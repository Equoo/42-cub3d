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

#include "vector2d.h"

t_vec2	vec2_add(t_vec2 self, t_vec2 other)
{
	self.x += other.x;
	self.y += other.y;
	return (self);
}

t_vec2i	vec2i_add(t_vec2i self, t_vec2i other)
{
	self.x += other.x;
	self.y += other.y;
	return (self);
}
