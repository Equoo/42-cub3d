/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_coroutine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 23:01:54 by dderny            #+#    #+#             */
/*   Updated: 2025/04/25 20:31:50 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/entities/player.h"
#include "render.h"
#include "vector2d.h"

void	player_anim_coroutine_next(t_player *player)
{
	if (!player->entity->b_isground)
	{
		if (!player->is_jumping)
			player->base->anim = "J_1";
		else
		{
			player->base->anim = "J_3";
			player->base->cycle = 0;
		}
	}
	else if (ft_strcmp(player->base->anim, "Idle_2")
		&& player->base->cycle == 0)
		player->base->anim = "Idle_1";
	else
		player->base->anim = "Idle_2";
}

void	player_anim_coroutine(t_element *self, t_render *render)
{
	t_player	*player;
	float		speed;

	(void)render;
	player = (t_player *)self->parent;
	speed = vec2_length(player->entity->velocity);
	if (player->entity->b_isground && speed <= 1.5 && speed >= 0.05)
	{
		if (ft_strcmp(player->base->anim, "W_1") && player->base->cycle <= 0.1)
			player->base->anim = "W_2";
		else
			player->base->anim = "W_1";
	}
	else if (player->entity->b_isground && speed > 1.5 && speed <= 4)
		player->base->anim = "W_3";
	else if (player->entity->b_isground && speed > 4)
	{
		if (ft_strcmp(player->base->anim, "Run_1")
			&& player->base->cycle <= 0.1)
			player->base->anim = "Run_2";
		else
			player->base->anim = "Run_1";
	}
	else
		player_anim_coroutine_next(player);
}
