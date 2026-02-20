/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:28:02 by dderny            #+#    #+#             */
/*   Updated: 2026/02/20 08:32:55 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTS_H
# define INPUTS_H
# include "core/engine.h"
# include <sys/types.h>

typedef enum e_key_state
{
	KEY_NONE,
	KEY_PRESSED,
	KEY_DOWN,
	KEY_RELEASED
}	t_key_state;

int	inputs_mousedown(int key, t_engine *engine);
int	inputs_mousemove(int x, int y, t_engine *engine);
int	inputs_mouseup(int key, t_engine *engine);

int	inputs_keydown(int key, t_engine *engine);
int	inputs_keyup(int key, t_engine *engine);

int	inputs_update(t_engine *engine);

int	iskeydown(t_engine *engine, u_int key);
int	iskeyreleased(t_engine *engine, u_int key);
int	iskeyup(t_engine *engine, u_int key);

int	apply_inputs(t_engine *engine);
int	apply_inputs_with_collision(t_engine *engine);

#endif
