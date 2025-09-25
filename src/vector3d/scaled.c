/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaled.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:43:36 by dderny            #+#    #+#             */
/*   Updated: 2025/04/18 16:33:23 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"

/*
** Scale a 2D float vector
** @param self: the vector
** @param factor: the factor
*/
t_vec3	vec3_scaled(t_vec3 self, float factor)
{
	t_vec3	new;

	if (factor == 0)
		return (self);
	new.x = self.x * factor;
	new.y = self.y * factor;
	new.z = self.z * factor;
	return (new);
}

/*
** Scale a 2D int vector
** @param self: the vector
** @param factor: the factor
*/
t_vec3i	vec3i_scaled(t_vec3i self, int factor)
{
	t_vec3i	new;

	if (factor == 0)
		return (self);
	new.x = self.x * factor;
	new.y = self.y * factor;
	new.z = self.z * factor;
	return (new);
}
