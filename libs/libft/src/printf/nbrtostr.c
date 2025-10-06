/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrtostr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:58:21 by dderny            #+#    #+#             */
/*   Updated: 2025/04/02 20:51:14 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static int	numberlen(long long n, t_ltoainfo info)
{
	int			len;
	long long	nb;

	len = 0;
	nb = n;
	while (nb && ++len)
		nb /= info.base.len;
	if (info.zeronbr && info.zeros > len)
		len = info.zeros;
	if (!info.zeronbr && !n)
		len++;
	if (info.sign || n < 0)
		len++;
	if (info.prefix && n)
		len += ft_strlen(info.prefix);
	if (!info.zeronbr && info.zeros > len)
		len = info.zeros;
	return (len);
}

static void	addprefix(char *str, long long n, t_ltoainfo info)
{
	int	i;

	if (n)
	{
		i = 0;
		if (n < 0 || info.sign)
			i = 1;
		while (info.prefix && *info.prefix)
		{
			str[i] = *info.prefix;
			info.prefix++;
			i++;
		}
	}
}

char	*ft_lltoa_base(long long n, t_ltoainfo info, int *strlen)
{
	int			len;
	long long	nb;
	char		*str;

	len = numberlen(n, info);
	*strlen = len;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memset(str, info.base.str[0], len);
	nb = n;
	if (nb < 0)
		str[0] = '-';
	if (nb < 0)
		nb *= -1;
	else if (info.sign)
		str[0] = info.sign;
	while (n && nb && len--)
	{
		str[len] = info.base.str[nb % info.base.len];
		nb /= info.base.len;
	}
	if (info.prefix)
		addprefix(str, n, info);
	return (str);
}

static int	unumberlen(unsigned long n, t_ltoainfo info)
{
	int				len;
	unsigned long	nb;

	len = 0;
	nb = n;
	while (nb && ++len)
		nb /= info.base.len;
	if (info.zeronbr && info.zeros > len)
		len = info.zeros;
	if (!info.zeronbr && !n)
		len++;
	if (info.sign)
		len++;
	if (info.prefix && n)
		len += ft_strlen(info.prefix);
	if (!info.zeronbr && info.zeros > len)
		len = info.zeros;
	return (len);
}

char	*ft_ultoa_base(unsigned long n, t_ltoainfo info, int *strlen)
{
	int		len;
	char	*str;

	len = unumberlen(n, info);
	*strlen = len;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memset(str, info.base.str[0], len);
	while (len--)
	{
		str[len] = info.base.str[n % info.base.len];
		n /= info.base.len;
	}
	if (info.sign)
		str[0] = info.sign;
	if (info.prefix)
		addprefix(str, 1, info);
	return (str);
}
