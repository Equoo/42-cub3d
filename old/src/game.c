/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:18:20 by dderny            #+#    #+#             */
/*   Updated: 2025/04/26 19:57:44 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/element.h"
#include "classes/entities/player.h"
#include "classes/terrain.h"
#include "error.h"
#include "ft_time.h"
#include "ft_vector.h"
#include "libft.h"
#include "scene.h"
#include "cub3d.h"
#include "vector2d.h"
#include <X11/X.h>
#include <X11/Xutil.h>
#include <errno.h>
#include <stdlib.h>

int	load_map(t_gameenv *env, char *path)
{
	t_scene	*scene;
	t_list	*lst_scene;

	scene = ft_scene(env, path);
	if (!scene)
		return (1);
	scene->terrain = ft_terrain(scene, path,
			"./textures/stringstar_fields.xpm");
	lst_scene = ft_lstnew(scene);
	if (!scene->terrain || !lst_scene)
	{
		if (scene->terrain)
			((t_terrain *)scene->terrain)->base->del(
				&((t_terrain *)scene->terrain)->base);
		if (lst_scene)
			free(lst_scene);
		scene_del(scene);
		return (1);
	}
	ft_lstadd_front(&env->scenes_lst, lst_scene);
	env->scene = scene;
	return (0);
}

int	game_init(t_gameenv *env, char *mappath)
{
	t_scene		*scene;
    (void)mappath;
    (void)env;
    //t_terrain	*terrain;
	//t_player	*player;

	if (load_map(env, mappath) || errno)
		return (1);
	scene = (t_scene *)env->scene;
	//player = ft_player(scene);
	//if (!player)
	//	return (1);
	//terrain = (t_terrain *)scene->terrain;
	//player->base->pos = (t_vec3){(terrain->spawn % terrain->w)
	//		* 16, (terrain->spawn / terrain->w) * 16, 0};
	//scene->ply = player;
    env->render.camera = (t_camera){.fov = 90};
	scene->seed = curtime_us();
	return (0);
}
