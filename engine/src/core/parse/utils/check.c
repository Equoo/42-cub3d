/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 08:24:12 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/23 08:32:12 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "core/parse.h"

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_map_line(char *line)
{
	return (line[0] == '0' || line[0] == '1' || line[0] == ' ');
}

int	is_identifier_line(char *line)
{
	return (ft_strncmp(line, TEX_NORTH, 3) == 0
		|| ft_strncmp(line, TEX_SOUTH, 3) == 0
		|| ft_strncmp(line, TEX_WEST, 3) == 0
		|| ft_strncmp(line, TEX_EAST, 3) == 0
		|| ft_strncmp(line, COL_FLOOR, 2) == 0
		|| ft_strncmp(line, COL_CEILING, 2) == 0);
}
