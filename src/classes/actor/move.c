/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 06:58:02 by dderny            #+#    #+#             */
/*   Updated: 2025/04/25 22:56:26 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/entities/actor.h"
#include "cub3d.h"

void	actor_move(struct s_actor *self, int dir, int modifier)
{
	int		speed;
	double	frametime;

	frametime = ((t_gameenv *)self->base->scene->env)->frametime;
	speed = 18;
	if (modifier == MOVE_WALK)
		speed = 6;
	else if (modifier == MOVE_SPEED && self->entity->b_isground)
		speed = 45;
	if (dir == 0)
	{
		self->entity->velocity.x -= speed * frametime;
		self->direction = -1;
	}
	else if (dir == 1)
	{
		self->entity->velocity.x += speed * frametime;
		self->direction = 1;
	}
	else if (dir == 2 && self->entity->b_isground)
		self->entity->velocity.y += 350 * frametime;
}
