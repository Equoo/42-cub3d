/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 04:42:48 by dderny            #+#    #+#             */
/*   Updated: 2025/05/25 22:21:22 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rotation.h"
#include <math.h>

t_vec3	rot_right(t_rot r)
{
	const float	rad = M_PI / 180.0f;
	t_vec3		rot;

	rot.x = sinf(r.z * rad * cosf(r.x * rad));
	rot.y = cosf(r.z * rad * cosf(r.x * rad));
	rot.z = sinf(r.x * rad);
	return (rot);
}
