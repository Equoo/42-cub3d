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

#include "vector3d.h"

/*
** Substract two 2D float vectors
** @param self: the first vector
** @param other: the second vector
*/
t_vec3	vec3_sub(t_vec3 self, t_vec3 other)
{
	t_vec3	result;

	result.x = self.x - other.x;
	result.y = self.y - other.y;
	result.z = self.z - other.z;
	return (result);
}

/*
** Substract two 2D int vectors
** @param self: the first vector
** @param other: the second vector
*/
t_vec3i	vec3i_sub(t_vec3i self, t_vec3i other)
{
	t_vec3i	result;

	result.x = self.x - other.x;
	result.y = self.y - other.y;
	result.z = self.z - other.z;
	return (result);
}
