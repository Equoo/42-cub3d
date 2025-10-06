/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:41:20 by dderny            #+#    #+#             */
/*   Updated: 2025/04/27 00:57:13 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/entities/player.h"
#include "collisions.h"
#include "scene.h"
#include "texture.h"
#include "libft.h"
#include "cub3d.h"
#include <stdlib.h>
#include <stdint.h>

void	player_del(t_element **self)
{
	t_player	*player;

	player = (t_player *)(*self)->parent;
	actor_del(self);
	if (player)
		free(player);
}

static void	init_plyer(t_player *player)
{
	player->actor->death_anim = "Death_1";
	player->actor->on_die = &player_on_die;
	player->base->anim_coroutine = &player_anim_coroutine;
	player->base->update = &player_update;
	player->attack = &player_attack;
	player->base->class = CLASS_PLAYER;
	player->base->parent = player;
	player->base->del = &player_del;
	player->base->txt_off_pos = (t_vec2){-14, -31};
	player->entity->hull = (t_aabb){{-7, -14}, {7, 0}, {0}, {0}};
}

t_player	*ft_player(t_scene *scene)
{
	t_actor		*actor;
	t_player	*player;

	actor = ft_actor(scene);
	if (!actor)
		return (NULL);
	player = ft_calloc(1, sizeof(t_player));
	if (!player)
	{
		actor->base->del(&actor->base);
		return (NULL);
	}
	player->coins = 0;
	player->base = actor->base;
	player->entity = actor->entity;
	player->actor = actor;
	player->base->texture = ft_texture(&scene->env->render,
			"./textures/cat.xpm");
	if (!player->base->texture)
	{
		player->base->del(&player->base);
		return (NULL);
	}
	init_plyer(player);
	return (player);
}
