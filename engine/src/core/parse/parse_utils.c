/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 06:31:54 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/20 03:50:40 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/parse.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include "types/rgba.h"

int	secure_open(char *path, int *fd)
{
	*fd = open(path, O_RDONLY);
	if (*fd == -1)
	{
		perror("Error");
		return (1);
	}
	return (0);
}

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

void	free_map_copy(char **dup, int height)
{
	int	i;

	i = -1;
	while (++i < height)
	{
		if (dup[i])
			free(dup[i]);
	}
	free(dup);
}

void	cleanup_map_resources(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->cells)
	{
		free(map->cells);
		map->cells = NULL;
	}
	if (map->grid)
	{
		i = 0;
		while (i < map->height)
		{
			if (map->grid[i])
				free(map->grid[i]);
			i++;
		}
		free(map->grid);
		map->grid = NULL;
	}
	i = 0;
	while (i < 4)
	{
		if (map->tex_paths[i])
		{
			free(map->tex_paths[i]);
			map->tex_paths[i] = NULL;
		}
		i++;
	}
}

int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}
