/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:32:11 by dderny            #+#    #+#             */
/*   Updated: 2025/04/26 19:56:10 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/entities/actor.h"
#include "classes/entity.h"
#include "scene.h"
#include <stdlib.h>
#include <stdint.h>

void	actor_del(t_element **self)
{
	t_actor	*actor;

	actor = cast_actor((*self)->parent);
	if (actor && actor->on_die && !actor->die_end_time)
		actor->on_die(actor);
	entity_del(self);
	if (actor)
		free(actor);
}

static void	init_actor(t_actor *actor, t_entity *entity)
{
	actor->entity = entity;
	actor->actor = actor;
	actor->move = &actor_move;
	actor->direction = 1;
	actor->health = 100;
	actor->base = entity->base;
	actor->base->parent = actor;
	actor->base->update = &actor_update;
	actor->base->draw = &actor_draw;
	actor->base->class = CLASS_ACTOR;
	actor->base->del = &actor_del;
	actor->entity->base = actor->base;
}

t_actor	*ft_actor(t_scene *scene)
{
	t_entity	*entity;
	t_actor		*actor;

	entity = ft_entity(scene, 10);
	if (!entity)
		return (NULL);
	actor = ft_calloc(1, sizeof(t_actor));
	if (!actor)
	{
		entity->base->del(&entity->base);
		return (NULL);
	}
	init_actor(actor, entity);
	return (actor);
}

t_actor	*cast_actor(void *actor)
{
	if (!actor)
		return (NULL);
	return ((t_actor *)(((uintptr_t *)actor))[2]);
}
