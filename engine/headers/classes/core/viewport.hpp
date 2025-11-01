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
	t_mat2		canvas_transform;
	t_debugdraw	debug_draw;
	int			gui_disable_input;

	t_camera3d	(*get_camera3d)(t_self *self);
	t_vec2		(*get_mousepos)(t_self *self);
};

t_viewport		*viewport_new();
int			viewport_construct(t_viewport *self);
int			viewport_destruct(t_viewport *self);

#endif
