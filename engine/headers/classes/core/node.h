/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:24:40 by dderny            #+#    #+#             */
/*   Updated: 2025/11/01 02:39:19 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

# include "classes/object.h"

struct s_scenetree;

/** INHERIT object **/
typedef struct s_node t_node;
struct s_node
{
	union {
		t_object	object;
		struct {
	char		**base_classes;
	char		*class_name;
	uint32_t	id;

	void	*(*free)(t_node *self);
	int		(*_destruct)(t_node *self);
	int		(*_notification)(t_node *self, int type, void *data);
	char	*(*_to_string)(t_node *self);
	int		(*notify)(t_node *self, int type, void *data);
	int		(*is_class)(t_node *self, char *classn);
		};
	};
	char	*name;
	t_node	**childs;
	int		phys_interpolation;

	int		(*queue_free)(t_node *self);
	int		(*_enter_tree)(t_node *self);
	int		(*_exit_tree)(t_node *self);
	int		(*_process)(t_node *self, float delta);
	int		(*_physics_process)(t_node *self, float delta);
	struct s_scenetree	*(*get_tree)(t_node *self);
	void	(*print_tree)(t_node *self);
	t_node	*(*get_parent)(t_node *self);
	int		(*reparent)(t_node *self, t_node *new_parent, int keep_transform);
	int		(*add_togroup)(t_node *self, char *group);
	int		(*rm_fromgroup)(t_node *self, char *group);
	int		(*add_child)(t_node *self, t_node *child);
	int		(*rm_child)(t_node *self, size_t child);
};

t_node		*node_new();
int			node_construct(t_node *self);
int			node_destruct(t_node *self);

char		*node_to_string(t_node *self);
int			node_add_child(t_node *self, t_node *child);
int			node_rm_child(t_node *self, size_t child);

#endif
