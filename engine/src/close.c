/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 02:53:52 by dderny            #+#    #+#             */
/*   Updated: 2026/02/28 18:55:58 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/engine.h"
#include "core/window.h"
#include "core/world.h"
#include "mlx.h"

int	engine_close(t_engine *engine)
{
	if (engine)
		map_destroy(engine->window.mlx, &engine->map);
	if (engine->sprite.img)
		mlx_destroy_image(engine->window.mlx, engine->sprite.img);
	garbage_collector(engine->garbage);
	window_destruct(&engine->window);
	return (0);
}
