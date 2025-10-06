/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 04:43:05 by dderny            #+#    #+#             */
/*   Updated: 2025/05/25 22:16:10 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rotation.h"
#include <math.h>

t_vec3	rot_forward(t_rot r)
{
	const float	rad = M_PI / 180.0f;
	t_vec3		rot;

	rot.x = cosf(r.z * rad) * cosf(r.y * rad);
	rot.y = sinf(r.z * rad) * cosf(r.y * rad);
	rot.z = sinf(r.y * rad);
	return (rot);
}
