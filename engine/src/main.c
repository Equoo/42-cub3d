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
#include "libft.h"
#include "core/engine.h"

int	engine_initialize(t_engine *engine, int argc, char *argv[])
{
	engine->max_fps = 0;
	engine->physics_ticks = 20;
	if (window_create(&engine->window, (t_window){.engine = engine,
		.width = 1920, .height = 1080, .title = "Cub3d",
		.close = &engine_close,
		.update = &engine_update
	}))
		return (1);
	(void)argc;
    (void)argv;
	return (0);
}

int main(int argc, char *argv[])
{
	t__xgarbage	garbage;
	t_engine	engine;

	if (_garbage_init(&garbage))
		return (1);
	engine = (t_engine){.garbage = &garbage};
	if (engine_initialize(&engine, argc, argv))
	{
		engine_close(&engine);
		return (1);
	}
	engine_close(&engine);
    return (0);
}
