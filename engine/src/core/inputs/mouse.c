/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 02:53:40 by dderny            #+#    #+#             */
/*   Updated: 2026/02/23 16:47:51 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/inputs.h"
#include "math/extend.h"

int	inputs_mousedown(int key, int x, int y, t_engine *engine)
{
	(void)x;
	(void)y;
	if (BONUS && key == SCROLL_UP && engine->mmap_zoom < ZOOM_MAX)
		engine->mmap_zoom += ZOOM_STEP;
	if (BONUS && key == SCROLL_DOWN && engine->mmap_zoom > ZOOM_MIN)
		engine->mmap_zoom -= ZOOM_STEP;
	if (BONUS && key == MOUSE_LEFT
		&& engine->camera.rot_speed < ROT_SPEED_MAX)
		engine->camera.rot_speed += ROT_SPEED_STEP;
	if (BONUS && key == MOUSE_RIGHT
		&& engine->camera.rot_speed > ROT_SPEED_MIN)
		engine->camera.rot_speed -= ROT_SPEED_STEP;
	return (0);
}

int	inputs_mousemove(int x, int y, t_engine *engine)
{
	if (BONUS)
		camera_mouse_move(x, y, engine);
	return (0);
}

int	inputs_mouseup(int key, int x, int y, t_engine *engine)
{
	(void)engine;
	(void)key;
	(void)x;
	(void)y;
	return (0);
}
