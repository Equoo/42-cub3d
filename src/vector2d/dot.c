/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:43:36 by dderny            #+#    #+#             */
/*   Updated: 2025/04/18 16:33:23 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2d.h"

/*
** Dot product of two 2D float vectors
** @param self: the first vector
** @param other: the second vector
** @return the dot product
*/
float	vec2_dot(t_vec2 *self, t_vec2 *other)
{
	return (self->x * other->x + self->y * other->y);
}

/*
** Dot product of two 2D int vectors
** @param self: the first vector
** @param other: the second vector
** @return the dot product
*/
int	vec2i_dot(t_vec2i *self, t_vec2i *other)
{
	return (self->x * other->x + self->y * other->y);
}
