/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:30:50 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 03:01:33 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <types/vector3.h>

float	vec3_sqrlen(t_vec3 self)
{
	return (self.x * self.x + self.y * self.y + self.z * self.z);
}

float	vec3_len(t_vec3 self)
{
	return (sqrtf(vec3_sqrlen(self)));
}
