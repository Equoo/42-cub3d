/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:12:19 by dderny            #+#    #+#             */
/*   Updated: 2025/12/01 23:04:41 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "core/game.h"
#include "core/window.h"

static int image_new(void *mlx, int width, int height, t_image *out)
{
	out->img = mlx_new_image(mlx, width, height);
	if (!out->img)
		return (1);
	out->data = (t_rgba *)mlx_get_data_addr(out->img, &out->size_line,
			&out->size_line, &out->height);
	out->size_line /= 4;
	out->width = width;
	out->height = height;
	out->size = out->size_line * out->height;
	return (0);
}

int	window_create(t_window *out, t_window base, void *engine)
{
	base.engine = engine;
	base.mlx = mlx_init();
	if (!base.mlx)
		return (1);
	base.mlx_win = mlx_new_window(base.mlx, g_win_width,
				g_win_height, (char *)g_win_title);
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
	mlx_hook(base.mlx_win, ON_MOUSEMOVE, 0, base.mousemove, base.engine);
	mlx_loop_hook(base.mlx, base.update, base.engine);
	*out = base;
	return (0);
}

