/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:39:23 by dderny            #+#    #+#             */
/*   Updated: 2025/10/06 16:47:27 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <types/vector2.h>

void	vec2_clamp(t_vec2 *self, t_vec2 min, t_vec2 max)
{
	self->x = fmaxf(min.x, fminf(self->x, max.x));
	self->y = fmaxf(min.y, fminf(self->y, max.y));
}

t_vec2	vec2_clamped(t_vec2 self, t_vec2 min, t_vec2 max)
{
	self.x = fmaxf(min.x, fminf(self.x, max.x));
	self.y = fmaxf(min.y, fminf(self.y, max.y));
	return (self);
}