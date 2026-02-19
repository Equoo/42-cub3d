/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba_from_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:38:05 by dderny            #+#    #+#             */
/*   Updated: 2026/02/19 20:03:23 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "types/rgba.h"
#include <asm-generic/errno.h>
#include <errno.h>

static int	col_from_str(char *str)
{
	char	*endptr;
	int		col;

	errno = 0;
	col = ft_strtoi(str, &endptr, 0);
	if (errno || (*endptr && *endptr != '\n'))
		return (-1);
	if (col > 255 || col < 0)
	{
		errno = EOVERFLOW;
		return (-1);
	}
	return (col);
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
	i = -1;
	while (++i < 3)
	{
		col = col_from_str(cols[i]);
		if (col == -1)
		{
			ft_freearray((void **)cols);
			return (1);
		}
		*out = (t_rgba)(out->rgb | (col << (16 - i * 8)));
	}
	ft_freearray((void **)cols);
	return (0);
}
