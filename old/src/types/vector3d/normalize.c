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

#include "vector3d.h"
#include <math.h>

/*
** Normalize a 2D float vector
** @param self: the vector
*/
t_vec3	vec3_normalize(t_vec3 self)
{
	float	len;

	len = sqrtf(self.x * self.x + self.y * self.y + self.z * self.z);
	if (len > 0.0f)
	{
		self.x /= len;
		self.y /= len;
		self.z /= len;
	}
	return (self);
}

/*
** Normalize a 2D int vector
** @param self: the vector
*/
t_vec3i	vec3i_normalize(t_vec3i self)
{
	int	len;

	len = sqrtf(self.x * self.x + self.y * self.y + self.z * self.z);
	if (len > 0.0f)
	{
		self.x /= len;
		self.y /= len;
		self.z /= len;
	}
	return (self);
}
