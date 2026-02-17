/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 02:53:40 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 02:53:47 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/inputs.h"

int	inputs_mousedown(int key, t_engine *engine)
{
	(void)engine;
	(void)key;
	return (0);
}

int	inputs_mousemove(int x, int y, t_engine *engine)
{
	(void)engine;
	(void)x;
	(void)y;
	return (0);
}

int	inputs_mouseup(int key, t_engine *engine)
{
	(void)engine;
	(void)key;
	return (0);
}
