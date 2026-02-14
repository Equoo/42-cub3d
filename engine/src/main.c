/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:33:22 by dderny            #+#    #+#             */
/*   Updated: 2026/02/14 06:02:20 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/window.h"
#include "core/world.h"
#include "libft.h"
#include "core/engine.h"
#include "core/camera.h"
#include "core/inputs.h"
#include "core/game.h"
#include "types/image.h"

// Using global variables that are **not marked const or static** is forbidden
// and is considered a norm error, unless the project explicitly allows them.
static const t_engine	g_engine = {
	.max_fps = 0,
	.physics_ticks = 20
};

static const t_window	g_window = {
	.mousedown = &inputs_mousedown,
	.mousemove = &inputs_mousemove,
	.mouseup = &inputs_mouseup,
	.keydown = &inputs_keydown,
	.keyup = &inputs_keyup,

	.close = &engine_close,
	.update = &engine_update
};

int	engine_initialize(t_engine *engine, int argc, char *argv[])
{
	if (window_create(&engine->window, g_window, engine))
		return (1);
	(void)argc;
	(void)argv;

	engine->camera = (t_camera){.fov = 80};

	t_map     map = (t_map){
		.width = 10,
		.height = 10,
		.cells = "1111111111110000110111000011011100001101111000000111100000011110000001111000000111100000011111111111",
		.textures = {
			{.uvb = {1,1}},
			{0},
			{0},
			{0}
		}
	};
	engine->map = &map;

	if (image_from_xpm(engine->window.mlx, "game/textures/background0.xpm", &map.textures[0].tex))
		return (1);
	if (image_from_xpm(engine->window.mlx, "game/textures/test.xpm", &map.textures[1].tex))
		return (1);
	if (image_from_xpm(engine->window.mlx, "game/textures/background0.xpm", &map.textures[2].tex))
		return (1);
	if (image_from_xpm(engine->window.mlx, "game/textures/background0.xpm", &map.textures[3].tex))
		return (1);

	if (game_initialize(engine))
		return (1);
	window_loop(&engine->window);
	return (0);
}

int main(int argc, char *argv[])
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
