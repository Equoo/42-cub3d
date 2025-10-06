/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_by.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:19:35 by dderny            #+#    #+#             */
/*   Updated: 2025/10/06 16:29:21 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <types/vector3.h>

t_vec3	vec3_add_by(t_vec3 *a, t_vec3 b)
{
	a->x += b.x;
	a->y += b.y;
	a->z += b.z;
	return (*a);
}

t_vec3	vec3_sub_by(t_vec3 *a, t_vec3 b)
{
	a->x -= b.x;
	a->y -= b.y;
	a->z -= b.z;
	return (*a);
}

t_vec3	vec3_mul_by(t_vec3 *a, t_vec3 b)
{
	a->x *= b.x;
	a->y *= b.y;
	a->z *= b.z;
	return (*a);
}

t_vec3	vec3_div_by(t_vec3 *a, t_vec3 b)
{
	a->x /= b.x;
	a->y /= b.y;
	a->z /= b.z;
	return (*a);
}
