/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:17:47 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 03:01:11 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <types/vector2.h>

t_vec2	vec2_add(t_vec2 a, t_vec2 b)
{
	return ((t_vec2){
		a.x + b.x,
		a.y + b.y,
	});
}

t_vec2	vec2_sub(t_vec2 a, t_vec2 b)
{
	return ((t_vec2){
		a.x - b.x,
		a.y - b.y,
	});
}

t_vec2	vec2_mul(t_vec2 a, t_vec2 b)
{
	return ((t_vec2){
		a.x * b.x,
		a.y * b.y,
	});
}

t_vec2	vec2_div(t_vec2 a, t_vec2 b)
{
	return ((t_vec2){
		a.x / b.x,
		a.y / b.y,
	});
}
