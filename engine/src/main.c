/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:14:42 by dderny            #+#    #+#             */
/*   Updated: 2026/02/14 19:35:20 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/camera.h"
#include "core/engine.h"
#include "core/game.h"
#include "core/inputs.h"
#include "core/window.h"
#include "core/world.h"
#include "libft.h"
#include "types/image.h"

// Using global variables that are **not marked const or static** is forbidden
// and is considered a norm error, unless the project explicitly allows them.
const static t_engine	g_engine = {.max_fps = 0, .physics_ticks = 20};

const static t_window	g_window = {.mousedown = &inputs_mousedown,
		.mousemove = &inputs_mousemove, .mouseup = &inputs_mouseup,
		.keydown = &inputs_keydown, .keyup = &inputs_keyup,
		.close = &engine_close, .update = &engine_update};

int	engine_initialize(t_engine *engine, int argc, char *argv[])
{
	t_map	map;

	if (window_create(&engine->window, g_window, engine))
		return (1);
	(void)argc;
	(void)argv;
	engine->camera = (t_camera){.fov = 75};
	map = (t_map){0};
	engine->map = &map;
	if (image_from_xpm(engine->window.mlx, "game/textures/background0.xpm",
			&map.textures[0]))
		return (1);
	if (image_from_xpm(engine->window.mlx, "game/textures/test.xpm",
			&map.textures[1]))
		return (1);
	if (image_from_xpm(engine->window.mlx, "game/textures/background0.xpm",
			&map.textures[2]))
		return (1);
	if (image_from_xpm(engine->window.mlx, "game/textures/background0.xpm",
			&map.textures[3]))
		return (1);
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
		engine_close(&engine);
		return (1);
	}
	engine_close(&engine);
	return (0);
}
