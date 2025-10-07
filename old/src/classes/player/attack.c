/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:12:45 by dderny            #+#    #+#             */
/*   Updated: 2025/04/25 21:09:20 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/entities/player.h"
#include "classes/entity.h"
#include "collisions.h"
#include "scene.h"
#include "vector2d.h"

void	player_attack(t_player *self)
{
	t_trace	tr;
	t_sweep	sweep;
	t_actor	*actor;

	tr = (t_trace){{0}, {0}, self->entity->hull, CGROUP_ACTOR, self->base->id};
	tr.from = vec2_add(self->base->pos,
			(t_vec2){self->entity->hull.min.x * 2 * self->actor->direction
			* -1, 0});
	tr.to = tr.from;
	sweep = world_sweep_aabb(self->base->scene, tr);
	actor = NULL;
	if (sweep.hit.touch && sweep.hit.element
		&& sweep.hit.element->class & CGROUP_ACTOR)
		actor = cast_actor(sweep.hit.element->parent);
	if (actor)
	{
		actor->health -= 50;
		if (actor->base->class == CLASS_FROG)
			actor->base->play_anim(actor->base, "Hurt");
		actor->entity->velocity = vec2_add(actor->entity->velocity,
				vec2_scaled(sweep.hit.normal, 100
					* self->base->scene->env->frametime));
	}
	self->base->play_anim(self->base, "Attack_1");
}
