/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:10:24 by dderny            #+#    #+#             */
/*   Updated: 2026/02/28 16:14:37 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/engine.h"
#include "core/game.h"
#include "core/inputs.h"
#include "core/world.h"
#include <ft_printf.h>
#include <ft_time.h>
#include <stdint.h>
#include <sys/types.h>

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

static int	render_update(t_engine *engine)
{
	window_drawbuffer(&engine->window);
	draw_walls(&engine->window.buffer, *engine->map, engine->camera);
	if (BONUS)
		update_sprites(1, engine->map->sprites, engine->camera);
	draw_minimap(&engine->window.buffer, engine->map, engine->camera,
		engine->mmap_zoom);
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
