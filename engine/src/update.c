/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:10:24 by dderny            #+#    #+#             */
/*   Updated: 2026/02/14 16:10:24 by dderny                  ###   ########   */
/*                                                                            */
/* ************************************************************************** */


#include "core/draw.h"
#include "core/engine.h"
#include "core/game.h"
#include "core/inputs.h"
#include <ft_time.h>
#include <sys/types.h>

static int	work(t_engine *engine)
{
	t_camera	*camera;
	int			i;
	t_vec2		a;
	t_vec2		b;

	camera = &engine->camera;
	if (iskeydown(engine, (uint)'w'))
		camera->pos = vec3_add(camera->pos, vec3_mulf(rot_forward(camera->rot),
					2 * engine->frametime));
	if (iskeydown(engine, (uint)'a'))
		camera->pos = vec3_add(camera->pos, vec3_mulf(rot_right(camera->rot), -2
					* engine->frametime));
	if (iskeydown(engine, (uint)'d'))
		camera->pos = vec3_add(camera->pos, vec3_mulf(rot_right(camera->rot), 2
					* engine->frametime));
	if (iskeydown(engine, (uint)'s'))
		camera->pos = vec3_add(camera->pos, vec3_mulf(rot_forward(camera->rot),
					-2 * engine->frametime));
	if (iskeydown(engine, (uint)'q'))
		camera->rot.z += -70 * engine->frametime;
	if (iskeydown(engine, (uint)'e'))
		camera->rot.z += 70 * engine->frametime;
	window_drawbuffer(&engine->window);
	draw_walls(&engine->window.buffer, *engine->map, engine->camera);
	i = 0;
	while (i < engine->map->height * engine->map->width)
	{
		if (engine->map->cells[i] != '1' && ++i)
			continue ;
		a = {100 + (i % engine->map->width) * 10, 500 + i / engine->map->height
			* 10};
		b = vec2_add(a, (t_vec2){10, 10});
		draw_square(&engine->window.buffer, a, b, (t_rgba)0xffff00ff);
		i++;
	}
	__builtin_printf("FPS: %f\n", engine->frametime > 0 ? 1
		/ engine->frametime : 0);
	return (0);
}

static int	time_update(t_engine *engine)
{
	static double	lastrealtime = 0;
	static double	elapsed = 0;

	engine->time = curtime_us();
	if (!engine->start_time)
		engine->start_time = engine->time;
	if (!engine->last_frame)
		engine->last_frame = engine->time;
	if (!lastrealtime)
		lastrealtime = engine->time;
	elapsed += engine->time - lastrealtime;
	if (elapsed >= 1.f / ((double)engine->physics_ticks))
	{
		elapsed -= 1.f / ((double)engine->physics_ticks);
		engine->frametime = (engine->time - engine->last_frame);
		if (engine_tick(engine))
			return (1);
		engine->last_frame = engine->time;
	}
	engine->frametime = (engine->time - lastrealtime);
	work(engine);
	lastrealtime = engine->time;
	return (0);
}

int	engine_update(t_engine *engine)
{
	if (time_update(engine) || game_update(engine))
	{
		engine_close(engine);
	}
	inputs_update(engine);
	return (0);
}

int	engine_tick(t_engine *engine)
{
	game_tick(engine);
	return (0);
}
