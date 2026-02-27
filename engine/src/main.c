/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:14:42 by dderny            #+#    #+#             */
/*   Updated: 2026/02/23 22:48:04 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/camera.h"
#include "core/engine.h"
#include "core/game.h"
#include "core/inputs.h"
#include "core/parse.h"
#include "core/window.h"
#include "core/world.h"
#include "ft_printf.h"
#include "libft.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// NORM V.4
// Using global variables that are **not marked const or static** is forbidden
// and is considered a norm error, unless the project explicitly allows them.
static const t_engine	g_engine = {.max_fps = 0, .physics_ticks = 20};

static const t_window	g_window = {.mousedown = &inputs_mousedown,
	.mouseup = &inputs_mouseup, .mousemove = &inputs_mousemove,
	.keydown = &inputs_keydown, .keyup = &inputs_keyup,
	.close = &engine_close, .update = &engine_update};

int	engine_initialize(t_engine *engine, int argc, char *argv[])
{
	t_map	map;

	if (argc != 2)
	{
		ft_dprintf(2, "./cub3d exemple.cub\n");
		return (1);
	}
	if (window_create(&engine->window, g_window, engine))
		return (1);
	map = (t_map){0};
	if (map_init(argv[1], &map))
		return (1);
	if (load_map(engine->window.mlx, &map))
		return (1);
	engine->map = &map;
	engine->camera = (t_camera){.speed = 2.0f, .rot_speed = 2.0f, .fov = 75,
		.pos = {map.spawn.x + SPAWN_OFFSET, map.spawn.y + SPAWN_OFFSET, 0},
		.rot = {0, 0, dir_to_int(map.dir)}};
	engine->mmap_zoom = ZOOM;
	if (game_initialize(engine))
		return (1);
	window_loop(&engine->window);
	return (0);
}

int	main(int argc, char *argv[])
{
	t__xgarbage	garbage;
	t_engine	engine;

	if (_garbage_init(&garbage))
		return (1);
	engine = g_engine;
	engine.garbage = &garbage;
	if (engine_initialize(&engine, argc, argv))
	{
		if (errno && errno != EWOULDBLOCK)
		{
			ft_dprintf(STDERR_FILENO, "Error\n%s\n", strerror(errno));
		}
		engine_close(&engine);
		return (1);
	}
	engine_close(&engine);
	return (0);
}
