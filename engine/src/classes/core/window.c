/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:12:19 by dderny            #+#    #+#             */
/*   Updated: 2025/12/01 23:04:41 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "classes/core/window.h"
#include "classes/core/engine.h"

int	window_on_destroy(t_window *self, int (*func)())
{
	mlx_hook(self->mlx_win, ON_DESTROY, 0, func, &self->engine);
	return (0);
}

int	window_construct(t_window *self, t_engine *engine)
{
	*self = (t_window){.garbage = engine->garbage, .engine = engine};
	if (object_construct((t_object *)self))
		return (1);
	self->_destruct = &window_destruct;
	self->width = 1920;
	self->height = 1080;
	self->mlx = engine->get_singleton(engine, ID_MLX);
	self->mlx_win = mlx_new_window(self->mlx, self->width,
				self->height, "Cub3D");
	if (!self->mlx_win)
		return (1);
	return (0);
}

int	window_destruct(t_window *self)
{
	object_destruct((t_object *)self);
	if (self->childs)
		vec_free(self->childs);
	if (self->mlx_win)
		mlx_destroy_window(self->mlx, self->mlx_win);
	return (0);
}

t_window		*window_new(t_engine *engine)
{
	t_window	*window;

	window = ft_xcalloc(engine->garbage, sizeof(t_window), 0);
	if (!window)
		return (NULL);
	if (window_construct(window, engine))
	{
		window->free(window);
		return (NULL);
	}
	return (window);
}
