/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node3d.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:24:40 by dderny            #+#    #+#             */
/*   Updated: 2025/11/01 03:14:28 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE3D_H
# define NODE3D_H

# include "types/vector3.h"
# include "classes/core/node.h"

/** INHERIT node **/
typedef struct s_node3d t_node3d;
struct s_node3d
{
	t_vec3	gpos;
	t_vec3	grot;
	t_vec3	gscale;
	t_vec3	pos;
	t_vec3	rot;
	t_vec3	scale;
	int		top_level;
	int		visible;
	
	int		(*gtranslate)(t_self *self, t_vec3 offset);
	int		(*grotate)(t_self *self, t_vec3 axis, float angle);
	int		(*gscaled)(t_self *self, t_vec3 offset);
	int		(*translate)(t_self *self, t_vec3 offset);
	int		(*rotate)(t_self *self, t_vec3 axis, float angle);
	int		(*scaled)(t_self *self, t_vec3 offset);
};

t_node3d		*node3d_new();
int			node3d_construct(t_node3d *self);
int			node3d_destruct(t_node3d *self);

#endif
