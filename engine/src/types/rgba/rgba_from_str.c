/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba_from_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:38:05 by dderny            #+#    #+#             */
/*   Updated: 2026/02/23 08:55:12 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "core/parse.h"
#include "types/rgba.h"
#include <asm-generic/errno.h>
#include <errno.h>

static int	col_from_str(char *str)
{
	char	*endptr;
	int		col;

	errno = 0;
	col = ft_strtoi(str, &endptr, 10);
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

	if (!valid_rgb_format(str))
	{
		ft_printf(ERR_COLORS_RGB);
		return (1);
	}
	cols = ft_split(str, ',');
	if (!cols)
		return (1);
	if (ft_arraylen((void **)cols) != 3)
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
