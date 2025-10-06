/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:07:42 by dderny            #+#    #+#             */
/*   Updated: 2025/04/02 20:51:14 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	j = 0;
	srclen = ft_strlen(src);
	if (!n)
		return (srclen);
	while (dest[i])
		i++;
	destlen = i;
	if (destlen >= n)
		return (srclen + n);
	while (src[j] && i + 1 < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
	return (destlen + srclen);
}
