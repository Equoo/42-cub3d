/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:24:40 by dderny            #+#    #+#             */
/*   Updated: 2025/11/01 02:24:38 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <mlx.h>
# include <mlx_int.h>

# include "classes/core/viewport.h"
# include "classes/core/engine.h"
# include "types/vector2.h"

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

/** INHERIT viewport **/
typedef struct s_window t_window;
struct s_window
{
	union {
		t_object	object;
		t_node	node;
		t_viewport	viewport;
		struct {
	t__xgarbage	*garbage;
	char		**base_classes;
	char		*class_name;
	uint32_t	id;

	void	*(*free)(t_window *self);
	int		(*_destruct)(t_window *self);
	int		(*_notification)(t_window *self, int type, void *data);
	char	*(*_to_string)(t_window *self);
	int		(*notify)(t_window *self, int type, void *data);
	int		(*is_class)(t_window *self, char *classn);
	char	*name;
	t_node	**childs;
	int		phys_interpolation;

	int		(*queue_free)(t_window *self);
	int		(*_enter_tree)(t_window *self);
	int		(*_exit_tree)(t_window *self);
	int		(*_process)(t_window *self, float delta);
	int		(*_physics_process)(t_window *self, float delta);
	struct s_scenetree	*(*get_tree)(t_window *self);
	void	(*print_tree)(t_window *self);
	t_node	*(*get_parent)(t_window *self);
	int		(*reparent)(t_window *self, t_node *new_parent, int keep_transform);
	int		(*add_togroup)(t_window *self, char *group);
	int		(*rm_fromgroup)(t_window *self, char *group);
	int		(*add_child)(t_window *self, t_node *child);
	int		(*rm_child)(t_window *self, size_t child);
	t_mat2		canvas_transform;
	t_debugdraw	debug_draw;
	int			gui_disable_input;

	t_camera3d	(*get_camera3d)(t_window *self);
	t_vec2		(*get_mousepos)(t_window *self);
		};
	};
	void		*mlx;
	void		*mlx_win;
	t_engine	*engine;
	int			width;
	int			height;

	// int		(*resize)(t_window *self, t_vec2 new_size);
};

int			window_on_destroy(t_window *self, int (*func)());

t_window		*window_new(t_engine *engine);
int			window_construct(t_window *self, t_engine *engine);
int			window_destruct(t_window *self);

#endif
