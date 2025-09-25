/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 04:36:34 by dderny            #+#    #+#             */
/*   Updated: 2025/04/25 20:18:22 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/element.h"
#include "classes/entity.h"
#include "collisions.h"
#include "libft.h"
#include "scene.h"
#include "cub3d.h"
#include "vector2d.h"

static void	on_collides(t_entity *ent, t_sweep res)
{
	t_entity	*other;

	if (ent->on_collide)
		ent->on_collide(ent, res.hit.element, res);
	if (res.hit.element && res.hit.element->class & CGROUP_ENTITY)
	{
		other = cast_entity(res.hit.element->parent);
		if (other && other->on_collide)
			other->on_collide(other, ent->base, res);
	}
}

static t_vec2	collide(t_entity *ent, t_vec2 vel)
{
	t_trace		trace;
	t_sweep		res;
	int			i;
	t_vec2	remaining;

	i = -1;
	while (++i < MAX_SWEEP_ITERATIONS)
	{
		trace = (t_trace){ent->base->pos, ent->base->pos, ent->hull, CGROUP_ALL,
			ent->base->id};
		trace.to = vec2_add(trace.to, vel);
		res = world_sweep_aabb(ent->base->scene, trace);
		if (!res.hit.touch || res.time >= 1.0f)
			break ;
		on_collides(ent, res);
		ent->base->pos = vec2_lerp(ent->base->pos, trace.to, res.time);
		remaining = vec2_sub(vel, vec2_multiply(vel,
					vec2_abs(res.hit.normal)));
		ent->velocity = vec2_scaled(remaining, 1.0f - res.time);
		ent->base->pos = vec2_add(ent->base->pos, vec2_scaled(
					res.hit.normal, EPSILON));
		vel = remaining;
	}
	return (vec2_add(ent->base->pos, vel));
}

static void	isgrounded(t_entity *ent)
{
	t_vec2	from;
	t_sweep		res;

	from = (t_vec2){ent->base->pos.x + ent->hull.min.x, ent->base->pos.y
		+ 1};
	if (ent->gravity_dir.y > 0)
		from.y -= aabb_h(ent->hull) + 2;
	res = world_sweep_aabb(ent->base->scene, (t_trace){from, from, {{0},
		{aabb_w(ent->hull), 1}, {0}, {0}}, CGROUP_ALL, ent->base->id});
	ent->b_isground = res.hit.touch;
}

void	entity_physic(t_element *self)
{
	t_entity	*ent;
	t_gameenv	*env;
	double		frametime;

	env = self->scene->env;
	frametime = env->frametime;
	if (frametime > 0.1)
		frametime = 0.1;
	ent = cast_entity(self->parent);
	if (!ent->nogravity)
		ent->velocity = vec2_sub(ent->velocity,
				vec2_scaled(ent->gravity_dir, GRAVITY * frametime));
	ent->velocity.x = ft_fclamp(ent->velocity.x, -16, 16);
	ent->velocity.y = ft_fclamp(ent->velocity.y, -16, 16);
	ent->base->pos = collide(ent, ent->velocity);
	isgrounded(ent);
	if (ent->b_isground)
		ent->velocity = vec2_scaled(ent->velocity, 1 - (frametime * 5));
	else
		ent->velocity = vec2_scaled(ent->velocity, 1 - (frametime * 3));
}
