/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 04:47:45 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/23 11:32:42 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/parse.h"
#include "ft_printf.h"

static void	grid_debug_indexes(t_map *map)
{
	int	i;

	i = -1;
	ft_printf("\n[Map->grid]\n-----------\nIndex|");
	while (++i < map->width)
	{
		if (i < 10)
			ft_printf("[0%d]", i);
		else
			ft_printf("[%d]", i);
	}
	ft_printf("\n-----|");
	i = -1;
	while (++i < map->width)
		ft_printf("----", i);
	ft_printf("\n");
}

static void	cells_debug(t_map *map)
{
	int	i;

	ft_printf("\nmap cells:\n----------\n");
	i = -1;
	while (++i < map->width + 2)
		ft_printf("-");
	ft_printf("\n");
	i = -1;
	while (map->cells[++i])
	{
		if (i == 0)
			ft_printf("|");
		if (i % map->width == 0 && i != 0)
			ft_printf("|\n|");
		ft_printf("%c", map->cells[i]);
	}
	ft_printf("|\n");
	i = -1;
	while (++i < map->width + 2)
		ft_printf("-");
	ft_printf("\n");
}

static void	grid_debug(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->grid[++i])
	{
		j = -1;
		if (i < 10)
			ft_printf(" (0%d)|", i);
		else
			ft_printf(" (%d)|", i);
		while (map->grid[i][++j])
			ft_printf(" [%c]", map->grid[i][j]);
		ft_printf("\n");
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
	ft_printf("Width: %d\nHeight: %d\n", map->width, map->height);
	ft_printf("Ceiling color:\trgb:%x\tr:%d\tg:%d\tb:%d\n", map->ceiling.rgb,
		map->ceiling.r, map->ceiling.g, map->ceiling.b);
	ft_printf("Floor color:\trgb:%x\tr:%d\tg:%d\tb:%d\n", map->floor.rgb,
		map->floor.r, map->floor.g, map->floor.b);
	ft_printf("/-----------------------------------------/\n");
	textures_debug(map);
	ft_printf("/-----------------------------------------/\n");
	cells_debug(map);
	ft_printf("/-----------------------------------------/\n");
	grid_debug_indexes(map);
	grid_debug(map);
	ft_printf("/-----------------------------------------/\n");
}
