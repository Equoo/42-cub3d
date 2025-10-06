/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:47:20 by dderny            #+#    #+#             */
/*   Updated: 2025/05/08 16:49:51 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_vector.h"

int	vec_append(t_vec *vector, void *element)
{
	t_vec_header	*header;
	size_t			new_capacity;

	if (!vector || !*vector)
		return (1);
	header = _vec_header(*vector);
	if (header->size >= header->capacity)
	{
		new_capacity = header->capacity * 2;
		header = ft_xrealloc(header, new_capacity, ALLOC_VECTOR);
		if (!header)
			return (1);
		*vector = header->data;
	}
	ft_memcpy(header->data + header->size * header->type_size, element,
		header->type_size);
	header->size++;
	return (0);
}
