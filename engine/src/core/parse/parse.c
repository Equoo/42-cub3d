/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:06:36 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/20 04:00:33 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/engine.h"
#include "core/parse.h"
#include "core/world.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

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
	if (check_possible_char(map) || textures_path_checker(map))
	{
		cleanup_map_resources(map);
		return (1);
	}
	if (build_map_grid(map))
	{
		cleanup_map_resources(map);
		return (1);
	}
	if (assign_player_pos(map))
	{
		ft_printf("Error: player_count != 1 in the map\n");
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
