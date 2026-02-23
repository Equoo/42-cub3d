/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:39:39 by dderny            #+#    #+#             */
/*   Updated: 2026/02/23 04:48:22 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/world.h"
#include "libft.h"
#include "types/image.h"
#include "types/vector2.h"

void	calc_wall_dimensions(t_wall_params *params, float dist,
		int buffer_height)
{
	params->w_height = PROJECTION_SCALE / dist;
	params->s_height = ft_clamp(params->w_height, 0, buffer_height);
	params->wall_start_y = (buffer_height - params->s_height) / 2;
}

void	calc_texture_params(t_wall_params *params, t_hit hit, t_image img)
{
	float	height_diff;

	height_diff = (float)(params->w_height - params->s_height);
	params->img_off = (height_diff * img.height) / (HALF_DIVISOR
			* params->w_height);
	params->img_x = (int)(fabsf(hit.pos.y) * img.width) % img.width;
	if (hit.dir == 0 || hit.dir == 1)
		params->img_x = (int)(hit.pos.x * img.width) % img.width;
	params->img_step = (float)img.height / (float)params->w_height;
}

float	calc_sky_darkness(int y, float inv_half_height)
{
	float	dist_from_center;
	float	darkness;

	dist_from_center = fabsf((float)y * inv_half_height - MAX_DARKNESS);
	darkness = ft_fclamp(dist_from_center, MIN_DARKNESS, MAX_DARKNESS);
	return (darkness);
}
