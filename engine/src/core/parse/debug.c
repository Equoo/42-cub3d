/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 04:47:45 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/21 03:10:34 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/parse.h"
#include "ft_printf.h"

static void	properties_debug(t_map *map)
{
	ft_printf("Properties debug:\n");
	ft_printf("spawnX: %f spawnY: %f\n", map->spawn.x, map->spawn.y);
	ft_printf("width: %d\t height: %d\n", map->width, map->height);
	ft_printf("Ceiling color:\trgb:%x\tr:%d\tg:%d\tb:%d\n", map->ceiling.rgb,
		map->ceiling.r, map->ceiling.g, map->ceiling.b);
	ft_printf("Floor color:\trgb:%x\tr:%d\tg:%d\tb:%d\n", map->floor.rgb,
		map->floor.r, map->floor.g, map->floor.b);
}

static void	cells_debug(t_map *map)
{
	int	i;

	ft_printf("\nmap cells:\n");
	i = 0;
	while (map->cells[i])
	{
		if (map->cells[i] == '\n')
			ft_printf(";");
		ft_printf("%c", map->cells[i]);
		i++;
	}
	ft_printf(";\n");
}

static void	grid_debug(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("\nMap->grid:\n");
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			ft_printf("[%c]", map->grid[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

static void	textures_debug(t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		ft_printf("tex_paths[%d]: %s\n", i, map->tex_paths[i]);
		i++;
	}
}

void	map_debug(t_map *map)
{
	ft_printf("/-----------------------------------------/\n");
	ft_printf("/----------------MAP-DEBUG----------------/\n");
	ft_printf("/-----------------------------------------/\n");
	cells_debug(map);
	properties_debug(map);
	grid_debug(map);
	textures_debug(map);
	ft_printf("/-----------------------------------------/\n");
}
