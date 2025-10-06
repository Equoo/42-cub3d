/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:45:48 by dderny            #+#    #+#             */
/*   Updated: 2025/05/08 16:34:57 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

char	*justifytxt(char *str, int reverse, int len, int *strlen)
{
	char	*res;

	if (!str)
		return (NULL);
	if (len <= *strlen)
		return (str);
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (!reverse)
	{
		ft_memset(res, 32, len - *strlen);
		ft_strlcpy(res + len - *strlen, str, *strlen + 1);
	}
	else
	{
		ft_strlcpy(res, str, len + 1);
		ft_memset(res + *strlen, 32, len - *strlen);
	}
	*strlen = len;
	free(str);
	return (res);
}

char	*ft_strfreejoin(const char *s1, const char *s2, int free1, int free2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (free1)
		free((void *)s1);
	if (free2)
		free((void *)s2);
	if (!str)
		return (NULL);
	return (str);
}

int	m_atoi(char **str)
{
	int					digits;
	unsigned long long	res;

	res = 0;
	digits = 0;
	while (**str && ft_isdigit(**str) && ++digits)
	{
		res = res * 10 + (int)(**str - '0');
		*str = *str + 1;
	}
	return ((int)res);
}

int	printf_error_free(t_pdata data)
{
	if (data.str)
		free(data.str);
	return (-1);
}
