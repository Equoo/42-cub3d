/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isreleased.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:37:57 by dderny            #+#    #+#             */
/*   Updated: 2025/04/22 14:40:28 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "cub3d.h"
#include <sys/types.h>

int	input_isreleased(u_int keycode, t_gameenv *env)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (env->keys_states[i][0] == keycode
			&& env->keys_states[i][1] == KEY_RELEASED)
			return (1);
		i++;
	}
	return (0);
}
