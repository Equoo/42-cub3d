/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:35:06 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 03:01:09 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <types/vector2.h>

void	vec2_norm(t_vec2 *self)
{
	float	len;

	len = vec2_len(*self);
	if (len == 0)
	{
		*self = (t_vec2){0, 0};
		return ;
	}
	self->x /= len;
	self->y /= len;
}

t_vec2	vec2_normed(t_vec2 self)
{
	float	len;

	len = vec2_len(self);
	if (len == 0)
		return ((t_vec2){0, 0});
	return ((t_vec2){self.x / len, self.y / len});
}
