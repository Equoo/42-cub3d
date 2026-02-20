/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 21:49:24 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/20 19:29:59 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include "core/parse.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"

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

static void	free_tex_paths(t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
		if (map->tex_paths[i])
			free(map->tex_paths[i++]);
		else
			i++;
}

int	assign_textures_and_colors(int fd, t_map *map)
{
	int		valid[6];
	int		i;
	char	*line;

	errno = 0;
	ft_bzero(valid, sizeof(valid));
	while (get_next_line(fd, &line) != -1 && line)
	{
		if (texture_path_assign(line, map, valid))
		{
			free(line);
			free_tex_paths(map);
			return (0);
		}
		free(line);
	}
	i = 0;
	while (i < 6 && valid[i] == 1)
		i++;
	if (i < 6 || errno)
	{
		free_tex_paths(map);
		return (0);
	}
	return (1);
}

int	assign_player_pos(t_map *map)
{
	int	i;
	int	player_count;
	int	j;

	i = -1;
	player_count = 0;
	while (++i < map->height)
	{
		if (!map->grid[i])
			continue ;
		j = -1;
		while (++j < (int)ft_strlen(map->grid[i]))
		{
			if (is_player_char(map->grid[i][j]))
			{
				player_count++;
				map->spawn.x = j;
				map->spawn.y = i;
			}
		}
	}
	if (player_count != 1)
		return (1);
	return (0);
}

int	assign_map(int fd, t_map *map)
{
	char	*line;
	char	*result;
	int		i;

	i = 0;
	result = NULL;
	errno = 0;
	while (get_next_line(fd, &line) != -1 && line)
	{
		if (check_map_format(map, line, &result, &i) == -1)
		{
			if (result)
				free(result);
			return (1);
		}
	}
	if (!result || errno)
	{
		if (!errno)
			ft_printf("Error: No map found in file\n");
		return (1);
	}
	map->cells = result;
	map->height = i;
	return (0);
}
