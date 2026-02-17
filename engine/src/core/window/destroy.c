/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:12:19 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 03:51:45 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/window.h"
#include <mlx.h>

int	window_destruct(t_window *win)
{
	if (win->mlx_win)
		mlx_destroy_window(win->mlx, win->mlx_win);
	if (win->mlx)
	{
		mlx_do_key_autorepeaton(win->mlx);
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	exit(EXIT_SUCCESS);
	return (0);
}
