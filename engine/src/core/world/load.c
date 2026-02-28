/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 01:16:33 by dderny            #+#    #+#             */
/*   Updated: 2026/02/24 03:18:46 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/world.h"
#include "core/engine.h"

int	load_map(void *mlx, t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (image_from_xpm(mlx, map->tex_paths[i], &map->textures[i]))
			return (1);
		i++;
	}
	if (BONUS)
	{
		if (image_from_xpm(mlx, map->door_tex_path, &map->door_texture))
			return (1);
	}
	return (0);
}
