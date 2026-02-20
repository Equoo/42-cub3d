/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:12:19 by dderny            #+#    #+#             */
/*   Updated: 2026/02/20 20:54:26 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/game.h"
#include "core/window.h"
#include <mlx.h>

int	window_create(t_window *out, t_window base, void *engine)
{
	base.engine = engine;
	base.width = g_win_width;
	base.height = g_win_height;
	base.mlx = mlx_init();
	if (!base.mlx)
		return (1);
	base.mlx_win = mlx_new_window(base.mlx, g_win_width, g_win_height,
			(char *)g_win_title);
	if (!base.mlx_win)
		return (1);
	if (image_new(base.mlx, g_win_width, g_win_height, &base.buffer))
		return (1);
	mlx_do_key_autorepeatoff(base.mlx);
	mlx_hook(base.mlx_win, ON_DESTROY, 0, base.close, base.engine);
	mlx_hook(base.mlx_win, ON_KEYDOWN, KeyPressMask, base.keydown, base.engine);
	mlx_hook(base.mlx_win, ON_KEYUP, KeyReleaseMask, base.keyup, base.engine);
	mlx_hook(base.mlx_win, ON_MOUSEUP, ButtonPressMask, base.mousedown,
		base.engine);
	mlx_hook(base.mlx_win, ON_MOUSEDOWN, ButtonReleaseMask, base.mousedown,
		base.engine);
	mlx_hook(base.mlx_win, ON_MOUSEMOVE, PointerMotionMask, base.mousemove,
		base.engine);
	mlx_loop_hook(base.mlx, base.update, base.engine);
	*out = base;
	return (0);
}
