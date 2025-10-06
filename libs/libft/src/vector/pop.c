/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:50:30 by dderny            #+#    #+#             */
/*   Updated: 2025/05/08 17:11:29 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vec	vec_pop(t_vec *vector)
{
	t_vec_header	*header;
	void			*element;

	if (!vector || !*vector)
		return (NULL);
	header = _vec_header(*vector);
	if (header->size == 0)
		return (NULL);
	element = header->data + (header->size - 1) * header->type_size;
	header->size--;
	return (element);
}
