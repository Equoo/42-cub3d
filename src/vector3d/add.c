/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:49:37 by dderny            #+#    #+#             */
/*   Updated: 2025/04/22 14:40:00 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"

t_vec3	vec3_add(t_vec3 self, t_vec3 other)
{
	self.x += other.x;
	self.y += other.y;
	self.z += other.z;
	return (self);
}

t_vec3i	vec3i_add(t_vec3i self, t_vec3i other)
{
	self.x += other.x;
	self.y += other.y;
	self.z += other.z;
	return (self);
}
