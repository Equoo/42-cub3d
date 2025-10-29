/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:12:19 by dderny            #+#    #+#             */
/*   Updated: 2025/10/29 16:03:30 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>
#include <stdlib.h>
#include <libft.h>
#include <ft_vector.h>
#include "classes/object.h"

char	*object_to_string(t_object *self)
{
	char	buffer[64];
	size_t	end;

	end = ft_strlcpy(buffer, self->class_name, ft_strlen(self->class_name));
	buffer[end] = "[";
	

	str = str_new(self->class_name);
	str_join(str, "[");
	str_join(str, str_fromul(self->id, 10));
	str_join(str, "]");
	return (str);
}

int				object_is_class(t_object *self, t_str class)
{
	size_t	i;
	size_t	size;

	size = vec_size(self->base_classes);
	i = 0;
	while (i < size)
	{
		if (ft_strcmp(self->base_classes[i], class) == 0)
			return (1);
		i++;
	}
	return (0);
}

int				object_construct(t_object *self)
{
	static id_t	last_id = 0;

	self->del = &object_del();
	self->destruct = &object_destruct();
	self->to_string = &object_to_string();
	self->is_class = &object_is_class();
	self->base_classes = vec_new(sizeof(t_str), 4);
	if (!self->base_classes)
		return (1);
	self->class_name = "object";
	if (!vec_append(&self->base_classes, &self->class_name))
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

void			*object_del(t_object *self)
{
	if (self->destruct)
	self->destruct(self);
	free(self);
	return (NULL);
}

