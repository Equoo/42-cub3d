/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 03:07:08 by dderny            #+#    #+#             */
/*   Updated: 2026/02/23 23:41:25 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/engine.h"
#include "core/inputs.h"
#include "math/extend.h"
#include <X11/keysym.h>

int	apply_inputs(t_engine *engine)
{
	t_camera	*camera;

	if (BONUS)
		apply_inputs_with_collision(engine);
	if (BONUS)
		return (0);
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
