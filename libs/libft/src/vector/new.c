/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:58:34 by dderny            #+#    #+#             */
/*   Updated: 2025/05/12 13:03:24 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

t_vec	vec_new(size_t element_size, size_t initial_capacity)
{
	t_vec_header	*vector;

	if (initial_capacity == 0)
		initial_capacity = 1;
	vector = ft_xcalloc(sizeof(t_vec_header) + initial_capacity * element_size,
			ALLOC_VECTOR);
	if (!vector)
		return (NULL);
	vector->type_size = element_size;
	vector->capacity = initial_capacity;
	vector->size = 0;
	return (vector->data);
}
