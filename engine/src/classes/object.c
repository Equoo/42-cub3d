/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:12:19 by dderny            #+#    #+#             */
/*   Updated: 2025/11/02 04:34:58 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include <stddef.h>
#include <stdlib.h>
#include <libft.h>
#include <ft_vector.h>
#include "classes/object.h"

char	*object_to_string(t_object *self)
{
	char	buffer[64];

	if (ft_snprintf(buffer, 63, "%s[%d]", self->class_name, self->id) == -1)
		return (NULL);
	return (ft_strdup(buffer));
}

int				object_is_class(t_object *self, char *classn)
{
	size_t	i;
	size_t	size;

	size = vec_size(self->base_classes);
	i = 0;
	while (i < size)
	{
		if (ft_strcmp(self->base_classes[i], classn) == 0)
			return (1);
		i++;
	}
	return (0);
}

int				object_construct(t_object *self)
{
	static id_t	last_id = 0;

	self->free = &object_free;
	self->_destruct = &object_destruct;
	self->_to_string = &object_to_string;
	self->is_class = &object_is_class;
	self->base_classes = vec_new(self->garbage, sizeof(char *), 4);
	if (!self->base_classes)
		return (1);
	self->class_name = "object";
	if (!vec_append((t_vec *)&self->base_classes, &self->class_name))
		return (1);
	self->id = last_id;
	last_id++;
	return (0);
}

int			object_destruct(t_object *self)
{
	if (self->base_classes)
		vec_free(&self->base_classes);
	return (0);
}

void			*object_free(t_object *self)
{
	if (self->_destruct)
		self->_destruct(self);
	ft_free(self);
	return (NULL);
}

