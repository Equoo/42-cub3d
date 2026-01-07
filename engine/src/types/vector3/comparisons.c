/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparisons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:00:55 by dderny            #+#    #+#             */
/*   Updated: 2025/10/06 16:02:23 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math/extend.h>
#include <types/vector3.h>

t_bool	vec3_eq(t_vec3 a, t_vec3 b)
{
	return (fabsf(a.x - b.x) < EPSILON
		&& fabsf(a.y - b.y) < EPSILON
		&& fabsf(a.z - b.z) < EPSILON);
}

t_bool	vec3_less(t_vec3 a, t_vec3 b)
{
	return (a.x < b.x && a.y < b.y && a.z < b.z);
}

t_bool	vec3_lesseq(t_vec3 a, t_vec3 b)
{
	return (a.x <= b.x && a.y <= b.y && a.z <= b.z);
}

t_bool	vec3_great(t_vec3 a, t_vec3 b)
{
	return (a.x > b.x && a.y > b.y && a.z > b.z);
}

t_bool	vec3_greateq(t_vec3 a, t_vec3 b)
{
	return (a.x >= b.x && a.y >= b.y && a.z >= b.z);
}
