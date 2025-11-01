/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node2d.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:24:40 by dderny            #+#    #+#             */
/*   Updated: 2025/11/01 01:48:51 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE2D_H
# define NODE2D_H

# include "types/mat2.h"
# include "classes/core/node.h"

/** INHERIT node **/
typedef struct s_node2d t_node2d;
struct s_node2d
{
	union {
		t_object	object;
		t_node	node;
		struct {
	char		**base_classes;
	char		*class_name;
	uint32_t	id;

	void	*(*free)(t_node2d *self);
	int		(*_destruct)(t_node2d *self);
	int		(*_notification)(t_node2d *self, int type, void *data);
	char	*(*_to_string)(t_node2d *self);
	int		(*notify)(t_node2d *self, int type, void *data);
	int		(*is_class)(t_node2d *self, char *classn);
	char	*name;
	t_node	**childs;
	int		phys_interpolation;

	int		(*queue_free)(t_node2d *self);
	int		(*_enter_tree)(t_node2d *self);
	int		(*_exit_tree)(t_node2d *self);
	int		(*_process)(t_node2d *self, float delta);
	int		(*_physics_process)(t_node2d *self, float delta);
	struct s_scenetree	*(*get_tree)(t_node2d *self);
	void	(*print_tree)(t_node2d *self);
	t_node	*(*get_parent)(t_node2d *self);
	int		(*reparent)(t_node2d *self, t_node *new_parent, int keep_transform);
	int		(*add_togroup)(t_node2d *self, char *group);
	int		(*rm_fromgroup)(t_node2d *self, char *group);
	int		(*add_child)(t_node2d *self, t_node *child);
	int		(*rm_child)(t_node2d *self, size_t child);
		};
	};
	t_mat2	transform;
	int		z_index;

	int		(*_draw)(t_node2d *self);
	int		(*rotate)(t_node2d *self, float angle);
	int		(*translate)(t_node2d *self, t_vec2 offest);
};

t_node2d	*node2d_new();
int			node2d_construct(t_node2d *self);
int			node2d_destruct(t_node2d *self);

int			node2d_draw(t_node2d *self);

#endif
