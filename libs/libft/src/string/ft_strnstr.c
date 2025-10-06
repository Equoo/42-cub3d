/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:16:39 by dderny            #+#    #+#             */
/*   Updated: 2025/04/02 20:51:14 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*find)
		return ((char *)str);
	if (!*str || !n)
		return (NULL);
	while (str[i] && i < n)
	{
		j = 0;
		while (i + j < n && find[j]
			&& (unsigned char)str[i + j] == (unsigned char)find[j])
			j++;
		if (!find[j])
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
