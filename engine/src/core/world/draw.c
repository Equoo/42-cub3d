/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:40:42 by dderny            #+#    #+#             */
/*   Updated: 2026/02/14 22:43:22 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/draw.h"
#include "core/world.h"
#include "libft.h"
#include "types/image.h"
#include "types/rgba.h"

static void	draw_sky_ground_pixel(t_draw_ctx *ctx, int i)
{
	float	darkness;
	float	inv_half_height;
	t_rgba	color;

	inv_half_height = MAX_DARKNESS / (float)ctx->half_height;
	darkness = calc_sky_darkness(i, inv_half_height);
	color = apply_darkness(ctx->map.floor, darkness);
	draw_pixel(ctx->buffer, ctx->x, i, color);
	color = apply_darkness(ctx->map.ceiling, darkness);
	draw_pixel(ctx->buffer, ctx->x, ctx->buffer->height - i, color);
}

static void	draw_ceiling_floor(t_draw_ctx *ctx, int limit)
{
	int	i;

	i = 0;
	while (i < limit)
	{
		draw_sky_ground_pixel(ctx, i);
		i++;
	}
}

static void	draw_wall_pixel(t_draw_ctx *ctx, t_wall_params *params,
		float darkness)
{
	int		i;
	t_rgba	color;
	int		tex_y;

	i = 0;
	while (i < params->s_height)
	{
		tex_y = (int)(i * params->img_step + params->img_off);
		if (params->img_x + tex_y * ctx->img.width > (uint)ctx->img.width
			* (uint)ctx->img.height)
		{
			__builtin_printf("TEST CRAsg: %d, %d, %d; res %d, size: %d\n",
				params->img_x, tex_y, ctx->img.width, params->img_x + tex_y
				* ctx->img.width, ctx->img.width * ctx->img.height);
		}
		color = ctx->img.data[params->img_x + tex_y * ctx->img.width];
		color = apply_darkness(color, darkness);
		draw_pixel(ctx->buffer, ctx->x, params->wall_start_y + i, color);
		i++;
	}
}

void	draw_wall(t_draw_ctx ctx, float dist, t_hit hit)
{
	t_wall_params	params;
	const float		darkness = ft_fclamp(MAX_DARKNESS / (dist * DIST_ATTENUATION
						+ DIST_OFFSET), MIN_DARKNESS, MAX_DARKNESS);
	int				limit;

	calc_wall_dimensions(&params, dist, ctx.buffer->height);
	if (params.s_height == 0)
		return ;
	limit = params.wall_start_y + 1;
	calc_texture_params(&params, hit, ctx.img);
	ctx.half_height = ctx.buffer->height / 2;
	draw_ceiling_floor(&ctx, limit);
	draw_wall_pixel(&ctx, &params, darkness);
}
