/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:53:46 by dderny            #+#    #+#             */
/*   Updated: 2025/04/02 20:51:14 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <libft.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>

ssize_t	get_newline(char *str)
{
	ssize_t	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] && (unsigned char)str[i] != '\n')
		i++;
	if ((unsigned char)str[i] != '\n')
		return (-1);
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	total;
	char	*str;

	if (!s2)
		return (free(s1), NULL);
	if (!s1)
		return (s2);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	total = s1len + s2len + 1;
	str = malloc(sizeof(char) * total);
	if (!str)
	{
		errno = ENOMEM;
		return (free(s1), free(s2), NULL);
	}
	str[0] = 0;
	ft_strlcpy(str, s1, total);
	ft_strlcpy(str + s1len, s2, s2len + 1);
	free(s1);
	free(s2);
	return (str);
}

size_t	gnl_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!src_len)
		return (0);
	i = 0;
	while (src[i] && i + 1 < n)
	{
		dest[i] = src[i];
		i++;
	}
	if (n)
		dest[i] = 0;
	return (src_len);
}

size_t	gnl_strlen(const char *str)
{
	const char	*const_str;

	if (!str)
		return (0);
	const_str = str;
	while (*const_str != '\0')
		++const_str;
	return (const_str - str);
}

char	*gnl_strdup(const char *s, int len)
{
	char	*cpy;

	if (!len)
		len = ft_strlen(s);
	len++;
	cpy = malloc(sizeof(char) * len);
	if (!cpy)
	{
		errno = ENOMEM;
		return (NULL);
	}
	cpy[0] = 0;
	ft_strlcpy(cpy, s, len);
	return (cpy);
}
