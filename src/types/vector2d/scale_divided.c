/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_divided.c                                    :+:      :+:    :+:   */
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
t_vec2	vec2_scale_dived(t_vec2 self, float factor)
{
	t_vec2	new;

	new = self;
	new.x /= factor;
	new.y /= factor;
	return (new);
}

/*
** Scale a 2D int vector
** @param self: the vector
** @param factor: the factor
*/
t_vec2i	vec2i_scale_dived(t_vec2i self, int factor)
{
	t_vec2i	new;

	new = self;
	new.x /= factor;
	new.y /= factor;
	return (new);
}
