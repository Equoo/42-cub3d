/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node3d.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:24:40 by dderny            #+#    #+#             */
/*   Updated: 2025/11/01 03:14:28 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE3D_H
# define NODE3D_H

# include "types/vector3.h"
# include "classes/core/node.h"

/** INHERIT node **/
typedef struct s_node3d t_node3d;
struct s_node3d
{
	union {
		t_object	object;
		t_node	node;
		struct {
	char		**base_classes;
	char		*class_name;
	uint32_t	id;

	void	*(*free)(t_node3d *self);
	int		(*_destruct)(t_node3d *self);
	int		(*_notification)(t_node3d *self, int type, void *data);
	char	*(*_to_string)(t_node3d *self);
	int		(*notify)(t_node3d *self, int type, void *data);
	int		(*is_class)(t_node3d *self, char *classn);
	char	*name;
	t_node	**childs;
	int		phys_interpolation;

	int		(*queue_free)(t_node3d *self);
	int		(*_enter_tree)(t_node3d *self);
	int		(*_exit_tree)(t_node3d *self);
	int		(*_process)(t_node3d *self, float delta);
	int		(*_physics_process)(t_node3d *self, float delta);
	struct s_scenetree	*(*get_tree)(t_node3d *self);
	void	(*print_tree)(t_node3d *self);
	t_node	*(*get_parent)(t_node3d *self);
	int		(*reparent)(t_node3d *self, t_node *new_parent, int keep_transform);
	int		(*add_togroup)(t_node3d *self, char *group);
	int		(*rm_fromgroup)(t_node3d *self, char *group);
	int		(*add_child)(t_node3d *self, t_node *child);
	int		(*rm_child)(t_node3d *self, size_t child);
		};
	};
	t_vec3	gpos;
	t_vec3	grot;
	t_vec3	gscale;
	t_vec3	pos;
	t_vec3	rot;
	t_vec3	scale;
	int		top_level;
	int		visible;
	
	int		(*gtranslate)(t_node3d *self, t_vec3 offset);
	int		(*grotate)(t_node3d *self, t_vec3 axis, float angle);
	int		(*gscaled)(t_node3d *self, t_vec3 offset);
	int		(*translate)(t_node3d *self, t_vec3 offset);
	int		(*rotate)(t_node3d *self, t_vec3 axis, float angle);
	int		(*scaled)(t_node3d *self, t_vec3 offset);
};

t_node3d		*node3d_new();
int			node3d_construct(t_node3d *self);
int			node3d_destruct(t_node3d *self);

#endif
