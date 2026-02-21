/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:30:50 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 03:01:04 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <types/vector2.h>

float	vec2_sqrlen(t_vec2 self)
{
	return (self.x * self.x + self.y * self.y);
}

float	vec2_len(t_vec2 self)
{
	return (sqrtf(vec2_sqrlen(self)));
}
