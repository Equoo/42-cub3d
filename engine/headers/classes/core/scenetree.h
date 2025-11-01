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
	union {
		t_object	object;
		struct {
	char		**base_classes;
	char		*class_name;
	uint32_t	id;

	void	*(*free)(t_scenetree *self);
	int		(*_destruct)(t_scenetree *self);
	int		(*_notification)(t_scenetree *self, int type, void *data);
	char	*(*_to_string)(t_scenetree *self);
	int		(*notify)(t_scenetree *self, int type, void *data);
	int		(*is_class)(t_scenetree *self, char *classn);
		};
	};
	t_window	root;
	t_node		cur_scene;
	int			phys_interpolation;

	int		(*_finalize)(t_scenetree *self);
	int		(*_initialize)(t_scenetree *self);
	int		(*_physics_process)(t_scenetree *self, float delta);
	int		(*_process)(t_scenetree *self, float delta);
	int		(*notify_group)(t_scenetree *self, char *group, int type, void *data);
	int		(*queue_delete)(t_scenetree *self, t_object obj);
};

t_scenetree		*scenetree_new();
int			scenetree_construct(t_scenetree *self);
int			scenetree_destruct(t_scenetree *self);

#endif
