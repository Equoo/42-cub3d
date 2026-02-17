/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 06:31:54 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/17 03:42:13 by dderny           ###   ########.fr       */
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
		free(path);
		close(*fd);
		perror("Error\n");
		return (1);
	}
	return (0);
}

int	texture_path_assign(char *line, t_map *map, int valid[])
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
		if (!tex_path)
			return (1);
		check_textures(tex_path, line, map, valid);
		if (check_floor_and_ceiling(line, map, valid))
			return (1);
	}
	else
		return (1);
	return (0);
}

int	assign_textures_and_colors(int fd, t_map *map)
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
			perror("Error\n");
			return (0);
		}
	}
	return (1);
}

void	map_debug(t_map *map)
{
	int	i;

	ft_printf("/-----------------------------------------/\n");
	ft_printf("/----------------MAP-DEBUG----------------/\n");
	ft_printf("/-----------------------------------------/\n");
	ft_printf("map cells:\n%s\n", map->cells);
	ft_printf("width: %d\t height: %d\n", map->width, map->height);
	ft_printf("Ceiling color:\trgb:%x\tr:%d\tg:%d\tb:%d\n", map->ceiling.rgb,
		map->ceiling.r, map->ceiling.g, map->ceiling.b);
	ft_printf("Floor color:\trgb:%x\tr:%d\tg:%d\tb:%d\n", map->floor.rgb,
		map->floor.r, map->floor.g, map->floor.b);
	i = 0;
	while (i < 4)
	{
		ft_printf("tex_paths[%d]: %s\n", i, map->tex_paths[i]);
		i++;
	}
	ft_printf("/-----------------------------------------/\n");
}
