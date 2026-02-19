/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:06:36 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/19 20:03:28 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/engine.h"
#include "core/parse.h"
#include "core/world.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

static void	cleanup_map_resources(t_map *map)
{
	int i;

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

static int	map_format_check(t_map *map, char *line, char **result, int *i)
{
	int		line_len;
	char	*temp;

	if (!line || !line[0])
		return (0);
	if (is_empty_line(line))
	{
		free(line);
		return (0);
	}
	if (line[0] == '0' || line[0] == '1' || line[0] == ' ')
	{
		line_len = ft_strlen(line);
		if (line[line_len - 1] == '\n')
			line[line_len - 1] = '\0';
		
		if (ft_strlen(line) > (unsigned long)map->width)
			map->width = ft_strlen(line);
		
		if (!*result)
		{
			*result = ft_strdup(line);
			if (!*result)
				return (-1);
		}
		else
		{
			temp = ft_strjoin(*result, "\n");
			free(*result);
			if (!temp)
				return (-1);
			*result = ft_strjoin(temp, line);
			free(temp);
			if (!*result)
				return (-1);
		}
		free(line);
		map->cells = *result;
		(*i)++;
		return (0);
	}
	free(line);
	return (0);
}

static int	assign_map(int fd, t_map *map)
{
	char	*line;
	char	*result;
	int		i;

	i = 0;
	result = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (map_format_check(map, line, &result, &i) == -1)
		{
			if (result)
				free(result);
			return (1);
		}
		line = get_next_line(fd);
	}
	if (!result)
	{
		ft_printf("Error: No map found in file\n");
		return (1);
	}
	map->cells = result;
	map->height = i;
	return (0);
}

static char	**duplicate_map_grid(t_map *map)
{
	char	**dup;
	int		i;

	dup = ft_calloc(map->height + 1,sizeof(char *));
	if (!dup)
		return (NULL);
	i = -1;
	while (++i < map->height)
	{
		if (!map->grid[i])
		{
			dup[i] = NULL;
			continue ;
		}
		dup[i] = ft_strdup(map->grid[i]);
		if (!dup[i])
		{
			while (--i >= 0)
				free(dup[i]);
			free(dup);
			return (NULL);
		}
	}
	dup[map->height] = NULL;
	return (dup);
}

static int	check_filled_boundaries_copy(char **map_copy, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < (int)ft_strlen(map_copy[i]))
		{
			if (map_copy[i][j] == 'F')
			{
				if (i == 0 || i == map->height - 1)
					return (ft_printf("Error: Map not properly surrounded - filled area touches edge\n"), 1);
				if (j == 0 || j == (int)ft_strlen(map_copy[i]) - 1)
					return (ft_printf("Error: Map not properly surrounded - filled area touches edge\n"), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_filled_spaces_copy(char **map_copy, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < (int)ft_strlen(map_copy[i]))
		{
			if (map_copy[i][j] == 'F')
			{
				if (j > 0 && map_copy[i][j - 1] == ' ')
					return (ft_printf("Error: Map not properly surrounded - space reached from filled area\n"), 1);
				if (j < (int)ft_strlen(map_copy[i]) - 1 && map_copy[i][j + 1] == ' ')
					return (ft_printf("Error: Map not properly surrounded - space reached from filled area\n"), 1);
				if (i > 0 && j < (int)ft_strlen(map_copy[i - 1]) && map_copy[i - 1][j] == ' ')
					return (ft_printf("Error: Map not properly surrounded - space reached from filled area\n"), 1);
				if (i < map->height - 1 && j < (int)ft_strlen(map_copy[i + 1]) && map_copy[i + 1][j] == ' ')
					return (ft_printf("Error: Map not properly surrounded - space reached from filled area\n"), 1);
			}
		}
	}
	return (0);
}

static int	check_surrounded_with_flood_fill(t_map *map)
{
	char	**map_copy;
	int		result;

	if (!map || !map->grid || map->height <= 0)
		return (1);
	if (map->spawn.y < 0 || map->spawn.y >= map->height)
		return (ft_printf("Error: Invalid player spawn\n"), 1);
	if (map->spawn.x < 0 || map->spawn.x >= (int)ft_strlen(map->grid[(int)map->spawn.y]))
		return (ft_printf("Error: Invalid player spawn\n"), 1);
	map_copy = duplicate_map_grid(map);
	if (!map_copy)
		return (1);
	flood_fill(map_copy, map->width, map->height, (t_vec2){map->spawn.x, map->spawn.y});
	result = 0;
	if (check_filled_boundaries_copy(map_copy, map))
		result = 1;
	if (!result && check_filled_spaces_copy(map_copy, map))
		result = 1;
	free_map_copy(map_copy, map->height);
	return (result);
}

int	check_map_validity(char *map_name, t_map *map)
{
	int		fd;
	char	*path;

	path = NULL;
	if (!map_path_checker(map_name, &path))
		return (1);
	if (secure_open(path, &fd))
	{
		free(path);
		return (1);
	}
	if (!assign_textures_and_colors(fd, map))
	{
		close(fd);
		free(path);
		return (1);
	}
	close(fd);
	if (secure_open(path, &fd))
	{
		free(path);
		return (1);
	}
	if (assign_map(fd, map))
	{
		close(fd);
		free(path);
		return (1);
	}
	close(fd);
	free(path);
	if (possible_char_checker(map) || textures_path_checker(map))
	{
		cleanup_map_resources(map);
		return (1);
	}
	if (build_map_grid(map))
	{
		cleanup_map_resources(map);
		return (1);
	}
	if (check_player_position(map))
	{
		cleanup_map_resources(map);
		return (1);
	}
	if (check_surrounded_with_flood_fill(map))
	{
		cleanup_map_resources(map);
		return (1);
	}
	if (DEBUG)
		map_debug(map);
	return (0);
}
