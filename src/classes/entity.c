/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 00:39:08 by dderny            #+#    #+#             */
/*   Updated: 2025/04/26 19:54:59 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/entity.h"
#include "collisions.h"
#include "scene.h"
#include "vector2d.h"
#include <libft.h>
#include <stdint.h>

void	entity_del(t_element **self)
{
	t_entity	*entity;

	entity = cast_entity((*self)->parent);
	element_del(self);
	if (entity)
		free(entity);
}

t_entity	*ft_entity(t_scene *scene, int zindex)
{
	t_element	*base;
	t_entity	*entity;

	base = ft_element(scene, zindex);
	if (!base)
		return (NULL);
	entity = ft_calloc(1, sizeof(t_entity));
	if (!entity)
	{
		base->del(&base);
		return (NULL);
	}
	entity->base = base;
	entity->entity = entity;
	entity->gravity_dir = (t_vec2){0, -1};
	entity->hull = (t_aabb){{-8, -16}, {8, 0}, {0}, {0}};
	entity->base->update = &entity_physic;
	entity->base->parent = entity;
	entity->base->class = CLASS_ENTITY;
	entity->base->del = &entity_del;
	return (entity);
}

t_entity	*cast_entity(void *entity)
{
	if (!entity)
		return (NULL);
	return ((t_entity *)(((uintptr_t *)entity))[1]);
}
