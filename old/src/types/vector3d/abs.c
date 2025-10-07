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

#include "vector3d.h"
#include <libft.h>

/*
** Return the absolute value of a 2D float vector
** @param self: the vector
*/
t_vec3	vec3_abs(t_vec3 self)
{
	self.x = ft_fabs(self.x);
	self.y = ft_fabs(self.y);
	self.z = ft_fabs(self.z);
	return (self);
}

/*
** Return the absolute value of a 2D int vector
** @param self: the vector
*/
t_vec3i	vec3i_abs(t_vec3i self)
{
	self.x = ft_abs(self.x);
	self.y = ft_abs(self.y);
	self.z = ft_abs(self.z);
	return (self);
}
