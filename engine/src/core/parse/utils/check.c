/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 08:24:12 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/24 01:14:40 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/engine.h"
#include "core/parse.h"
#include "libft.h"

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
	if (is_identifier_line(line))
		return (0);
	if (BONUS)
		return (line[0] == '0' || line[0] == '1' || line[0] == 'D'
			|| line[0] == ' ' || is_player_char(line[0]));
	return (line[0] == '0' || line[0] == '1' || line[0] == ' '
		|| is_player_char(line[0]));
}

int	is_identifier_line(char *line)
{
	if (BONUS)
		return (ft_strncmp(line, TEX_NORTH, 3) == 0 || ft_strncmp(line,
				TEX_SOUTH, 3) == 0 || ft_strncmp(line, TEX_WEST, 3) == 0
			|| ft_strncmp(line, TEX_EAST, 3) == 0 || ft_strncmp(line,
				TEX_CLOSED_DOOR, 3) == 0 || ft_strncmp(line, COL_FLOOR, 2) == 0
			|| ft_strncmp(line, COL_CEILING, 2) == 0);
	return (ft_strncmp(line, TEX_NORTH, 3) == 0 || ft_strncmp(line, TEX_SOUTH,
			3) == 0 || ft_strncmp(line, TEX_WEST, 3) == 0 || ft_strncmp(line,
			TEX_EAST, 3) == 0 || ft_strncmp(line, COL_FLOOR, 2) == 0
		|| ft_strncmp(line, COL_CEILING, 2) == 0);
}
