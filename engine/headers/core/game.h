/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:27:45 by dderny            #+#    #+#             */
/*   Updated: 2026/02/14 16:02:40 by dderny                  ###   ########   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "core/engine.h"

extern const int	g_win_width;
extern const int	g_win_height;
extern const char	*g_win_title;

int					game_initialize(t_engine *engine);
int					game_update(t_engine *engine);
int					game_tick(t_engine *engine);

#endif
