/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 02:53:40 by dderny            #+#    #+#             */
/*   Updated: 2026/02/23 16:47:51 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/inputs.h"
#include "math/extend.h"

int	inputs_mousedown(int key, t_engine *engine)
{
	(void)engine;
	(void)key;
	return (0);
}

int	inputs_mousemove(int x, int y, t_engine *engine)
{
	if (BONUS)
		camera_mouse_move(x, y, engine);
	return (0);
}

int	inputs_mouseup(int key, t_engine *engine)
{
	(void)engine;
	(void)key;
	return (0);
}
