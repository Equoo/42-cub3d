/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 23:23:51 by dderny            #+#    #+#             */
/*   Updated: 2026/02/14 23:23:53 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/engine.h"
#include "core/parse.h"
#include "core/world.h"
#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

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
		if (line[0] == '0' || line[0] == '1' || line[0] == ' ')
		{
			line[ft_strlen(line) - 1] = 0;
			if (ft_strlen(line) > (unsigned long)map->width)
				map->width = ft_strlen(line);
			if (!result)
				result = line;
			else
			{
				result = ft_strjoin(result, line);
				free(line);
			}
			if (map->cells)
				free(map->cells);
			map->cells = result;
			i++;
			if (!result)
				break ;
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	if (!result)
	{
		if (line)
			free(line);
		return (0);
	}
	map->height = i;
	// ft_printf("%d, %d, map->cells=\n %s\n", map->width, map->height,
	// map->cells);
	return (1);
}

int	check_map_validity(char *map_name, t_map *map)
{
	int		fd;
	char	*path;

	if (!map_path_checker(map_name, &path))
		return (1);
	fd = secure_open(path);
	if (fd == -1)
		return (1);
	if (!assign_textures_and_colors(fd, map))
		return (1);
	close(fd);
	fd = secure_open(path);
	if (fd == -1)
		return (1);
	assign_map(fd, map);
	close(fd);
	if (textures_path_checker(map))
		return (1);
	if (DEBUG)
		map_debug(map);
	return (0);
}
