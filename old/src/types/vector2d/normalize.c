/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:43:36 by dderny            #+#    #+#             */
/*   Updated: 2025/04/18 16:33:23 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2d.h"
#include <math.h>

/*
** Normalize a 2D float vector
** @param self: the vector
*/
t_vec2	vec2_normalize(t_vec2 self)
{
	float	len;

	len = sqrt(self.x * self.x + self.y * self.y);
	if (len > 0.0f)
	{
		self.x /= len;
		self.y /= len;
	}
	return (self);
}

/*
** Normalize a 2D int vector
** @param self: the vector
*/
t_vec2i	vec2i_normalize(t_vec2i self)
{
	int	len;

	len = sqrt(self.x * self.x + self.y * self.y);
	if (len > 0.0f)
	{
		self.x /= len;
		self.y /= len;
	}
	return (self);
}
