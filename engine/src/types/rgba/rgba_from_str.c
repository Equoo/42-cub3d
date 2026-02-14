/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba_from_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:38:05 by dderny            #+#    #+#             */
/*   Updated: 2026/02/14 18:20:06 by dderny                  ###   ########   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "types/rgba.h"
#include <asm-generic/errno.h>
#include <errno.h>
#include <stdlib.h>

static int	col_from_str(char *str)
{
	char	*endptr;
	int		col;

	errno = 0;
	col = ft_strtoi(str, &endptr, 0);
	if (errno || *endptr)
		return (-1);
	if (col > 255)
	{
		errno = EOVERFLOW;
		return (-1);
	}
	return (0);
}

int	rgba_from_str(char *str, t_rgba *out)
{
	char	**cols;
	int		col;
	int		i;

	cols = ft_split(str, ',');
	if (!cols)
		return (1);
	out->rgb = 0;
	if (ft_arraylen((void **)cols) > 3)
	{
		ft_freearray((void **)cols);
		return (1);
	}
	i = 0;
	while (i < 3)
	{
		col = col_from_str(cols[i]);
		if (col == -1)
		{
			ft_freearray((void **)cols);
			return (1);
		}
		*out = (t_rgba)(out->rgb + (col << (28 - i * 4)));
		i++;
	}
	return (0);
}
