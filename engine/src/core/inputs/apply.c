/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 03:07:08 by dderny            #+#    #+#             */
/*   Updated: 2026/02/20 08:39:02 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/engine.h"
#include "core/physics.h"
#include "core/inputs.h"
#include <X11/keysym.h>

int apply_inputs(t_engine *engine)
{
	t_camera *camera;

	camera = &engine->camera;
	if (iskeydown(engine, (uint)'w'))
		camera->pos = vec3_add(camera->pos, vec3_mulf(rot_forward(camera->rot),
													  2 * engine->frametime));
	if (iskeydown(engine, (uint)'a'))
		camera->pos = vec3_add(camera->pos, vec3_mulf(rot_right(camera->rot), 2 * engine->frametime));
	if (iskeydown(engine, (uint)'d'))
		camera->pos = vec3_add(camera->pos, vec3_mulf(rot_right(camera->rot), -2 * engine->frametime));
	if (iskeydown(engine, (uint)'s'))
		camera->pos = vec3_add(camera->pos, vec3_mulf(rot_forward(camera->rot),
													  -2 * engine->frametime));
	if (iskeydown(engine, XK_Left))
		camera->rot.z += -100 * engine->frametime;
	if (iskeydown(engine, XK_Right))
		camera->rot.z += 100 * engine->frametime;
	return (0);
}

// Need refacto/norm
int apply_inputs_with_collision(t_engine *engine)
{
	t_camera *camera;
	t_vec3 fwd;
	t_vec3 right;
	float speed;
	float dx;
	float dy;

	camera = &engine->camera;
	fwd = rot_forward(camera->rot);
	right = rot_right(camera->rot);

	dx = 0.0f;
	dy = 0.0f;
	if (iskeydown(engine, XK_Shift_L))
		speed = 3.5f * engine->frametime;
	else
		speed = 2.0f * engine->frametime;
	if (iskeydown(engine, (uint)'w'))
	{
		dx += fwd.x * speed;
		dy += fwd.y * speed;
	}
	if (iskeydown(engine, (uint)'s'))
	{
		dx -= fwd.x * speed;
		dy -= fwd.y * speed;
	}
	if (iskeydown(engine, (uint)'a'))
	{
		dx += right.x * speed;
		dy += right.y * speed;
	}
	if (iskeydown(engine, (uint)'d'))
	{
		dx -= right.x * speed;
		dy -= right.y * speed;
	}
	if (dx != 0.0f || dy != 0.0f)
		move_with_collision(engine, dx, dy);
	if (iskeydown(engine, XK_Left))
		camera->rot.z += -100.0f * engine->frametime;
	if (iskeydown(engine, XK_Right))
		camera->rot.z += 100.0f * engine->frametime;
	return (0);
}
