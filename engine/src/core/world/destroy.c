/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 02:47:47 by dderny            #+#    #+#             */
/*   Updated: 2026/02/28 16:04:34 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/world.h"
#include "mlx.h"

static void	free_map_grid(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}

int	map_destroy(void *mlx, t_map *map)
{
	int	i;

	if (!map)
		return (0);
	if (map->cells)
		free(map->cells);
	if (map->grid)
		free_map_grid(map);
	if (map->sprites)
		free(map->sprites);
	i = 0;
	while (i < 4)
	{
		if (map->tex_paths[i])
			free(map->tex_paths[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (map->textures[i].img)
			mlx_destroy_image(mlx, map->textures[i].img);
		i++;
	}
	return (0);
}
