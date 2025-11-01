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
	t_mat2	transform;
	int		z_index;

	int		(*_draw)(t_self *self);
	int		(*rotate)(t_self *self, float angle);
	int		(*translate)(t_self *self, t_vec2 offest);
};

t_node2d	*node2d_new();
int			node2d_construct(t_node2d *self);
int			node2d_destruct(t_node2d *self);

int			node2d_draw(t_node2d *self);

#endif
