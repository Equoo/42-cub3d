/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_operators_by.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:29:34 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 03:01:45 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <types/vector3.h>

t_vec3	vec3_mulf_by(t_vec3 *a, float b)
{
	a->x *= b;
	a->y *= b;
	a->z *= b;
	return (*a);
}

t_vec3	vec3_divf_by(t_vec3 *a, float b)
{
	a->x /= b;
	a->y /= b;
	a->z /= b;
	return (*a);
}

t_vec3	vec3_muli_by(t_vec3 *a, int b)
{
	a->x *= b;
	a->y *= b;
	a->z *= b;
	return (*a);
}

t_vec3	vec3_divi_by(t_vec3 *a, int b)
{
	a->x /= b;
	a->y /= b;
	a->z /= b;
	return (*a);
}
