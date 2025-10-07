/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:23:05 by dderny            #+#    #+#             */
/*   Updated: 2025/04/26 00:57:42 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "cub3d.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <bits/floatn-common.h>
#include <sys/types.h>

int	down_key(int keycode, t_gameenv *env)
{
	int	i;
	int	first_zero;

	if (keycode == XK_Escape)
		process_close(env);
	first_zero = -1;
	i = 0;
	while (i < 32)
	{
		if (first_zero == -1 && env->keys_states[i][0] == 0)
			first_zero = i;
		if (env->internal_keys[i] == (u_int)keycode)
			return (0);
		i++;
	}
	if (first_zero != -1)
		env->internal_keys[first_zero] = keycode;
	return (0);
}

int	up_key(int keycode, t_gameenv *env)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (env->internal_keys[i] == (u_int)keycode)
		{
			env->internal_keys[i] = 0;
			return (0);
		}
		i++;
	}
	return (0);
}

void	tick_inputs(t_gameenv *env)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		env->keys_states[i][0] = env->internal_keys[i];
		if (!env->internal_keys[i])
		{
			if (env->keys_states[i][1] < KEY_RELEASED)
				env->keys_states[i][1] = KEY_RELEASED;
			else
				env->keys_states[i][1] = KEY_NONE;
			i++;
			continue ;
		}
		if (!env->internal_last_keys[i])
			env->keys_states[i][1] = KEY_PRESSED;
		else
			env->keys_states[i][1] = KEY_DOWN;
		i++;
	}
	ft_memcpy(&env->internal_last_keys, &env->internal_keys, sizeof(int) * 32);
}
