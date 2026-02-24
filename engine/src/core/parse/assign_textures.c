/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 00:00:00 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/24 04:08:52 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/engine.h"
#include "core/parse.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include <errno.h>

void	check_textures(char *tex_path, char *line, t_map *map, int valid[])
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

int	check_floor_and_ceiling(char *line, t_map *map, int valid[])
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

static int	assign_paths(char *line, t_map *map, int valid[])
{
	int		i;
	int		len;
	char	*tex_path;

	if (BONUS)
		return (texture_path_assign_bonus(line, map, valid));
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
		len = ft_strlen(tex_path);
		if (len > 0 && tex_path[len - 1] == '\n')
			tex_path[len - 1] = '\0';
		check_textures(tex_path, line, map, valid);
		return (0);
	}
	if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		return (check_floor_and_ceiling(line, map, valid));
	return (0);
}

static int	handle_line(char *line, t_map *map, int valid[], int *map_started)
{
	if (!is_empty_line(line) && is_map_line(line))
	{
		if (!valid_properties(valid))
			return (properties_err(line, valid));
		*map_started = 1;
	}
	else if (!is_empty_line(line) && (*map_started
			|| !is_identifier_line(line)))
	{
		if (*map_started)
			ft_printf(ERR_MAP_LAST);
		else
			ft_printf(ERR_UNKNOWN_ID);
		free(line);
		return (0);
	}
	if (!*map_started && assign_paths(line, map, valid))
	{
		free(line);
		return (0);
	}
	free(line);
	return (-1);
}

int	assign_textures_and_colors(int fd, t_map *map)
{
	int		valid[6];
	char	*line;
	int		map_started;
	int		ret;

	errno = 0;
	map_started = 0;
	ft_bzero(valid, sizeof(valid));
	while (get_next_line(fd, &line) != -1 && line)
	{
		ret = handle_line(line, map, valid, &map_started);
		if (ret != -1)
			return (ret);
	}
	if (!valid_properties(valid))
		return (properties_err(NULL, valid));
	return (1);
}
