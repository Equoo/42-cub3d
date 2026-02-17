/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 20:07:23 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 03:24:52 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math/extend.h"
#include "types/vector3.h"

t_vec3	rot_forward(t_rot r)
{
	t_vec3	rot;

	rot.x = cos_lut(r.z) * cos_lut(r.y);
	rot.y = sin_lut(r.z) * cos_lut(r.y);
	rot.z = sin_lut(r.y);
	return (rot);
}

t_vec3	rot_up(t_rot r)
{
	t_vec3	rot;

	rot.x = cos_lut(r.z) * sin_lut(r.x);
	rot.y = sin_lut(r.z) * sin_lut(r.x);
	rot.z = cos_lut(r.x);
	return (rot);
}

t_vec3	rot_right(t_rot r)
{
	return (vec3_cross(rot_forward(r), (t_vec3){0, 0, 1}));
}
