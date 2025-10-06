/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:19:31 by dderny            #+#    #+#             */
/*   Updated: 2025/05/08 17:19:40 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_vector.h"

void	vec_remove(t_vec vector, size_t index)
{
	t_vec_header	*header;

	if (!vector)
		return ;
	header = _vec_header(vector);
	if (index >= header->size)
		return ;
	ft_memmove(header->data + index * header->type_size,
		header->data + (index + 1) * header->type_size,
		(header->size - index - 1) * header->type_size);
	header->size--;
}
