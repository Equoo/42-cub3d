/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:35:06 by dderny            #+#    #+#             */
/*   Updated: 2025/10/06 16:39:18 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <types/vector3.h>

void	vec3_norm(t_vec3 *self)
{
	float	len;

	len = vec3_len(*self);
	if (len == 0)
	{
		*self = VEC3_ZERO;
		return (*self);
	}
	self->x /= len;
	self->y /= len;
	self->z /= len;
}

t_vec3	vec3_normed(t_vec3 self)
{
	float	len;

	len = vec3_len(self);
	if (len == 0)
		return (VEC3_ZERO);
	return ((t_vec3){self.x / len, self.y / len, self.z / len});
}