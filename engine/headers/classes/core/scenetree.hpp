/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenetree.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:24:40 by dderny            #+#    #+#             */
/*   Updated: 2025/11/01 03:10:51 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENETREE_H
# define SCENETREE_H

# include "classes/object.h"
# include "classes/core/node.h"
# include "classes/core/window.h"

/** INHERIT object **/
typedef struct s_scenetree t_scenetree;
struct s_scenetree
{
	t_window	root;
	t_node		cur_scene;
	int			phys_interpolation;

	int		(*_finalize)(t_self *self);
	int		(*_initialize)(t_self *self);
	int		(*_physics_process)(t_self *self, float delta);
	int		(*_process)(t_self *self, float delta);
	int		(*notify_group)(t_self *self, char *group, int type, void *data);
	int		(*queue_delete)(t_self *self, t_object obj);
};

t_scenetree		*scenetree_new();
int			scenetree_construct(t_scenetree *self);
int			scenetree_destruct(t_scenetree *self);

#endif
