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

#include "vector3d.h"

/*
** Scale a 2D float vector
** @param self: the vector
** @param factor: the factor
*/
t_vec3	vec3_scale_dived(t_vec3 self, float factor)
{
	t_vec3	new;

	new = self;
	new.x /= factor;
	new.y /= factor;
	new.z /= factor;
	return (new);
}

/*
** Scale a 2D int vector
** @param self: the vector
** @param factor: the factor
*/
t_vec3i	vec3i_scale_dived(t_vec3i self, int factor)
{
	t_vec3i	new;

	new = self;
	new.x /= factor;
	new.y /= factor;
	new.z /= factor;
	return (new);
}
