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
	t_vec3	pos;
	t_vec3	rot;
	
	int		(*set_pos)(t_self *self, t_vec3 pos);
};

t_node		*node3d_new();
int			node3d_construct(t_node3d *self);
int			node3d_destruct(t_node3d *self);

#endif
