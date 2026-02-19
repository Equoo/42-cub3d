/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 06:31:54 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/19 20:03:23 by zsonie           ###   ########lyon.fr   */
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

static int	texture_path_assign(char *line, t_map *map, int valid[])
{
	int		i;
	int		len;
	char	*tex_path;

	if (ft_strncmp(line, MAP_NORTH, 3) == 0 || ft_strncmp(line, MAP_WEST,
			3) == 0 || ft_strncmp(line, MAP_SOUTH, 3) == 0 || ft_strncmp(line,
			MAP_EAST, 3) == 0)
	{
		i = 3;
		while (line[i] == ' ')
			i++;
		tex_path = ft_strdup(&line[i]);
		if (!tex_path)
			return (1);
		len = ft_strlen(tex_path);
		if (len > 0 && tex_path[len - 1] == '\n')
			tex_path[len - 1] = '\0';
		check_textures(tex_path, line, map, valid);
	}
	else if (ft_strncmp(line, MAP_FLOOR, 2) == 0 || ft_strncmp(line, MAP_CEILING, 2) == 0)
	{
		/* floor/ceiling: do not allocate a texture path, just parse colors */
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
	line = get_next_line(fd);
	while (line)
	{
		texture_path_assign(line, map, valid);
		free(line);
		line = get_next_line(fd);
	}
	i = -1;
	while (++i < 6)
	{
		if (valid[i] != 1)
		{
			perror("Error");
			i = -1;
			while (++i < 4)
			{
				if (map->tex_paths[i])
				{
					free(map->tex_paths[i]);
					map->tex_paths[i] = NULL;
				}
			}
			return (0);
		}
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
