/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 02:39:53 by dderny            #+#    #+#             */
/*   Updated: 2025/11/01 02:41:15 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

#include "classes/core/node.h"

char	*node_to_string(t_node *self)
{
	char	buffer[64];

	if (ft_snprintf(buffer, 63, "%s[%d][%s]", self->class_name, self->id, self->name) == -1)
		return (NULL);
	return (ft_strdup(buffer));
}
