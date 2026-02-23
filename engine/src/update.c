/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:10:24 by dderny            #+#    #+#             */
/*   Updated: 2026/02/23 03:39:00 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/camera.h"
#include "core/draw.h"
#include "core/engine.h"
#include "core/game.h"
#include "core/inputs.h"
#include "core/physics.h"
#include "core/world.h"
#include "types/rgba.h"
#include "types/vector2.h"
#include <ft_printf.h>
#include <ft_time.h>
#include <math.h>
#include <stdint.h>
#include <sys/types.h>

// void	printticks(t_gameenv *env)
// {
// 	static double	last = 0;
// 	static double	middle = 0;
// 	static int		fps = TICK;
// 	static int		count = 0;
//
// 	middle = middle + env->frametime;
// 	count++;
// 	if (env->time - last >= 1)
// 	{
// 		middle /= count;
// 		count = 0;
// 		fps = 1 / middle;
// 		env->smooth_fps = fps;
// 		middle = env->frametime;
// 		last = env->time;
// 	}
// }

int	engine_tick(t_engine *engine)
{
	game_tick(engine);
	return (0);
}

static int	time_update(t_engine *engine)
{
	static double	elapsed = 0;

	engine->time = curtime_us();
	if (!engine->start_time)
		engine->start_time = engine->time;
	if (!engine->last_frame)
		engine->last_frame = engine->time;
	if (!engine->lastrealtime)
		engine->lastrealtime = engine->time;
	elapsed += engine->time - engine->lastrealtime;
	if (elapsed >= 1.f / ((double)engine->physics_ticks))
	{
		elapsed -= 1.f / ((double)engine->physics_ticks);
		engine->frametime = (engine->time - engine->last_frame);
		if (engine_tick(engine))
			return (1);
		engine->last_frame = engine->time;
	}
	engine->frametime = (engine->time - engine->lastrealtime);
	return (0);
}

#define MMAP_OFFSET 100
#define SIZE 200
#define SIZEHALF 100
#define ZOOM 15.f
#define MMAP_PLY_SIZE (CAMERA_RADIUS * ZOOM)

static void	draw_minimap(t_image *buffer, t_map *map, t_camera camera)
{
	int		i;
	t_vec2	pos;
	t_vec2	map_pos;

	pos = (t_vec2){g_win_width - MMAP_OFFSET - SIZE, MMAP_OFFSET};
	i = 0;
	while (i < SIZE * SIZE)
	{
		if (vec2_dist((t_vec2){pos.x + i % SIZE, pos.y + i / SIZE},
			(t_vec2){pos.x + SIZEHALF, pos.y + SIZEHALF}) > SIZEHALF && ++i)
			continue ;
		map_pos = (t_vec2){(i % SIZE) / ZOOM + camera.pos.x - SIZEHALF / ZOOM,
			i / SIZE / ZOOM + camera.pos.y - SIZEHALF / ZOOM};
		if (!is_inmap(map_pos, map)
			|| map->cells[vec2_index(map_pos, map->width)] == '1')
			draw_pixel(buffer, pos.x + i % SIZE, pos.y + i / SIZE, (t_rgba)0xffffffff);
		i++;
	}
	draw_square(buffer, (t_vec2){pos.x + SIZEHALF - MMAP_PLY_SIZE,
		pos.y + SIZEHALF - MMAP_PLY_SIZE},
		(t_vec2){pos.x + SIZEHALF + MMAP_PLY_SIZE,
		pos.y + SIZEHALF + MMAP_PLY_SIZE}, (t_rgba)0xffff0000);
}

static int	render_update(t_engine *engine)
{
	window_drawbuffer(&engine->window);
	draw_walls(&engine->window.buffer, *engine->map, engine->camera);
	draw_minimap(&engine->window.buffer, engine->map, engine->camera);
	return (0);
}

int	engine_update(t_engine *engine)
{
	if (time_update(engine) || inputs_update(engine)
		|| apply_inputs(engine) || render_update(engine)
		|| game_update(engine))
	{
		engine_close(engine);
	}
	if (engine->frametime > 0)
		ft_printf("FPS: %f\n", 1 / engine->frametime);
	engine->lastrealtime = engine->time;
	if (UNITTEST && engine->time - engine->start_time > 0.05)
		engine_close(engine);
	return (0);
}
