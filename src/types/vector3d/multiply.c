/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:13:19 by dderny            #+#    #+#             */
/*   Updated: 2025/04/18 16:33:23 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"

t_vec3	vec3_multiply(t_vec3 self, t_vec3 other)
{
	t_vec3	result;

	result.x = self.x * other.x;
	result.y = self.y * other.y;
	result.z = self.z * other.z;
	return (result);
}

t_vec3i	vec3i_multiply(t_vec3i self, t_vec3i other)
{
	t_vec3i	result;

	result.x = self.x * other.x;
	result.y = self.y * other.y;
	result.z = self.z * other.z;
	return (result);
}
