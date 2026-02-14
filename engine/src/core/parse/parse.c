/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:06:36 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/14 07:10:20 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/parse.h"
#include "core/world.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

static int	texture_path_assign(char *line, t_map *map, int valid[])
{
	int		i;
	char	*tex_path;

	if (ft_strncmp(line, MAP_NORTH, 3) == 0 || ft_strncmp(line, MAP_WEST,
			3) == 0 || ft_strncmp(line, MAP_SOUTH, 3) == 0 || ft_strncmp(line,
			MAP_EAST, 3) == 0 || ft_strncmp(line, MAP_FLOOR, 2) == 0
		|| ft_strncmp(line, MAP_CEILING, 2) == 0)
	{
		i = 3;
		while (line[i] == ' ')
			i++;
		tex_path = ft_strdup(&line[i]);
		check_textures(tex_path, line, map, valid);
		check_floor_and_ceiling(line, map, valid);
	}
	else
		return 1;
	return (0);
}

static int check_textures_and_colors(int fd, t_map *map)
{
	int		valid[6];
	int		i;
	char	*line;

	i = -1;
	while (++i < 6)
		valid[i] = 0;
	while ((line = get_next_line(fd)) != 0)
		texture_path_assign(line, map, valid);
	free(line);
	close(fd);
	i = -1;
	while (++i < 6)
	{
		if (valid[i] != 1)
		{
			perror("Error\nWrong parse");
			return 0;
		}
	}
	return 1;
}

static int assign_map(int fd, t_map *map)
{
	char *line;
	char *result;

	result = "";
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '0' || line[0] == '1' || line[0] == ' ')
			result = ft_strjoin(result, line);
		line = get_next_line(fd);
		if (!line)
			free(line);
	}
	map->cells = result;
	ft_printf("map->cells=\n %s\n", map->cells);
	return 1;
}

static int secure_open(char *path)
{
	int fd;
	
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free(path);
		close(fd);
		perror("Error\n");
		return (-1);
	}
	return fd;
}

int	check_map_validity(char *map_name, t_map *map)
{
	int		fd;
	char	*path;

	if (!suffix_format_checker(map_name, MAP_FORMAT))
		return (0);
	path = ft_strjoin(MAP_FOLDER, map_name);
	if (!path)
	{
		free(path);
		return (0);
	}
	fd = secure_open(path);
	if (fd == -1)
		return -1;
	if (!check_textures_and_colors(fd,map))
		return 0;
	close(fd);
	fd = secure_open(path);
	if (fd == -1)
		return -1;
	assign_map(fd, map);
	close(fd);
	return (1);
}
