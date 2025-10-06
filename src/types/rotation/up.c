/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 06:34:42 by dderny            #+#    #+#             */
/*   Updated: 2025/05/25 05:34:04 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rotation.h"
#include <math.h>

t_vec3	rot_up(t_rot r)
{
	const float	rad = M_PI / 180.0f;
	t_vec3		rot;

	rot.x = cosf(r.z * rad) * sinf(r.x * rad);
	rot.y = sinf(r.z * rad) * sinf(r.x * rad);
	rot.z = cosf(r.x * rad);
	return (rot);
}
