/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:29:33 by dderny            #+#    #+#             */
/*   Updated: 2025/04/02 20:51:14 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					digits;
	unsigned long long	res;
	int					negative;

	i = 0;
	res = 0;
	negative = 1;
	digits = 0;
	while (str[i] && str[i] != '-' && str[i] != '+' && !ft_isdigit(str[i]))
		if (++i && !ft_isspace(str[i - 1]))
			return (res);
	if (str[i] == '-' && ++i)
		negative *= -1;
	if (str[i] == '+' && negative == 1)
		i++;
	while (str[i] && str[i] == '0')
		i++;
	while (str[i] && ft_isdigit(str[i]) && ++digits)
		res = res * 10 + (int)(str[i++] - '0');
	if (negative == -1 && (res > __LONG_LONG_MAX__ || digits > 19))
		res = 0;
	if (negative == 1 && (res > __LONG_LONG_MAX__ || digits > 19))
		res = -1;
	return ((int)res * negative);
}
