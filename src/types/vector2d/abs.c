/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:26:27 by dderny            #+#    #+#             */
/*   Updated: 2025/04/18 16:33:23 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2d.h"
#include <libft.h>

/*
** Return the absolute value of a 2D float vector
** @param self: the vector
*/
t_vec2	vec2_abs(t_vec2 self)
{
	self.x = ft_fabs(self.x);
	self.y = ft_fabs(self.y);
	return (self);
}

/*
** Return the absolute value of a 2D int vector
** @param self: the vector
*/
t_vec2i	vec2i_abs(t_vec2i self)
{
	self.x = ft_abs(self.x);
	self.y = ft_abs(self.y);
	return (self);
}
