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

int	engine_construct(t_engine *self)
{
	t_singleton	tmp;

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
	tmp = (t_singleton){ID_MLX, mlx_init()};
	if (!tmp.object || vec_append((void *)self->singletons, &tmp))
		return (1);
	return (0);
}

int	engine_destruct(t_engine *self)
{
	object_destruct((t_object *)self);
	if (self->singletons)
	{
		if (self->get_singleton(self, ID_MLX))
			free(self->get_singleton(self, ID_MLX));
		vec_free(self->singletons);
	}
	return (0);
}

t_engine		*engine_new(t__xgarbage *garbage)
{
	t_engine	*engine;

	engine = ft_xcalloc(garbage, sizeof(t_engine), 0);
	if (!engine)
		return (NULL);
	*engine = (t_engine){.garbage = garbage};
	if (engine_construct(engine))
	{
		engine->free(engine);
		return (NULL);
	}
	return (engine);
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
