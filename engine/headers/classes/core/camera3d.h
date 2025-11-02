/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera3d.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:24:40 by dderny            #+#    #+#             */
/*   Updated: 2025/11/01 03:31:48 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA3D_H
# define CAMERA3D_H

# include "classes/core/node3d.h"
# include "types/vector2.h"

/** INHERIT node3d **/
typedef struct s_camera3d t_camera3d;
struct s_camera3d
{
	union {
		t_object	object;
		t_node	node;
		t_node3d	node3d;
		struct {
	t__xgarbage	*garbage;
	char		**base_classes;
	char		*class_name;
	uint32_t	id;

	void	*(*free)(t_camera3d *self);
	int		(*_destruct)(t_camera3d *self);
	int		(*_notification)(t_camera3d *self, int type, void *data);
	char	*(*_to_string)(t_camera3d *self);
	int		(*notify)(t_camera3d *self, int type, void *data);
	int		(*is_class)(t_camera3d *self, char *classn);
	char	*name;
	t_node	**childs;
	int		phys_interpolation;

	int		(*queue_free)(t_camera3d *self);
	int		(*_enter_tree)(t_camera3d *self);
	int		(*_exit_tree)(t_camera3d *self);
	int		(*_process)(t_camera3d *self, float delta);
	int		(*_physics_process)(t_camera3d *self, float delta);
	struct s_scenetree	*(*get_tree)(t_camera3d *self);
	void	(*print_tree)(t_camera3d *self);
	t_node	*(*get_parent)(t_camera3d *self);
	int		(*reparent)(t_camera3d *self, t_node *new_parent, int keep_transform);
	int		(*add_togroup)(t_camera3d *self, char *group);
	int		(*rm_fromgroup)(t_camera3d *self, char *group);
	int		(*add_child)(t_camera3d *self, t_node *child);
	int		(*rm_child)(t_camera3d *self, size_t child);
	t_vec3	gpos;
	t_vec3	grot;
	t_vec3	gscale;
	t_vec3	pos;
	t_vec3	rot;
	t_vec3	scale;
	int		top_level;
	int		visible;
	
	int		(*gtranslate)(t_camera3d *self, t_vec3 offset);
	int		(*grotate)(t_camera3d *self, t_vec3 axis, float angle);
	int		(*gscaled)(t_camera3d *self, t_vec3 offset);
	int		(*translate)(t_camera3d *self, t_vec3 offset);
	int		(*rotate)(t_camera3d *self, t_vec3 axis, float angle);
	int		(*scaled)(t_camera3d *self, t_vec3 offset);
		};
	};
	int		current;
	float	far;
	float	fov;
	float	near;
	
	t_vec3		(*project_position)(t_camera3d *self, t_vec2 screenpos, float zdepth);
};

t_camera3d	*camera3d_new();
int			camera3d_construct(t_camera3d *self);
int			camera3d_destruct(t_camera3d *self);

#endif
