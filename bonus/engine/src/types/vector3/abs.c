/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:45:37 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 03:01:19 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <types/vector3.h>

t_vec3	vec3_abs(t_vec3 self)
{
	return ((t_vec3){fabsf(self.x), fabsf(self.y), fabsf(self.z)});
}
