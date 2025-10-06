/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:03:34 by dderny            #+#    #+#             */
/*   Updated: 2025/05/26 04:19:00 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void	*ft_free(void *ptr)
{
	t__allocs	*data;
	size_t		i;

	data = __get_ft_allocations();
	if (!data->allocations)
	{
		free(ptr);
		return (NULL);
	}
	i = *((size_t *)ptr - 1);
	if (i < data->size && data->allocations[i].ptr == ptr - sizeof(size_t))
	{
		free(data->allocations[i].ptr);
		data->allocations[i] = (t__alloc){NULL, 0, 0};
		return (NULL);
	}
	ft_dprintf(STDERR_FILENO,
		"Error: trying to free a pointer that was not allocated by ft_alloc\n");
	free(ptr);
	return (NULL);
}

void	*ft_xfree(id_t mapid)
{
	t__allocs	*data;
	size_t		i;

	data = __get_ft_allocations();
	if (!data->allocations)
		return (NULL);
	i = 0;
	while (i < data->size)
	{
		if (data->allocations[i].ptr && (mapid == 0
				|| data->allocations[i].mapid & mapid))
		{
			free(data->allocations[i].ptr);
			data->allocations[i] = (t__alloc){NULL, 0, 0};
		}
		i++;
	}
	return (NULL);
}

__attribute__((destructor)) void	*garbage_collector(void)
{
	t__allocs	*data;
	size_t		total;
	size_t		i;

	data = __get_ft_allocations();
	if (!data->allocations)
		return (NULL);
	i = 0;
	total = 0;
	while (i < data->size)
	{
		if (!data->allocations[i].ptr && ++i)
			continue ;
		free(data->allocations[i].ptr);
		total += data->allocations[i].size;
		i++;
	}
	free(data->allocations);
	if (total && DEBUG)
		ft_dprintf(STDERR_FILENO, "Warning: total memory leak: %u bytes\n",
			total);
	return (NULL);
}
