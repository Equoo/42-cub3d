/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:06:36 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/22 20:01:07 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/engine.h"
#include "core/parse.h"
#include "core/world.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

static int	load_map_file(char *path, t_map *map)
{
	int	fd;

	if (secure_open(path, &fd))
		return (1);
	if (!assign_textures_and_colors(fd, map))
	{
		close(fd);
		return (1);
	}
	close(fd);
	if (secure_open(path, &fd))
		return (1);
	if (assign_map(fd, map))
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

static int	check_possible_char(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->cells[++i])
	{
		j = 0;
		while (POSSIBLE_CHAR[j])
		{
			if (map->cells[i] != POSSIBLE_CHAR[j])
				j++;
			else
				break ;
			if (j >= 7)
				return (1);
		}
	}
	return (0);
}

static int	validate_map_content(t_map *map)
{
	if (check_possible_char(map) || textures_path_checker(map))
		return (1);
	if (build_map_grid(map))
		return (1);
	if (assign_player_pos(map))
	{
		ft_printf("Error: player_count != 1 in the map\n");
		return (1);
	}
	if (check_surrounded_with_flood_fill(map))
		return (1);
	return (0);
}

int	map_init(char *map_name, t_map *map)
{
	char	*path;

	path = NULL;
	if (!map_path_checker(map_name, &path))
		return (1);
	if (load_map_file(path, map))
	{
		free(path);
		cleanup_map_resources(map);
		return (1);
	}
	free(path);
	if (validate_map_content(map))
	{
		cleanup_map_resources(map);
		return (1);
	}
	if (DEBUG)
		map_debug(map);
	return (0);
}
