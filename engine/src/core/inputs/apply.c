/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 03:07:08 by dderny            #+#    #+#             */
/*   Updated: 2026/02/21 02:24:06 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/engine.h"
#include "core/inputs.h"
#include "core/physics.h"
#include "math/extend.h"
#include <X11/keysym.h>

int	apply_inputs(t_engine *engine)
{
	t_camera	*camera;

	camera = &engine->camera;
	if (iskeydown(engine, (uint) 'w'))
		camera->pos = vec3_add(camera->pos, vec3_mulf(rot_forward(camera->rot),
					2 * engine->frametime));
	if (iskeydown(engine, (uint) 'a'))
		camera->pos = vec3_add(camera->pos, vec3_mulf(rot_right(camera->rot), 2
					* engine->frametime));
	if (iskeydown(engine, (uint) 'd'))
		camera->pos = vec3_add(camera->pos, vec3_mulf(rot_right(camera->rot), -2
					* engine->frametime));
	if (iskeydown(engine, (uint) 's'))
		camera->pos = vec3_add(camera->pos, vec3_mulf(rot_forward(camera->rot),
					-2 * engine->frametime));
	if (iskeydown(engine, XK_Left))
		camera->rot.z += -100 * engine->frametime;
	if (iskeydown(engine, XK_Right))
		camera->rot.z += 100 * engine->frametime;
	camera->rot.z = sanitize_angle(camera->rot.z);
	return (0);
}

static void	apply_sprint(t_engine *engine)
{
	if (iskeydown(engine, XK_Shift_L))
		engine->camera.speed = 3.5f * engine->frametime;
	else
		engine->camera.speed = 2.0f * engine->frametime;
}

static void	apply_movements(t_engine *engine, float *dx, float *dy)
{
	t_vec3	fwd;
	t_vec3	right;

	fwd = rot_forward(engine->camera.rot);
	right = rot_right(engine->camera.rot);
	if (iskeydown(engine, (uint) 'w'))
	{
		*dx += fwd.x * engine->camera.speed;
		*dy += fwd.y * engine->camera.speed;
	}
	if (iskeydown(engine, (uint) 's'))
	{
		*dx -= fwd.x * engine->camera.speed;
		*dy -= fwd.y * engine->camera.speed;
	}
	if (iskeydown(engine, (uint) 'a'))
	{
		*dx += right.x * engine->camera.speed;
		*dy += right.y * engine->camera.speed;
	}
	if (iskeydown(engine, (uint) 'd'))
	{
		*dx -= right.x * engine->camera.speed;
		*dy -= right.y * engine->camera.speed;
	}
}

int	apply_inputs_with_collision(t_engine *engine)
{
	float	dx;
	float	dy;

	dx = 0.0f;
	dy = 0.0f;
	apply_sprint(engine);
	apply_movements(engine, &dx, &dy);
	if (dx != 0.0f || dy != 0.0f)
		move_with_collision(engine, dx, dy);
	if (iskeydown(engine, XK_Left))
		engine->camera.rot.z += -100.0f * engine->frametime;
	if (iskeydown(engine, XK_Right))
		engine->camera.rot.z += 100.0f * engine->frametime;
	if (iskeydown(engine, XK_Alt_L))
		mlx_mouse_show(engine->window.mlx, engine->window.mlx_win);
	else
		mlx_mouse_hide(engine->window.mlx, engine->window.mlx_win);
	return (0);
}
