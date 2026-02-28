/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 04:49:03 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/28 19:03:18 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "core/parse.h"

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

static void	free_grid(t_map *map)
{
	int	i;

	if (!map->grid)
		return ;
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

static void	free_tex_paths(t_map *map)
{
	int	i;

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
	if (map->door_tex_path)
	{
		free(map->door_tex_path);
		map->door_tex_path = NULL;
	}
}

void	cleanup_map_resources(t_map *map)
{
	if (!map)
		return ;
	if (map->cells)
	{
		free(map->cells);
		map->cells = NULL;
	}
	free_grid(map);
	free_tex_paths(map);
}
