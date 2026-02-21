/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:39:23 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 03:01:21 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <types/vector3.h>

void	vec3_clamp(t_vec3 *self, t_vec3 min, t_vec3 max)
{
	self->x = fmaxf(min.x, fminf(self->x, max.x));
	self->y = fmaxf(min.y, fminf(self->y, max.y));
	self->z = fmaxf(min.z, fminf(self->z, max.z));
}

t_vec3	vec3_clamped(t_vec3 self, t_vec3 min, t_vec3 max)
{
	self.x = fmaxf(min.x, fminf(self.x, max.x));
	self.y = fmaxf(min.y, fminf(self.y, max.y));
	self.z = fmaxf(min.z, fminf(self.z, max.z));
	return (self);
}
