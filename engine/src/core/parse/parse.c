/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:06:36 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/15 01:45:49 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/engine.h"
#include "core/parse.h"
#include "core/world.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

static int	map_format_check(t_map *map, char *line, char **result, int *i)
{
	if (line[0] == '0' || line[0] == '1' || line[0] == ' ')
	{
		line[ft_strlen(line) - 1] = 0;
		if (ft_strlen(line) > (unsigned long)map->width)
			map->width = ft_strlen(line);
		if (!*result)
			*result = line;
		else
		{
			*result = ft_strjoin(*result, line);
			free(line);
		}
		if (map->cells)
			free(map->cells);
		map->cells = *result;
		(*i)++;
		if (!result)
			return -1;
	}
	else
		free(line);
	return 0;
}

static int	assign_map(int fd, t_map *map)
{
	char	*line;
	char	*result;
	int		i;

	line = get_next_line(fd);
	i = 0;
	result = NULL;
	while (line)
	{
		if (map_format_check(map, line, &result, &i) == -1)
			break;
		line = get_next_line(fd);
	}
	if (!result)
	{
		if (line)
			free(line);
		return (1);
	}
	map->height = i;
	return (0);
}
static int possible_char_checker(t_map *map)
{
	int i;
	int j;

	i=0;
	while (map->cells[i])
	{
		j=0;
		while (POSSIBLE_CHAR[j])
		{
			ft_printf("possiblechar: %c, currentcell: %c\n", POSSIBLE_CHAR[j], map->cells[i]);
			if (map->cells[i] != POSSIBLE_CHAR[j])
				j++;
			else
				break;
			if (j >= 7)
			{
				ft_printf("Wrong char in map\n");
				return -1;
			}
		}
		i++;
	}
	return 0;
}

int	check_map_validity(char *map_name, t_map *map)
{
	int		fd;
	char	*path;

	if (!map_path_checker(map_name, &path))
		return (1);
	if (secure_open(path, &fd))
		return (1);
	if (!assign_textures_and_colors(fd, map))
		return (1);
	close(fd);
	if (secure_open(path, &fd))
		return (1);
	if (assign_map(fd, map))
		return 1;
	close(fd);
	if (possible_char_checker(map) || textures_path_checker(map))
		return 1;
	if (DEBUG)
		map_debug(map);
	return (0);
}
