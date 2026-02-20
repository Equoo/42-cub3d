/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 02:53:40 by dderny            #+#    #+#             */
/*   Updated: 2026/02/20 21:53:16 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/inputs.h"

int	inputs_mousedown(int key, t_engine *engine)
{
	(void)engine;
	(void)key;
	return (0);
}

static float	sanitize_angle(float f)
{
	if (f > 360)
		f -= 360;
	else if (f < 0)
		f += 360;
	return (f);
}

int	inputs_mousemove(int x, int y, t_engine *engine)
{
	int	center_x;
	int	center_y;

	center_x = engine->window.width / 2;
	center_y = engine->window.height / 2;
	if (x == center_x && y == center_y)
		return (0);
	engine->camera.rot.z += ((x - center_x) * engine->camera.rot_speed
			* engine->frametime);
	sanitize_angle(engine->camera.rot.z);
	mlx_mouse_move(engine->window.mlx, engine->window.mlx_win, center_x,
		center_y);
	return (0);
}

int	inputs_mouseup(int key, t_engine *engine)
{
	(void)engine;
	(void)key;
	return (0);
}
