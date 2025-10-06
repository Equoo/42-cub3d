/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:32:24 by dderny            #+#    #+#             */
/*   Updated: 2025/10/06 16:34:38 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <types/vector3.h>

float	vec3_sqrdist(t_vec3 a, t_vec3 b)
{
	return ((a.x - b.x) * (a.x - b.x)
		+ (a.y - b.y) * (a.y - b.y)
		+ (a.z - b.z) * (a.z - b.z));
}

float	vec3_dist(t_vec3 a, t_vec3 b)
{
	return (sqrtf(vec3_sqrdist(a, b)));
}