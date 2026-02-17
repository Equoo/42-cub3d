/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 02:53:52 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 03:01:50 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/engine.h"
#include "core/window.h"
#include "core/world.h"

int	engine_close(t_engine *engine)
{
	map_destroy(engine->window.mlx, engine->map);
	garbage_collector(engine->garbage);
	window_destruct(&engine->window);
	return (0);
}
