/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node3d.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:24:40 by dderny            #+#    #+#             */
/*   Updated: 2025/10/30 13:40:35 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE3D_H
# define NODE3D_H

# include <ft_vector.h>
# include <stddef.h>
# include <unistd.h>

# include "types/vector3.h"
# include "classes/nodes/node.h"

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
	int		(*destruct)(t_node3d *self);
	char	*(*to_string)(t_node3d *self);
	int		(*is_class)(t_node3d *self, char *classn);
	t_node	**childs;

	int		(*_enter_tree)(t_node3d *self);
	int		(*_exit_tree)(t_node3d *self);
	int		(*_process)(t_node3d *self, float delta);
	int		(*_physics_process)(t_node3d *self, float delta);
	t_node	(*get_parent)(t_node3d *self);
	int		(*add_togroup)(t_node3d *self, char *group);
	int		(*add_child)(t_node3d *self, t_node *child);
	int		(*rm_child)(t_node3d *self, size_t child);
		};
	};
	t_vec3	pos;
	t_vec3	rot;
	
	int		(*set_pos)(t_node3d *self, t_vec3 pos);
};

t_node		*node3d_new();
int			node3d_construct(t_node3d *self);
int			node3d_destruct(t_node3d *self);

#endif
