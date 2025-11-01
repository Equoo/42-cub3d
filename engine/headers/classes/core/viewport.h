/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:24:40 by dderny            #+#    #+#             */
/*   Updated: 2025/11/01 02:22:02 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWPORT_H
# define VIEWPORT_H

# include "classes/core/node.h"
# include "classes/core/camera3d.h"
# include "types/mat2.h"
# include "types/debugdraw.h"

/** INHERIT node **/
typedef struct s_viewport t_viewport;
struct s_viewport
{
	union {
		t_object	object;
		t_node	node;
		struct {
	char		**base_classes;
	char		*class_name;
	uint32_t	id;

	void	*(*free)(t_viewport *self);
	int		(*_destruct)(t_viewport *self);
	int		(*_notification)(t_viewport *self, int type, void *data);
	char	*(*_to_string)(t_viewport *self);
	int		(*notify)(t_viewport *self, int type, void *data);
	int		(*is_class)(t_viewport *self, char *classn);
	char	*name;
	t_node	**childs;
	int		phys_interpolation;

	int		(*queue_free)(t_viewport *self);
	int		(*_enter_tree)(t_viewport *self);
	int		(*_exit_tree)(t_viewport *self);
	int		(*_process)(t_viewport *self, float delta);
	int		(*_physics_process)(t_viewport *self, float delta);
	struct s_scenetree	*(*get_tree)(t_viewport *self);
	void	(*print_tree)(t_viewport *self);
	t_node	*(*get_parent)(t_viewport *self);
	int		(*reparent)(t_viewport *self, t_node *new_parent, int keep_transform);
	int		(*add_togroup)(t_viewport *self, char *group);
	int		(*rm_fromgroup)(t_viewport *self, char *group);
	int		(*add_child)(t_viewport *self, t_node *child);
	int		(*rm_child)(t_viewport *self, size_t child);
		};
	};
	t_mat2		canvas_transform;
	t_debugdraw	debug_draw;
	int			gui_disable_input;

	t_camera3d	(*get_camera3d)(t_viewport *self);
	t_vec2		(*get_mousepos)(t_viewport *self);
};

t_viewport		*viewport_new();
int			viewport_construct(t_viewport *self);
int			viewport_destruct(t_viewport *self);

#endif
