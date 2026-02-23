/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 08:21:26 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/23 09:08:09 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "core/parse.h"

int properties_err(char *line, int valid[])
{
	if (line)
		free(line);
	if (valid[0] != 1 || valid[1] != 1 || valid[2] != 1
		|| valid[3] != 1)
	{
		ft_printf(ERR_TEXTURE_MISS);
		return (0);
	}
	else if (valid[4] != 1 || valid[5] != 1)
	{
		ft_printf(ERR_COLORS_MISS);
		return (0);
	}
	return (0);
}
