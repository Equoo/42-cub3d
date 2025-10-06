/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_by.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:19:35 by dderny            #+#    #+#             */
/*   Updated: 2025/10/06 16:51:17 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <types/vector2.h>

t_vec2	vec2_add_by(t_vec2 *a, t_vec2 b)
{
	a->x += b.x;
	a->y += b.y;
	return (*a);
}

t_vec2	vec2_sub_by(t_vec2 *a, t_vec2 b)
{
	a->x -= b.x;
	a->y -= b.y;
	return (*a);
}

t_vec2	vec2_mul_by(t_vec2 *a, t_vec2 b)
{
	a->x *= b.x;
	a->y *= b.y;
	return (*a);
}

t_vec2	vec2_div_by(t_vec2 *a, t_vec2 b)
{
	a->x /= b.x;
	a->y /= b.y;
	return (*a);
}
