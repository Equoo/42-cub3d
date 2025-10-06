/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:11:45 by dderny            #+#    #+#             */
/*   Updated: 2025/05/08 17:11:53 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_vector.h"

t_vec	vec_insert(t_vec *vector, size_t index, void *element)
{
	t_vec_header	*header;
	size_t			new_capacity;

	if (!vector || !*vector)
		return (NULL);
	header = _vec_header(*vector);
	if (index > header->size)
		return (NULL);
	if (header->size >= header->capacity)
	{
		new_capacity = header->capacity * 2;
		header = ft_xrealloc(header, new_capacity, ALLOC_VECTOR);
		if (!header)
			return (NULL);
		*vector = header->data;
	}
	ft_memmove(header->data + (index + 1) * header->type_size,
		header->data + index * header->type_size,
		(header->size - index) * header->type_size);
	ft_memcpy(header->data + index * header->type_size, element,
		header->type_size);
	header->size++;
	return (header->data);
}
