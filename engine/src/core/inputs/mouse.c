/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 02:53:40 by dderny            #+#    #+#             */
/*   Updated: 2026/02/21 02:37:22 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/inputs.h"
#include "math/extend.h"

int	inputs_mousedown(int key, t_engine *engine)
{
	(void)engine;
	(void)key;
	return (0);
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
	engine->camera.rot.z = sanitize_angle(engine->camera.rot.z);
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
