/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tick_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 23:44:48 by dderny            #+#    #+#             */
/*   Updated: 2025/04/26 19:56:57 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/element.h"
#include "classes/entities/player.h"
#include "ft_bool.h"
#include "input.h"
#include "libft.h"
#include "render.h"
#include "scene.h"
#include "cub3d.h"
#include "vector2d.h"
#include <X11/X.h>
#include <X11/Xutil.h>
#include <stdlib.h>

void	tick_key(t_player *ply, t_gameenv *env)
{
	int	modifier;

	if (input_ispressed('w', env))
	{
		ply->actor->move(ply->actor, 2, 0);
		ply->base->play_anim(ply->base, "J_2");
		ply->is_jumping = TRUE;
	}
	modifier = MOVE_JOG;
	if (input_isdown(XK_Alt_L, env))
		modifier = MOVE_WALK;
	if (input_isdown(XK_Shift_L, env))
		modifier = MOVE_SPEED;
	if (input_isdown('w', env))
		ply->actor->move(ply->actor, 0, modifier);
	if (input_isdown('a', env))
		ply->actor->move(ply->actor, 1, modifier);
	if (input_isdown('d', env))
		ply->actor->move(ply->actor, 2, modifier);
	if (input_ispressed('s', env))
	{
		ply->actor->move(ply->actor, 3, modifier);
	}
	if (input_ispressed(XK_space, env))
		ply->attack(ply);
}

// NOT MALLOC SAFE
static void	draw_hud(t_gameenv *env, t_scene *scene, char *text)
{
	(void)scene;
    text = ft_itoa(env->smooth_fps);
	if (!text)
		return ;
	draw_text(&env->render, "FPS:", (t_vec2){100, 100}, 32);
	draw_text(&env->render, text, (t_vec2){170, 100}, 32);
	free(text);
}

void	tick_game(t_gameenv *env)
{
	t_scene		*scene;
	t_list		*node;
	t_list		*tmp_node;
	t_element	*node_elem;

	scene = (t_scene *)env->scene;
	tick_key(scene->ply, env);
	node = scene->elements;
	while (node)
	{
		tmp_node = node->next;
		node_elem = (t_element *)node->content;
		if (node_elem->internal_update && scene->ply
			&& (vec3_length(vec3_sub(node_elem->pos,
						cast_element(scene->ply)->pos)) < 2048))
			node_elem->internal_update(node_elem);
		node = tmp_node;
	}
	draw_hud(env, scene, NULL);
}
