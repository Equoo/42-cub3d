/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 00:00:00 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/23 03:53:23 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/parse.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include <errno.h>

static void	check_textures(char *tex_path, char *line, t_map *map, int valid[])
{
	if (ft_strncmp(line, TEX_NORTH, 3) == 0)
	{
		free(map->tex_paths[0]);
		map->tex_paths[0] = tex_path;
		valid[0]++;
	}
	else if (ft_strncmp(line, TEX_SOUTH, 3) == 0)
	{
		free(map->tex_paths[1]);
		map->tex_paths[1] = tex_path;
		valid[1]++;
	}
	else if (ft_strncmp(line, TEX_WEST, 3) == 0)
	{
		free(map->tex_paths[2]);
		map->tex_paths[2] = tex_path;
		valid[2]++;
	}
	else if (ft_strncmp(line, TEX_EAST, 3) == 0)
	{
		free(map->tex_paths[3]);
		map->tex_paths[3] = tex_path;
		valid[3]++;
	}
}

static int	check_floor_and_ceiling(char *line, t_map *map, int valid[])
{
	int		i;
	t_rgba	color;

	i = 2;
	while (line[i] == ' ')
		i++;
	color.rgb = 0;
	if (ft_strncmp(line, COL_FLOOR, 2) == 0)
	{
		if (rgba_from_str(line + i, &color))
			return (1);
		map->floor = color;
		valid[4]++;
	}
	else if (ft_strncmp(line, COL_CEILING, 2) == 0)
	{
		if (rgba_from_str(line + i, &color))
			return (1);
		map->ceiling = color;
		valid[5]++;
	}
	return (0);
}

static int	texture_path_assign(char *line, t_map *map, int valid[])
{
	int		i;
	char	*tex_path;

	if (ft_strncmp(line, TEX_NORTH, 3) == 0 || ft_strncmp(line, TEX_WEST,
			3) == 0 || ft_strncmp(line, TEX_SOUTH, 3) == 0 || ft_strncmp(line,
			TEX_EAST, 3) == 0)
	{
		i = 3;
		while (line[i] == ' ')
			i++;
		tex_path = ft_strdup(&line[i]);
		if (!tex_path)
			return (1);
		if (ft_strlen(tex_path) > 0 && tex_path[ft_strlen(tex_path)
			- 1] == '\n')
			tex_path[ft_strlen(tex_path) - 1] = '\0';
		check_textures(tex_path, line, map, valid);
		return (0);
	}
	if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		return (check_floor_and_ceiling(line, map, valid));
	return (0);
}

static int	all_valid(int valid[])
{
	int	i;

	i = 0;
	while (i < 6 && valid[i] == 1)
		i++;
	return (i == 6);
}

int	assign_textures_and_colors(int fd, t_map *map)
{
	int		valid[6];
	char	*line;

	errno = 0;
	ft_bzero(valid, sizeof(valid));
	while (get_next_line(fd, &line) != -1 && line)
	{
		if (!is_empty_line(line) && is_map_line(line))
		{
			if (!all_valid(valid))
			{
				free(line);
				if (valid[0] > 1 || valid[1] > 1 || valid[2] > 1
					|| valid[3] > 1)
					ft_printf("Error\nPARSING: Too many textures.\n");
				else if (valid[0] < 1 || valid[1] < 1 || valid[2] < 1
					|| valid[3] < 1)
					ft_printf("Error\nPARSING: Not enough textures.\n");
				else if (valid[4] > 1 || valid[5] > 1)
					ft_printf("Error\nPARSING: Too many colors.\n");
				else if (valid[4] < 1 || valid[5] < 1)
					ft_printf("Error\nPARSING: Not enough colors.\n");
				else
					ft_printf("Error\nPARSING: Map should be last.\n");
				return (0);
			}
		}
		if (texture_path_assign(line, map, valid))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	while ((get_next_line(fd, &line) != -1 && line))
		free(line);
	if (!all_valid(valid) || errno)
		return (0);
	return (1);
}
