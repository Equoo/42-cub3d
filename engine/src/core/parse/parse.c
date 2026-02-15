/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:06:36 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/15 04:08:39 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/engine.h"
#include "core/parse.h"
#include "core/world.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

// static int	rebuild_map(t_map *map)
// {
// }

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
			return (-1);
	}
	else
		free(line);
	return (0);
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
			break ;
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

static int	possible_char_checker(t_map *map)
{
	int	specific;
	int	i;
	int	j;

	i = -1;
	specific = 0;
	while (map->cells[++i])
	{
		j = 0;
		while (POSSIBLE_CHAR[j])
		{
			if (map->cells[i] != POSSIBLE_CHAR[j])
				j++;
			else
			{
				if (POSSIBLE_CHAR[j] == 'N' || POSSIBLE_CHAR[j] == 'S'
					|| POSSIBLE_CHAR[j] == 'W' || POSSIBLE_CHAR[j] == 'E')
					specific++;
				break ;
			}
			if (j >= 7 || specific > 1)
				return (-1);
		}
	}
	return (0);
}

static int	from_start_surrounded_check(t_map *map, int *i, int *x)
{
	if (*x == 0)
	{
		while (map->cells[*i] == ' ')
		{
			(*i)++;
			(*x)++;
		}
		if (map->cells[*i] != '1')
		{
			ft_printf("ERROR: Not surrounded by walls\n");
			return (1);
		}
	}
	return (0);
}
// static int	inside_surrounded_check(t_map *map, int *i, int *x)
// {
// 	if (map->cells[*i] == ' ')
// 	{
// 		if (map->cells[(*i) - 1] != '1')
// 		{
// 			ft_printf("not 1 before\n");
// 			return (1);
// 		}
// 		else
// 		{
// 			while (map->cells[*i] == ' ')
// 			{
// 				(*i)++;
// 				(*x)++;
// 			}
// 			if (map->cells[*i] != '1' || map->cells[*i] != '\n')
// 			{
// 				ft_printf("\noasdasd\n");
// 				return (1);
// 			}
// 		}
// 	}
// 	return (0);
// }

static int	from_end_surrounded_check(t_map *map, int *i, int *x)
{
	if (*x == map->width - 1)
	{
		while (map->cells[*i] == ' ')
		{
			(*i)--;
			(*x)--;
		}
		if (map->cells[*i] != '1')
		{
			ft_printf("ERROR: Not surrounded by walls\n");
			return (1);
		}
		else
		{
			(*i)++;
			(*x)++;
			while (map->cells[*i] == ' ')
			{
				(*i)++;
				(*x)++;
			}
		}
	}
	return (0);
}

static int	is_surrounded_by_walls(t_map *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (map->cells[i])
	{
		x = i % map->width;
		if ((i / (y + 1)) == map->width)
			y++;
		if (from_start_surrounded_check(map, &i, &x))
			return (1);
		// if (inside_surrounded_check(map, &i, &x))
		// 	return (1);
		if (from_end_surrounded_check(map, &i, &x))
			return (1);
		ft_printf("i= %d,x= %d, y= %d, cell[i]=%c\n", i, x, y, map->cells[i]);
		i++;
	}
	return (0);
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
		return (1);
	close(fd);
	if (possible_char_checker(map) || textures_path_checker(map))
		return (1);
	if (is_surrounded_by_walls(map))
		return (1);
	if (DEBUG)
		map_debug(map);
	return (0);
}
