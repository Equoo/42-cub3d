/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:43:36 by dderny            #+#    #+#             */
/*   Updated: 2025/04/18 16:33:23 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2d.h"

/*
** Substract two 2D float vectors
** @param self: the first vector
** @param other: the second vector
*/
t_vec2	vec2_sub(t_vec2 self, t_vec2 other)
{
	t_vec2	result;

	result.x = self.x - other.x;
	result.y = self.y - other.y;
	return (result);
}

/*
** Substract two 2D int vectors
** @param self: the first vector
** @param other: the second vector
*/
t_vec2i	vec2i_sub(t_vec2i self, t_vec2i other)
{
	t_vec2i	result;

	result.x = self.x - other.x;
	result.y = self.y - other.y;
	return (result);
}
