/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:00:07 by dderny            #+#    #+#             */
/*   Updated: 2025/04/02 20:51:14 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	const char		*a;
	const size_t	*w;

	a = str;
	while ((uintptr_t)str % sizeof(size_t))
	{
		if (!*str)
			return (str - a);
		str++;
	}
	w = (const void *)str;
	while (!(((*w) - 0x0101010101010101) & ~(*w) & 0x8080808080808080))
		w++;
	str = (const void *)w;
	while (*str)
		str++;
	return (str - a);
}
