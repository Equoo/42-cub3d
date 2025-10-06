/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:12:12 by dderny            #+#    #+#             */
/*   Updated: 2025/05/26 04:19:50 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_xcalloc(size_t size, id_t mapid)
{
	void	*ptr;

	ptr = ft_xalloc(size, mapid);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}
