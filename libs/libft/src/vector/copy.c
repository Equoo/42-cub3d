/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:42:17 by dderny            #+#    #+#             */
/*   Updated: 2025/05/12 13:03:36 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

t_vec	vec_copy(t_vec *vector)
{
	t_vec_header	*new_vector;
	t_vec_header	*old_vector;

	if (!vector || !*vector)
		return (NULL);
	old_vector = _vec_header(*vector);
	new_vector = ft_xalloc(old_vector->capacity * old_vector->type_size,
			ALLOC_VECTOR);
	if (!new_vector)
		return (NULL);
	ft_memcpy(new_vector->data, old_vector->data, old_vector->size
		* old_vector->type_size);
	new_vector->type_size = old_vector->type_size;
	new_vector->capacity = old_vector->capacity;
	new_vector->size = old_vector->size;
	return (new_vector->data);
}
