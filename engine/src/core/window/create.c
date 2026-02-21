/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:12:19 by dderny            #+#    #+#             */
/*   Updated: 2026/02/21 00:04:27 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/game.h"
#include "core/window.h"
#include <mlx.h>

int	window_create(t_window *out, t_window base, void *engine)
{
	*out = base;
	out->engine = engine;
	out->width = g_win_width;
	out->height = g_win_height;
	out->mlx = mlx_init();
	if (!out->mlx)
		return (1);
	out->mlx_win = mlx_new_window(out->mlx, g_win_width, g_win_height,
			(char *)g_win_title);
	if (!out->mlx_win)
		return (1);
	if (image_new(out->mlx, g_win_width, g_win_height, &out->buffer))
		return (1);
	mlx_do_key_autorepeatoff(out->mlx);
	mlx_hook(out->mlx_win, ON_DESTROY, 0, out->close, out->engine);
	mlx_hook(out->mlx_win, ON_KEYDOWN, KeyPressMask, out->keydown, out->engine);
	mlx_hook(out->mlx_win, ON_KEYUP, KeyReleaseMask, out->keyup, out->engine);
	mlx_hook(out->mlx_win, ON_MOUSEUP, ButtonPressMask, out->mousedown,
		out->engine);
	mlx_hook(out->mlx_win, ON_MOUSEDOWN, ButtonReleaseMask, out->mousedown,
		out->engine);
	mlx_hook(out->mlx_win, ON_MOUSEMOVE, PointerMotionMask, out->mousemove,
		out->engine);
	mlx_loop_hook(out->mlx, out->update, out->engine);
	return (0);
}
