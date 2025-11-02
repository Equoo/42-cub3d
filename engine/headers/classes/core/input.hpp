/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:24:40 by dderny            #+#    #+#             */
/*   Updated: 2025/11/01 05:19:25 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "classes/object.h"
#include <sys/types.h>

typedef enum {
	MOUSE_MODE_VISIBLE,
	MOUSE_MODE_HIDDEN,
	MOUSE_MODE_CAPTURED,
	MOUSE_MODE_CONFINED,
	MOUSE_MODE_CONFINED_HIDDEN
}		t_mousemode;

/** INHERIT object **/
typedef struct s_input t_input;
struct s_input
{
	t_mousemode	mousemode;
	
	int		(*is_keypressed)(t_self *self, uint keycode);
	int		(*is_keydown)(t_self *self, uint keycode);
	int		(*is_keyreleased)(t_self *self, uint keycode);
	int		(*is_anythingpressed)(t_self *self);
};

t_input		*input_new();
int			input_construct(t_input *self);
int			input_destruct(t_input *self);

#endif
