/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_operators_by.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:29:34 by dderny            #+#    #+#             */
/*   Updated: 2025/10/06 16:51:28 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <types/vector2.h>

t_vec2	vec2_mulf_by(t_vec2 *a, float b)
{
	a->x *= b;
	a->y *= b;
	return (*a);
}

t_vec2	vec2_divf_by(t_vec2 *a, float b)
{
	a->x /= b;
	a->y /= b;
	return (*a);
}

t_vec2	vec2_muli_by(t_vec2 *a, int b)
{
	a->x *= b;
	a->y *= b;
	return (*a);
}

t_vec2	vec2_divi_by(t_vec2 *a, int b)
{
	a->x /= b;
	a->y /= b;
	return (*a);
}