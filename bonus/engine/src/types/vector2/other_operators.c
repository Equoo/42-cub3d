/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:17:47 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 03:01:14 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <types/vector2.h>

t_vec2	vec2_mulf(t_vec2 a, float b)
{
	return ((t_vec2){
		a.x * b,
		a.y * b,
	});
}

t_vec2	vec2_divf(t_vec2 a, float b)
{
	return ((t_vec2){
		a.x / b,
		a.y / b,
	});
}

t_vec2	vec2_muli(t_vec2 a, int b)
{
	return ((t_vec2){
		a.x * b,
		a.y * b,
	});
}

t_vec2	vec2_divi(t_vec2 a, int b)
{
	return ((t_vec2){
		a.x / b,
		a.y / b,
	});
}
