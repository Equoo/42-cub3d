/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:24:40 by dderny            #+#    #+#             */
/*   Updated: 2025/10/30 13:38:16 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

# include <ft_vector.h>
# include <stddef.h>
# include <unistd.h>

# include "classes/object.h"

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
	int		(*destruct)(t_node *self);
	char	*(*to_string)(t_node *self);
	int		(*is_class)(t_node *self, char *classn);
		};
	};
	t_node	**childs;

	int		(*_enter_tree)(t_node *self);
	int		(*_exit_tree)(t_node *self);
	int		(*_process)(t_node *self, float delta);
	int		(*_physics_process)(t_node *self, float delta);
	t_node	(*get_parent)(t_node *self);
	int		(*add_togroup)(t_node *self, char *group);
	int		(*add_child)(t_node *self, t_node *child);
	int		(*rm_child)(t_node *self, size_t child);
};

t_node		*node_new();
int			node_construct(t_node *self);
int			node_destruct(t_node *self);

int			node_add_child(t_node *self, t_node *child);
int			node_rm_child(t_node *self, size_t child);

#endif
