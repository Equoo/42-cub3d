/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:43:39 by dderny            #+#    #+#             */
/*   Updated: 2026/02/28 18:56:15 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/camera.h"
#include "core/game.h"
#include "core/world.h"
#include "ft_vector.h"
#include "math/extend.h"
#include "types/vector2.h"
#include <stdint.h>

static float	dist(float a, float b)
{
	float	diff;

	diff = (a - b) * -1;
	if (diff < -180)
		diff = 360 - a + b;
	return (diff);
}

int	update_sprites(t_sprite *sprites, t_camera cam)
{
	const t_vec2	c_pos = {cam.pos.x, cam.pos.y};
	float			sangle;
	int				center;
	int				width;
	size_t			i;

	i = 0;
	while (i < vec_size(sprites))
	{
		sprites[i].dist = vec2_dist(sprites[i].pos, c_pos);
		sangle = sanitize_angle(vec2_angle(c_pos, sprites[i].pos));
		center = (float)g_win_width / 2 + dist(cam.rot.z, sangle)
			/ ((float)cam.fov / (g_win_width * RAYS_DENSITY));
		sprites[i].darkness = ft_fclamp(MAX_DARK / (sprites[i].dist * DIST_ATTEN
					+ DIST_OFFSET), MIN_DARK, MAX_DARK);
		sprites[i].height = PROJECTION_SCALE / (sprites[i].dist * SPRITES_SIZE);
		sprites[i].wmul = (float)sprites[i].tex.height / sprites[i].height;
		width = (float)sprites[i].height / (float)sprites[i].tex.height
			* (sprites[i].tex.width / 8);
		sprites[i].sx = center - width / 2;
		sprites[i].width = width;
		sprites[i].draw = 1;
		i++;
	}
	return (0);
}

static int	calc_params(t_wall_params *params, t_sprite *sprite, int x,
		t_image img)
{
	float	height_diff;

	params->img_x = (x - sprite->sx);
	if (params->img_x > (uint)sprite->width || params->img_x < 0)
		return (1);
	params->img_x *= sprite->wmul;
	height_diff = (float)(params->w_height - params->s_height);
	params->img_off = (height_diff * img.height) / (HALF_DIVISOR
			* params->w_height);
	params->img_step = (float)img.height / (float)params->w_height;
	params->img_x += (int64_t)(*sprite->time * 10) % 6 * (sprite->tex.width
			/ 8);
	return (0);
}

int	draw_sprites(t_draw_ctx *ctx, float dist)
{
	t_wall_params	params;
	t_sprite		sprite;
	size_t			i;

	i = 0;
	while (i < vec_size(ctx->map.sprites))
	{
		sprite = ctx->map.sprites[i];
		if (!sprite.draw && ++i)
			continue ;
		if (sprite.dist > dist && ++i)
			continue ;
		calc_wall_dimensions(&params, sprite.dist * SPRITES_SIZE,
			ctx->buffer->height);
		if (params.s_height == 0 && ++i)
			continue ;
		ctx->img = sprite.tex;
		if (calc_params(&params, &sprite, ctx->x, ctx->img) && ++i)
			continue ;
		draw_wall_pixel(ctx, &params, sprite.darkness);
		i++;
	}
	return (0);
}

int	sprites_init(void *e)
{
	t_engine	*engine;
	t_sprite	sprite;
	t_map		*map;
	int			i;

	engine = e;
	if (image_from_xpm(engine->window.mlx, "game/textures/smoke.xpm",
			&engine->sprite))
		return (1);
	map = &engine->map;
	map->sprites = vec_new(engine->garbage, sizeof(t_sprite), 4);
	if (!map->sprites)
		return (1);
	i = 0;
	while (i < map->width * map->height)
	{
		if (map->cells[i] != 'B' && ++i)
			continue ;
		sprite = (t_sprite){.tex = engine->sprite, vec2_from_index(i,
				map->width), .time = &engine->time};
		if (vec_append((t_vec *)&map->sprites, &sprite))
			return (1);
		i++;
	}
	return (0);
}
