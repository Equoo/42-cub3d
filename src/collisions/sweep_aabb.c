/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sweep_aabb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:09:07 by dderny            #+#    #+#             */
/*   Updated: 2025/04/22 14:25:16 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collisions.h"
#include "libft.h"

static int	is_intersecting(t_vec3 near_time, t_vec3 far_time)
{
	return (near_time.x > far_time.y || near_time.y > far_time.x
		|| ft_fmax(near_time.x, near_time.y) >= 1 || ft_fmin(far_time.x,
			far_time.y) <= 0);
}

t_hit	intersect_segment(t_vec3 pos, t_vec3 delta, t_vec3 padding,
		t_aabb hull)
{
	t_vec3	scale;
	t_vec3	sign;
	t_vec3	near_time;
	t_vec3	far_time;
	t_hit		hit;

	scale = vec3_divide((t_vec3){1, 1, 1}, delta);
	sign = (t_vec3){getsign(scale.x), getsign(scale.y), getsign(scale.z)};
	near_time = vec3_multiply(vec3_sub(vec3_sub(hull.center, pos),
				vec3_multiply(sign, vec3_add(hull.half, padding))),
			scale);
	far_time = vec3_multiply(vec3_add(vec3_sub(hull.center, pos),
				vec3_multiply(sign, vec3_add(hull.half, padding))),
			scale);
	if (is_intersecting(near_time, far_time))
		return ((t_hit){.time = 1});
	hit = (t_hit){.touch = 1, .time = ft_fclamp(ft_fmax(near_time.x,
				near_time.y), 0, 1)};
	if (near_time.x > near_time.y)
		hit.normal.x = -sign.x;
	else
		hit.normal.y = -sign.y;
	hit.delta = vec3_scaled(delta, -(1 - hit.time));
	hit.pos = vec3_add(pos, vec3_scaled(delta, hit.time));
	return (hit);
}

t_hit	intersect_aabb(t_aabb hulla, t_aabb hullb)
{
	t_vec3	d;
	t_vec3	p;
	t_hit		hit;

	hit = (t_hit){0, NULL, {0}, {0}, {0}, 1};
	d = vec3_sub(hullb.center, hulla.center);
	p = vec3_sub(vec3_add(hullb.half, hulla.half), vec3_abs(d));
	if (p.x <= 0 || p.y <= 0)
		return (hit);
	hit.touch = 1;
	if (p.x < p.y)
	{
		hit.normal.x = getsign(d.x);
		hit.delta.x = p.x * hit.normal.x;
		hit.pos.x = hullb.center.x + (hulla.half.x * hit.normal.x);
		hit.pos.y = hulla.center.y;
	}
	else
	{
		hit.normal.y = getsign(d.y);
		hit.delta.y = p.y * hit.normal.y;
		hit.pos.x = hulla.center.x;
		hit.pos.y = hullb.center.y + (hulla.half.y * hit.normal.y);
	}
	return (hit);
}

static t_sweep	sweep_aabb_static(t_aabb hulla, t_aabb hullb)
{
	t_sweep	sweep;

	sweep = (t_sweep){.time = 1};
	sweep.pos = hulla.center;
	sweep.hit = intersect_aabb(hulla, hullb);
	if (sweep.hit.touch)
		sweep.time = 0;
	if (sweep.hit.touch)
		sweep.hit.time = 0;
	return (sweep);
}

t_sweep	sweep_aabb(t_aabb hulla, t_aabb hullb, t_vec3 delta)
{
	t_sweep		sweep;
	t_vec3	dir;

	if (delta.x == 0 && delta.y == 0)
		return (sweep_aabb_static(hulla, hullb));
	sweep = (t_sweep){0};
	sweep.hit = intersect_segment(hulla.center, delta, hulla.half, hullb);
	if (sweep.hit.touch)
	{
		sweep.time = ft_fclamp(sweep.hit.time - EPSILON, 0, 1);
		sweep.pos = vec3_add(hulla.center, vec3_scaled(delta,
					sweep.time));
		dir = vec3_normalize(delta);
		sweep.hit.pos.x = ft_fclamp(sweep.hit.pos.x + dir.x * hulla.half.x,
				hullb.center.x - hulla.half.x, hullb.center.x + hulla.half.x);
		sweep.hit.pos.y = ft_fclamp(sweep.hit.pos.y + dir.y * hulla.half.y,
				hullb.center.y - hulla.half.y, hullb.center.y + hulla.half.y);
	}
	else
	{
		sweep.hit.pos = vec3_add(hulla.center, delta);
		sweep.time = 1;
	}
	return (sweep);
}
