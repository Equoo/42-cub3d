/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:17:47 by dderny            #+#    #+#             */
/*   Updated: 2025/10/06 16:18:42 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <types/vector3.h>

t_vec3	vec3_add(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){
		a.x + b.x,
		a.y + b.y,
		a.z + b.z
	});
}

t_vec3	vec3_sub(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){
		a.x - b.x,
		a.y - b.y,
		a.z - b.z
	});
}

t_vec3	vec3_mul(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){
		a.x * b.x,
		a.y * b.y,
		a.z * b.z
	});
}

t_vec3	vec3_div(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){
		a.x / b.x,
		a.y / b.y,
		a.z / b.z
	});
}