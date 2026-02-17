/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 01:16:33 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 02:09:18 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/world.h"

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
	return (0);
}
