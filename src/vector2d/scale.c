/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:43:36 by dderny            #+#    #+#             */
/*   Updated: 2025/04/18 16:33:23 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2d.h"

/*
** Scale a 2D float vector
** @param self: the vector
** @param factor: the factor
*/
void	vec2_scale(t_vec2 *self, float factor)
{
	self->x *= factor;
	self->y *= factor;
}

/*
** Scale a 2D int vector
** @param self: the vector
** @param factor: the factor
*/
void	vec2i_scale(t_vec2i *self, int factor)
{
	self->x *= factor;
	self->y *= factor;
}
