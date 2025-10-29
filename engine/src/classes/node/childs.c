/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:53:13 by dderny            #+#    #+#             */
/*   Updated: 2025/10/29 14:30:49 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/nodes/node.h"

int			node_add_child(t_node *self, t_node *child)
{
	return (vec_append(&self->childs, (void *)&child));
}

int			node_rm_child(t_node *self, size_t child)
{
	vec_remove(self->childs, child);
	return (0);
}
