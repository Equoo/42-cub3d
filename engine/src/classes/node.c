/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 03:46:48 by dderny            #+#    #+#             */
/*   Updated: 2025/11/01 04:38:05 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "classes/core/node.h"

int	node_construct(t_node *self)
{
	self->_destruct = &node_destruct;
	self->_to_string = &node_to_string;
	if (object_construct((t_object *)self))
		return (1);
	self->childs = vec_new(sizeof(t_node), 2);
	if (!self->childs)
		return (1);
	return (0);
}

int	node_destruct(t_node *self)
{
	if (self->childs)
		vec_free(self->childs);
	return (0);
}

t_node		*node_new()
{
	t_node	*node;

	node = ft_xcalloc(sizeof(t_node), 0);
	if (!node)
		return (NULL);
	*node = (t_node){0};
	if (node_construct(node))
	{
		node->free(node);
		return (NULL);
	}
	return (node);
}
