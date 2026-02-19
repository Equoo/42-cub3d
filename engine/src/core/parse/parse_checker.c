/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 03:00:01 by dderny            #+#    #+#             */
/*   Updated: 2026/02/19 06:02:31 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/parse.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"

void	check_textures(char *tex_path, char *line, t_map *map, int valid[])
{
	if (ft_strncmp(line, MAP_NORTH, 3) == 0)
	{
		map->tex_paths[0] = tex_path;
		valid[0]++;
	}
	else if (ft_strncmp(line, MAP_SOUTH, 3) == 0)
	{
		map->tex_paths[1] = tex_path;
		valid[1]++;
	}
	else if (ft_strncmp(line, MAP_WEST, 3) == 0)
	{
		map->tex_paths[2] = tex_path;
		valid[2]++;
	}
	else if (ft_strncmp(line, MAP_EAST, 3) == 0)
	{
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
	if (ft_strncmp(line, MAP_FLOOR, 2) == 0)
	{
		if (rgba_from_str(line + i, &color))
			return (1);
		map->floor = color;
		valid[4]++;
	}
	else if (ft_strncmp(line, MAP_CEILING, 2) == 0)
	{
		if (rgba_from_str(line + i, &color))
			return (1);
		map->ceiling = color;
		valid[5]++;
	}
	return (0);
}

int	check_player_position(t_map *map)
{
	int	i;
	int	player_count;

	i = -1;
	player_count = 0;
	while (++i < map->height)
	{
		int j = -1;
		while (++j < map->width && map->grid[i][j])
		{
			if (map->grid[i][j] == 'N' || map->grid[i][j] == 'S' 
				|| map->grid[i][j] == 'E' || map->grid[i][j] == 'W')
			{
				player_count++;
				map->spawn.x = j;
				map->spawn.y = i;
			}
		}
	}
	if (player_count != 1)
	{
		ft_printf("Error: player_count != 1 in the map\n");
		return (1);
	}
	return (0);
}

int	possible_char_checker(t_map *map)
{
	int	specific;
	int	i;
	int	j;

	i = -1;
	specific = 0;
	while (map->cells[++i])
	{
		if (map->cells[i] == '\n')
			continue ;
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
