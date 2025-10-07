/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:37:41 by dderny            #+#    #+#             */
/*   Updated: 2025/04/22 14:39:40 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collisions.h"

float	getsign(float value)
{
	if (value < 0)
		return (-1);
	else
		return (1);
}

float	aabb_w(t_aabb hull)
{
	return (ft_fabs(hull.max.x - hull.min.x));
}

float	aabb_h(t_aabb hull)
{
	return (ft_fabs(hull.max.y - hull.min.y));
}

t_aabb	aabb_from_mm(t_vec3 min, t_vec3 max)
{
	t_aabb	hull;

	hull.min = min;
	hull.max = max;
	hull.center.x = (min.x + max.x) / 2;
	hull.center.y = (min.y + max.y) / 2;
	hull.center.z = (min.z + max.z) / 2;
	hull.half.x = (max.x - min.x) / 2;
	hull.half.y = (max.y - min.y) / 2;
	hull.half.z = (max.z - min.z) / 2;
	return (hull);
}

t_aabb	aabb_from_ch(t_vec3 center, t_vec3 half)
{
	t_aabb	hull;

	hull.center = center;
	hull.half = half;
	hull.min.x = center.x - half.x;
	hull.min.y = center.y - half.y;
	hull.min.y = center.z - half.z;
	hull.max.x = center.x + half.x;
	hull.max.y = center.y + half.y;
	hull.max.z = center.z + half.z;
	return (hull);
}
