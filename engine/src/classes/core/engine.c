/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 03:46:48 by dderny            #+#    #+#             */
/*   Updated: 2025/11/02 04:34:27 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "classes/core/engine.h"
#include "classes/object.h"

int	engine_construct(t_engine *self)
{
	self->_destruct = &engine_destruct;
	if (object_construct((t_object *)self))
		return (1);
	self->singletons = vec_new(self->garbage, sizeof(t_singleton), 2);
	if (!self->singletons)
		return (1);
	return (0);
}

int	engine_destruct(t_engine *self)
{
	object_destruct((t_object *)self);
	if (self->singletons)
		vec_free(self->singletons);
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
