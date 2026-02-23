/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:41:37 by dderny            #+#    #+#             */
/*   Updated: 2026/02/23 16:47:07 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/engine.h"
#include "core/inputs.h"
#include "core/physics.h"
#include "math/extend.h"
#include <X11/keysym.h>

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
	engine->camera.rot.z = sanitize_angle(engine->camera.rot.z);
	if (iskeydown(engine, XK_Alt_L))
		mlx_mouse_show(engine->window.mlx, engine->window.mlx_win);
	else
		mlx_mouse_hide(engine->window.mlx, engine->window.mlx_win);
	return (0);
}

int	camera_mouse_move(int x, int y, t_engine *engine)
{
	int	center_x;
	int	center_y;

	center_x = engine->window.width / 2;
	center_y = engine->window.height / 2;
	if (x == center_x && y == center_y)
		return (0);
	engine->camera.rot.z += ((x - center_x) * engine->camera.rot_speed
			* engine->frametime);
	engine->camera.rot.z = sanitize_angle(engine->camera.rot.z);
	mlx_mouse_move(engine->window.mlx, engine->window.mlx_win, center_x,
		center_y);
	return (0);
}
