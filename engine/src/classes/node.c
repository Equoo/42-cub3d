/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 03:46:48 by dderny            #+#    #+#             */
/*   Updated: 2025/10/29 13:53:46 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

#include "classes/nodes/node.h"

int	node_construct(t_node *self)
{
	self->destruct = &node_destruct;
	if (object_construct(self.object))
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

	node = ft_xcalloc(size, 0);
	if (!node)
		return (NULL);
	node = (t_node){0};
	if (node_construct(node))
	{
		node.del(node);
		return (NULL);
	}
	return (node);
}
