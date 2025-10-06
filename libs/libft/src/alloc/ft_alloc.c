/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:02:07 by dderny            #+#    #+#             */
/*   Updated: 2025/05/26 04:19:27 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

void	*ft_xalloc(size_t size, id_t mapid)
{
	t__allocs	*data;
	t__alloc	*tmp;
	void		*ptr;

	data = __get_ft_allocations();
	if (!data->allocations)
		return (NULL);
	if (data->allocations && data->size >= data->capacity)
	{
		data->capacity *= 2;
		tmp = malloc(sizeof(t__alloc) * data->capacity);
		if (!tmp)
			return (NULL);
		ft_memcpy(tmp, data->allocations, sizeof(t__alloc) * data->size);
		free(data->allocations);
		data->allocations = tmp;
	}
	ptr = malloc(size + sizeof(size_t));
	if (!ptr)
		return (NULL);
	*(size_t *)ptr = data->size;
	data->allocations[data->size] = (t__alloc){ptr, size, mapid};
	data->size++;
	return (ptr + sizeof(size_t));
}

void	*ft_alloc(size_t size)
{
	return (ft_xalloc(size, 0));
}
