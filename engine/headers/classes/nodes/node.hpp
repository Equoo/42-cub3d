/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:24:40 by dderny            #+#    #+#             */
/*   Updated: 2025/10/29 13:56:20 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

# include <ft_vector.h>
# include <stddef.h>
# include <unistd.h>

# include "classes/object.h"

/** INHERIT object **/
typedef struct s_node t_node;
struct s_node
{
	t_node	**childs;

	int		(*add_child)(t_self *self, t_node *child);
	int		(*rm_child)(t_self *self, size_t child);
};

t_node		*node_new();
int			node_construct(t_node *self);
int			node_destruct(t_node *self);

int			node_add_child(t_node *self, t_node *child);
int			node_rm_child(t_node *self, size_t child);

#endif
