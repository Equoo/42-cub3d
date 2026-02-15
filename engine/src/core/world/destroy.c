/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 02:47:47 by dderny            #+#    #+#             */
/*   Updated: 2026/02/15 02:57:19 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/world.h"
#include "mlx.h"

int	map_destroy(void *mlx, t_map *map)
{
	int	i;

	if (map->cells)
		free(map->cells);
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
