/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 23:48:41 by dderny            #+#    #+#             */
/*   Updated: 2025/04/17 11:32:34 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <limits.h>
#include <errno.h>

static int	get_digit(char c, int base)
{
	int	nbr;

	nbr = -1;
	if (ft_isdigit(c))
		nbr = c - '0';
	if (c >= 'a' && c <= 'z')
		nbr = c - 'a' + 10;
	if (c >= 'A' && c <= 'Z')
		nbr = c - 'A' + 10;
	if (nbr < base)
		return (nbr);
	return (-1);
}

static char	*process_start(char *str, int *base, int *sign)
{
	if (*base == 0 && *str == '0' && *(str + 1) == 'x' && str++ && str++)
		*base = 16;
	else if (*base == 0 && *str == '0' && str++)
		*base = 8;
	else if (*base == 0)
		*base = 10;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-' && str++)
		*sign = -1;
	else if (*str == '+')
		str++;
	while (*str && *str == '0')
		str++;
	if (*str && *str != '-' && *str != '+'
		&& get_digit(*str, *base) == -1)
	{
		errno = EINVAL;
		return (NULL);
	}
	return (str);
}

static char	*process_numbers(char *str, long *nbr, int sign, int base)
{
	int		digit;

	digit = get_digit(*str, base);
	while (*str && digit != -1)
	{
		if ((sign == 1 && *nbr > (LONG_MAX - digit) / base)
			|| (sign == -1 && *nbr > (-(LONG_MIN + digit)) / base))
		{
			if (sign == 1)
				*nbr = LONG_MAX;
			else
				*nbr = LONG_MIN;
			errno = ERANGE;
			break ;
		}
		else
			*nbr = *nbr * base + digit;
		digit = get_digit(*++str, base);
	}
	return (str);
}

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	long	nbr;
	int		sign;
	char	*str;

	str = (char *)nptr;
	nbr = 0;
	sign = 1;
	str = process_start(str, &base, &sign);
	if (!str)
	{
		if (endptr)
			*endptr = (char *)nptr;
		return (0);
	}
	str = process_numbers(str, &nbr, sign, base);
	if (endptr)
		*endptr = str;
	nbr *= sign;
	return (nbr);
}
