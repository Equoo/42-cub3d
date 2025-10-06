/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:17:47 by dderny            #+#    #+#             */
/*   Updated: 2025/10/06 16:19:23 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <types/vector3.h>

t_vec3	vec3_mulf(t_vec3 a, float b)
{
	return ((t_vec3){
		a.x * b,
		a.y * b,
		a.z * b
	});
}

t_vec3	vec3_divf(t_vec3 a, float b)
{
	return ((t_vec3){
		a.x / b,
		a.y / b,
		a.z / b
	});
}

t_vec3	vec3_muli(t_vec3 a, int b)
{
	return ((t_vec3){
		a.x * b,
		a.y * b,
		a.z * b
	});
}

t_vec3	vec3_divi(t_vec3 a, int b)
{
	return ((t_vec3){
		a.x / b,
		a.y / b,
		a.z / b
	});
}