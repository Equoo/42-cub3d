/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:59:44 by dderny            #+#    #+#             */
/*   Updated: 2025/04/02 20:51:14 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdint.h>
#include <stdlib.h>

char	*convertfloat(double nbr, t_pflag ptype, int *len)
{
	char		*str;
	t_ltoainfo	info;

	info = (t_ltoainfo){{BASE10, 10}, 0, 0, 0, NULL};
	info.zeros = 6;
	if (ptype.atributs[F_PLUS])
		info.sign = '+';
	if (ptype.atributs[F_SPACE])
		info.sign = ' ';
	if (ptype.atributs[F_POINT])
		info.zeronbr = 1;
	if (ptype.atributs[F_ZERO])
		info.zeros = ptype.min;
	if (ptype.atributs[F_POINT])
		info.zeros = ptype.atributs[F_POINT] - 1;
	str = ft_ftoa(nbr, info, len);
	return (str);
}

static int	testfloat(double *nbr)
{
	return (*(long *)nbr >> 63);
}

char	*ft_ftoa(double nbr, t_ltoainfo info, int *strlen)
{
	char	*str;
	char	*strfract;
	int		sign;
	double	fractionnal;
	int		i;

	sign = 1;
	if (testfloat(&nbr))
		sign = -1;
	str = ft_lltoa_base((long)nbr * sign, (t_ltoainfo){{BASE10, 10}, info.sign,
			0, 0, NULL}, strlen);
	strfract = ft_calloc(info.zeros + 3, sizeof(char));
	strfract[0] = '.';
	fractionnal = nbr - (long)nbr;
	i = 0;
	while (i <= info.zeros && ++i)
	{
		fractionnal *= 10;
		strfract[i] = '0' + (int)fractionnal;
		fractionnal -= (int)fractionnal;
	}
	*strlen += i;
	str = ft_strfreejoin(str, strfract, 1, 1);
	return (str);
}
