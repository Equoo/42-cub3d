/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:02:12 by dderny            #+#    #+#             */
/*   Updated: 2026/02/14 20:04:22 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/camera.h"
#include "core/draw.h"
#include "core/world.h"
#include "libft.h"
#include "math/algorithm.h"
#include "math/extend.h"
#include "types/image.h"
#include "types/rgba.h"
#include "types/vector2.h"

#define PROJECTION_SCALE 1200.0f
#define DIST_ATTENUATION 0.8f
#define DIST_OFFSET 0.3f
#define MIN_DARKNESS 0.05f
#define MAX_DARKNESS 1.0f
#define HALF_DIVISOR 2.0f

typedef struct s_wall_params
{
	int			w_height;
	int			s_height;
	float		img_off;
	float		img_step;
	uint		img_x;
	int			wall_start_y;
}				t_wall_params;

typedef struct s_draw_ctx
{
	t_image		*buffer;
	t_image		img;
	t_map		map;
	int			x;
	int			half_height;
}				t_draw_ctx;

static t_rgba	apply_darkness(t_rgba color, float darkness)
{
	t_rgba	result;

	result = color;
	result.r *= darkness;
	result.g *= darkness;
	result.b *= darkness;
	return (result);
}

static void	calc_wall_dimensions(t_wall_params *params, float dist,
		int buffer_height)
{
	params->w_height = PROJECTION_SCALE / dist;
	params->s_height = ft_clamp(params->w_height, 0, buffer_height);
	params->wall_start_y = (buffer_height - params->s_height) / 2;
}

static void	calc_texture_params(t_wall_params *params, t_hit hit, t_image img)
{
	float	height_diff;

	height_diff = (float)(params->w_height - params->s_height);
	params->img_off = (height_diff * img.height) / (HALF_DIVISOR
			* params->w_height);
	params->img_x = (int)(hit.pos.y * img.width) % img.width;
	if (hit.dir == 0 || hit.dir == 1)
		params->img_x = (int)(hit.pos.x * img.width) % img.width;
	params->img_step = (float)img.height / (float)params->w_height;
}

static float	calc_sky_darkness(int y, float inv_half_height)
{
	float	dist_from_center;
	float	darkness;

	dist_from_center = fabsf((float)y * inv_half_height - MAX_DARKNESS);
	darkness = ft_fclamp(dist_from_center, MIN_DARKNESS, MAX_DARKNESS);
	return (darkness);
}

static void	draw_sky_ground_pixel(t_draw_ctx *ctx, int i)
{
	float	darkness2;
	float	inv_half_height;
	t_rgba	color;

	inv_half_height = MAX_DARKNESS / (float)ctx->half_height;
	darkness2 = calc_sky_darkness(i, inv_half_height);
	color = apply_darkness(ctx->map.floor, darkness2);
	draw_pixel(ctx->buffer, ctx->x, i, color);
	color = apply_darkness(ctx->map.ceiling, darkness2);
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
		color = ctx->img.data[params->img_x + tex_y * ctx->img.width];
		color = apply_darkness(color, darkness);
		draw_pixel(ctx->buffer, ctx->x, params->wall_start_y + i, color);
		i++;
	}
}

static void	draw_wall(t_image *buffer, int x, float dist, t_hit hit,
		t_image img, t_map map)
{
	t_wall_params	params;
	t_draw_ctx		ctx;
	const float		darkness = ft_fclamp(MAX_DARKNESS / (dist * DIST_ATTENUATION
						+ DIST_OFFSET), MIN_DARKNESS, MAX_DARKNESS);
	int				limit;

	calc_wall_dimensions(&params, dist, buffer->height);
	if (params.s_height == 0)
		return ;
	limit = params.wall_start_y + 1;
	calc_texture_params(&params, hit, img);
	ctx.buffer = buffer;
	ctx.img = img;
	ctx.map = map;
	ctx.x = x;
	ctx.half_height = buffer->height / 2;
	draw_ceiling_floor(&ctx, limit);
	draw_wall_pixel(&ctx, &params, darkness);
}

int	draw_walls(t_image *buffer, t_map map, t_camera cam)
{
	const int	rays = buffer->width;
	const float	angle_steps = (float)cam.fov / (float)rays;
	const int	rays_filling = 1;
	int			i;
	float		ray_angle;
	t_hit		hit;
	t_vec2		off;
	t_vec2		origin;
	t_vec2		dir;
	t_vec2		a;
	t_vec2		b;

	// const int   slice_width = render->width / rays;
	i = 0;
	while (i < rays)
	{
		if (i % rays_filling && ++i)
			continue ;
		ray_angle = cam.rot.z - (float)cam.fov / 2 + i * angle_steps;
		off = (t_vec2){100, 500};
		origin = vec2_add(vec2_mulf((t_vec2){cam.pos.x, cam.pos.y}, 10), off);
		dir = (t_vec2){cos_lut(ray_angle), sin_lut(ray_angle)};
		hit = dda_trace((t_vec2){cam.pos.x, cam.pos.y}, dir, map);
		if (hit.hit)
		{
			draw_wall(buffer, i, hit.dist * cos_lut(-(float)cam.fov / 2 + i
					* angle_steps), hit, map.textures[hit.dir], map);
			draw_line(buffer, origin,
				vec2_add(vec2_mulf((t_vec2){cos_lut(ray_angle),
						sin_lut(ray_angle)}, 100), origin), (t_rgba)0xff00ff00);
			a = (t_vec2){100 + hit.pos.x * 10, 500 + hit.pos.y * 10};
			b = vec2_add(a, (t_vec2){10, 10});
			draw_square(buffer, a, b, (t_rgba)0xff0000ff);
		}
		else
			draw_line(buffer, origin,
				vec2_add(vec2_muli((t_vec2){cos_lut(ray_angle),
						sin_lut(ray_angle)}, 100), origin), (t_rgba)0xffff0000);
		i++;
	}
	return (0);
}
