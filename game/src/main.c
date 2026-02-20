/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:51:55 by dderny            #+#    #+#             */
/*   Updated: 2026/02/20 08:48:06 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/game.h"

const int g_win_width = 1920;
const int g_win_height = 1080;

const char *g_win_title = "Cub3d";

int game_initialize(t_engine *engine)
{
	mlx_mouse_hide(engine->window.mlx, engine->window.mlx_win);
	return (0);
}

int game_update(t_engine *engine)
{
	(void)engine;
	return (0);
}

int game_tick(t_engine *engine)
{
	(void)engine;
	return (0);
}
