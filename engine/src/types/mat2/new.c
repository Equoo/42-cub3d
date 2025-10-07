/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:50:00 by dderny            #+#    #+#             */
/*   Updated: 2025/10/07 15:47:43 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <types/mat2.h>

t_mat2	mat2(t_vec2 x, t_vec2 y, t_vec2 origin)
{
	return ((t_mat2){.x = x, .y = y, .origin = origin});
}

t_mat2	mat2_from_rp(float rot, t_vec2 pos)
{
	t_mat2	result;
	float	cos_rot;
	float	sin_rot;

	cos_rot = cosf(rot);
	sin_rot = sinf(rot);
	result.origin = pos;
	result.x = (t_vec2){cos_rot, sin_rot};
	result.y = (t_vec2){-sin_rot, cos_rot};
	return (result);
}

t_mat2	mat2_from_rssp(float rot, t_vec2 scale, t_vec2 skew, t_vec2 pos)
{
	t_mat2	result;

	result.col[0][0] = cosf(rot) * scale.x;
	result.col[1][1] = sinf(rot + skew) * scale.y;
	result.col[1][0] = -sinf(rot + skew) * scale.y;
	result.col[0][1] = cosf(rot) * scale.x;
	result.col[2] = pos;
	return (result);
}
