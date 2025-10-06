/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:16:41 by dderny            #+#    #+#             */
/*   Updated: 2025/05/08 17:17:21 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_vector.h"

t_vec	vec_cat(t_vec *a, t_vec *b)
{
	t_vec_header	*header_a;
	t_vec_header	*header_b;
	size_t			new_capacity;

	if (!a || !*a || !b || !*b)
		return (NULL);
	header_a = _vec_header(*a);
	header_b = _vec_header(*b);
	new_capacity = header_a->capacity + header_b->capacity;
	header_a = ft_xrealloc(header_a, new_capacity, ALLOC_VECTOR);
	if (!header_a)
		return (NULL);
	ft_memcpy(header_a->data + header_a->size * header_a->type_size,
		header_b->data, header_b->size * header_b->type_size);
	header_a->size += header_b->size;
	return (header_a->data);
}
