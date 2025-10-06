/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:39:23 by dderny            #+#    #+#             */
/*   Updated: 2025/04/02 20:51:14 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	int		len;
	long	nb;
	char	*str;

	len = 0;
	if (n < 0 || !n)
		len++;
	nb = n;
	while (nb && ++len)
		nb /= 10;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	nb = (long)n;
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while ((n && nb && len--) || (!n && len--))
	{
		str[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
