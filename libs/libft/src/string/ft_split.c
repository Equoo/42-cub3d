/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:08:09 by dderny            #+#    #+#             */
/*   Updated: 2025/04/02 20:51:14 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	split_by(const char *s, char c, char **res)
{
	unsigned int	i;
	unsigned int	j;
	int				count;

	i = 0;
	j = 0;
	count = 0;
	while (s[j])
	{
		j = i;
		while (s[j] && (unsigned char)s[j] != (unsigned char)c)
			j++;
		if (res && (j - i))
		{
			res[count] = ft_substr(s, i, (size_t)(j - i));
			if (!res[count])
				return (-1);
		}
		if (j - i)
			count++;
		i = j + 1;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	char	**splited;

	if (!s)
		return (NULL);
	splited = (char **)ft_calloc(split_by(s, c, NULL) + 1, sizeof(char *));
	if (!splited)
		return (NULL);
	i = 0;
	if (split_by(s, c, splited) == -1)
	{
		while (splited[i])
			free(splited[i++]);
		free(splited);
		return (NULL);
	}
	return (splited);
}
