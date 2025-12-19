/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 03:46:48 by dderny            #+#    #+#             */
/*   Updated: 2025/12/01 23:41:11 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <mlx.h>

#include "classes/core/engine.h"
#include "classes/core/engine.hpp"
#include "classes/object.h"

int	engine_construct(t_engine *self, t__xgarbage *garbage)
{
	t_singleton	tmp;

	*self = (t_engine){.garbage = garbage};
	if (object_construct((t_object *)self))
		return (1);
	self->_destruct = &engine_destruct;
	self->get_singleton = &engine_get_singleton;
	self->add_singleton = &engine_add_singleton;
	self->max_fps = 0;
	self->physics_ticks = 20;
	self->singletons = vec_new(self->garbage, sizeof(t_singleton), 2);
	if (!self->singletons)
		return (1);
	self->mlx = mlx_init();
	if (!self->mlx)
		return (1);
	tmp = (t_singleton){ID_MLX, self->mlx};
	if (vec_append((void *)&self->singletons, &tmp))
		return (1);
	// mlx_do_key_autorepeatoff(env.render.mlx);
	mlx_loop_hook(self->mlx, &, &self);
	mlx_loop(env.render.ml);
	return (0);
}

int	engine_destruct(t_engine *self)
{
	void	*mlx;

	object_destruct((t_object *)self);
	if (self->singletons)
	{
		mlx = self->get_singleton(self, ID_MLX);
		if (mlx)
		{
			mlx_destroy_display(mlx);
			free(mlx);
		}
		vec_free(self->singletons);
	}
	return (0);
}

void	*engine_get_singleton(t_engine *self, id_t id)
{
	size_t	i;
	
	i = 0;
	while (i < vec_size(self->singletons))
	{
		if (self->singletons[i].id == id)
			return (self->singletons[i].object);
		i++;
	}
	return (NULL);
}

int	engine_add_singleton(t_engine *self, id_t id, void *singleton)
{
	const t_singleton data = {
		id,
		singleton
	};

	vec_append((void *)self->singletons, (void *)&data);
	return (0);
}
