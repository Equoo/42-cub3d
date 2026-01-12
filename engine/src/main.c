/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:33:22 by dderny            #+#    #+#             */
/*   Updated: 2025/11/18 02:20:46 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/window.h"
#include "core/world.h"
#include "libft.h"
#include "core/engine.h"
#include "core/camera.h"
#include "core/inputs.h"
#include "core/game.h"

// Using global variables that are **not marked const or static** is forbidden
// and is considered a norm error, unless the project explicitly allows them.
const static t_engine	g_engine = {
	.max_fps = 0,
	.physics_ticks = 20
};

const static t_window	g_window = {
	.mousedown = &inputs_mousedown,
	.mousemove = &inputs_mousemove,
	.mouseup = &inputs_mouseup,
	.keydown = &inputs_keydown,
	.keyup = &inputs_keyup,

	.close = &engine_close,
	.update = &engine_update
};


#define RED 0xff00ffff
#define BLUE 0xffff00ff
#define GREEN 0xffffff00
#define RDM 0xfff0fef0

int	engine_initialize(t_engine *engine, int argc, char *argv[])
{
	if (window_create(&engine->window, g_window, engine))
		return (1);
	(void)argc;
	(void)argv;

	engine->camera = (t_camera){.fov = 90};
	t_world     world = (t_world){.n_sectors = NSECTORS};
	engine->world = &world;

	world.sectors = ft_xalloc(engine->garbage, sizeof(t_sector) * NSECTORS, 0);
	world.sectors[0] = ft_xalloc(engine->garbage, sizeof(t_sector) + sizeof(t_face) * 5, 1024);
	*world.sectors[0] = (t_sector){ 0, 100, {.rgb=0xffffffff}, {.rgb=0xfffffff}, 5};
	world.sectors[0]->faces[0] = (t_face){-1, -1, {-1000, -1000}, {.rgb=RED}};
	world.sectors[0]->faces[1] = (t_face){1, 3, {1000, -1000}, {.rgb=BLUE}};
	world.sectors[0]->faces[2] = (t_face){-1, -1, {1000, 1000}, {.rgb=GREEN}};
	world.sectors[0]->faces[3] = (t_face){-1, -1, {0, 1450}, {.rgb=RDM}};
	world.sectors[0]->faces[4] = (t_face){-1, -1, {-1000, 1000}, {.rgb=RDM}};

	world.sectors[1] = ft_xalloc(engine->garbage, sizeof(t_sector) + sizeof(t_face) * 4, 1024);
	*world.sectors[1] = (t_sector){ 0, 100, {.rgb=0xffffffff}, {.rgb=0xfffffff}, 4};
	world.sectors[1]->faces[0] = (t_face){-1, -1, {1000, -1000}, {.rgb=RED}};
	world.sectors[1]->faces[1] = (t_face){-1, -1, {3000, -1000}, {.rgb=BLUE}};
	world.sectors[1]->faces[2] = (t_face){-1, -1, {3000, 1000}, {.rgb=GREEN}};
	world.sectors[1]->faces[3] = (t_face){0, 1, {1000, 1000}, {.rgb=RDM}};

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
