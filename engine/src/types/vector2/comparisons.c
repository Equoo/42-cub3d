/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparisons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:00:55 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 03:00:40 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math/extend.h>
#include <types/vector2.h>

t_bool	vec2_eq(t_vec2 a, t_vec2 b)
{
	return (fabsf(a.x - b.x) < EPSILON && fabsf(a.y - b.y) < EPSILON);
}

t_bool	vec2_less(t_vec2 a, t_vec2 b)
{
	return (a.x < b.x && a.y < b.y);
}

t_bool	vec2_lesseq(t_vec2 a, t_vec2 b)
{
	return (a.x <= b.x && a.y <= b.y);
}

t_bool	vec2_great(t_vec2 a, t_vec2 b)
{
	return (a.x > b.x && a.y > b.y);
}

t_bool	vec2_greateq(t_vec2 a, t_vec2 b)
{
	return (a.x >= b.x && a.y >= b.y);
}
