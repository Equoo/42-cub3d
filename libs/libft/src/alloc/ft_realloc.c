/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:12:57 by dderny            #+#    #+#             */
/*   Updated: 2025/05/26 04:19:59 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_xrealloc(void *ptr, size_t size, id_t mapid)
{
	void	*new_ptr;

	if (size == 0)
	{
		if (ptr)
			free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (ft_xalloc(size, mapid));
	new_ptr = ft_xalloc(size, mapid);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}

void	*ft_realloc(void *ptr, size_t size)
{
	return (ft_xrealloc(ptr, size, 0));
}
