/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:55:01 by dderny            #+#    #+#             */
/*   Updated: 2025/04/24 23:25:12 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/entity.h"
#include "classes/entities/actor.h"
#include "texture.h"

void	actor_update(t_element *self)
{
	t_actor	*actor;

	entity_physic(self);
	actor = cast_actor(self->parent);
	if (actor && actor->health <= 0)
	{
		if (!actor->die_end_time)
		{
			if (actor->death_anim)
			{
				actor->die_end_time = self->scene->env->time
					+ texture_slice_time(self->texture, actor->death_anim);
				self->play_anim(self, actor->death_anim);
			}
			else
				actor->die_end_time = self->scene->env->time + 0.1f;
			actor->entity->nocollision = 1;
			if (actor->on_die)
				actor->on_die(actor);
		}
		else if (actor->die_end_time <= self->scene->env->time)
			self->del(&self);
	}
}
