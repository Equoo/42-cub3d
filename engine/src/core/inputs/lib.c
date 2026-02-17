/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 02:53:29 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 03:04:40 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/inputs.h"

int	inputs_update(t_engine *engine)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		engine->keys_states[i][0] = engine->internal_keys[i];
		if (!engine->internal_keys[i])
		{
			if (engine->keys_states[i][1] < KEY_RELEASED)
				engine->keys_states[i][1] = KEY_RELEASED;
			else
				engine->keys_states[i][1] = KEY_NONE;
			i++;
			continue ;
		}
		if (!engine->internal_last_keys[i])
			engine->keys_states[i][1] = KEY_PRESSED;
		else
			engine->keys_states[i][1] = KEY_DOWN;
		i++;
	}
	ft_memcpy(&engine->internal_last_keys, &engine->internal_keys, sizeof(int)
		* 32);
	return (0);
}

int	iskeypressed(t_engine *engine, u_int keycode)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (engine->keys_states[i][0] == keycode
			&& engine->keys_states[i][1] == KEY_PRESSED)
			return (1);
		i++;
	}
	return (0);
}

int	iskeyreleased(t_engine *engine, u_int keycode)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (engine->keys_states[i][0] == keycode
			&& engine->keys_states[i][1] == KEY_RELEASED)
			return (1);
		i++;
	}
	return (0);
}

int	iskeydown(t_engine *engine, u_int keycode)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (engine->keys_states[i][0] == keycode
			&& engine->keys_states[i][1] == KEY_DOWN)
			return (1);
		i++;
	}
	return (0);
}
