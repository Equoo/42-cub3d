/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:39:55 by dderny            #+#    #+#             */
/*   Updated: 2025/04/02 20:51:14 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start <= slen)
		slen -= start;
	else
		slen = 0;
	if (slen < len || len == SIZE_MAX)
		len = slen;
	len++;
	res = ft_calloc(len, sizeof(char));
	if (!res)
		return (NULL);
	if (slen > 0)
		ft_strlcpy(res, s + start, len);
	return (res);
}
