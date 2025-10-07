/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:06:41 by dderny            #+#    #+#             */
/*   Updated: 2025/04/27 00:00:52 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "cub3d.h"
# include "vector3d.h"
# include <ft_bool.h>
# include <libft.h>

enum			e_scene
{
	SCENE_GAME,
	SCENE_MENU
};

typedef enum e_class
{
	CLASS_ELEMENT = 1,
	CLASS_ENTITY = 1 << 1,
	CLASS_ACTOR = 1 << 2,
	CLASS_PLAYER = 1 << 3,
	CLASS_FROG = 1 << 4,
	CLASS_EXIT = 1 << 5,
	CLASS_HUD = 1 << 6,
	CLASS_TERRAIN = 1 << 7,
	CLASS_BACKGROUND = 1 << 8
}				t_class;

typedef enum e_cgroup
{
	CGROUP_OTHER = CLASS_ELEMENT | CLASS_BACKGROUND | CLASS_HUD,
	CGROUP_TERRAIN = CLASS_TERRAIN,
	CGROUP_ENTITY = CLASS_ENTITY | CLASS_ACTOR | CLASS_PLAYER | CLASS_FROG |
	CLASS_EXIT,
	CGROUP_ACTOR = CLASS_ACTOR | CLASS_PLAYER | CLASS_FROG,
	CGROUP_ALL = CGROUP_OTHER | CGROUP_TERRAIN | CGROUP_ENTITY | CGROUP_ACTOR
}				t_cgroup;

typedef struct s_scene
{
	t_gameenv	*env;
	char		*name;
	t_list		*elements;
	t_vec3	    cam_pos;
	void		*terrain;
	void		*ply;
	int			seed;
	t_bool		removed;

	void		(*update)(struct s_scene *self);
}				t_scene;

void			scene_del(void *self);
t_scene			*ft_scene(void *env, char *name);

int				scene_add(t_scene *self, void *element);

#endif
