/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:51:08 by dderny            #+#    #+#             */
/*   Updated: 2025/10/30 12:09:34 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <types/vector2.h>
#include <types/mat2.h>

float	mat2_determinant(t_mat2 m)
{
	return (m.col[0].x * m.col[1].y - m.col[0].y * m.col[1].x);
}

t_vec2	mat2_origin(t_mat2 m)
{
	return (m.origin);
}

float	mat2_rotation(t_mat2 m)
{
	return (atan2f(m.col[0].y, m.col[0].x));
}

t_vec2	mat2_gscale(t_mat2 m)
{
	t_vec2	scale;
	scale.x = vec2_len(m.col[0]);
	if (mat2_determinant(m) < 0)
		scale.y = -vec2_len(m.col[1]);
	else
		scale.y = vec2_len(m.col[1]);
	return (scale);
}

float	mat2_skew(t_mat2 m)
{
	float	dot;
	float	det_sign;
		
	if (mat2_determinant(m) < 0)
		det_sign = -1;
	else
		det_sign = 1;
	dot = vec2_dot(
		vec2_normed(m.col[0]),
		vec2_mulf(
			vec2_normed(m.col[1]),
			det_sign
		)
	);
	return (dot - (float)M_PI * 0.5f);
}
