/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 04:47:45 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/19 21:06:24 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/parse.h"
#include "ft_printf.h"

void	map_debug(t_map *map)
{
	int	i;

	ft_printf("/-----------------------------------------/\n");
	ft_printf("/----------------MAP-DEBUG----------------/\n");
	ft_printf("/-----------------------------------------/\n");
	ft_printf("map cells:\n%s\n", map->cells);
	ft_printf("width: %d\t height: %d\n", map->width, map->height);
	ft_printf("Ceiling color:\trgb:%x\tr:%d\tg:%d\tb:%d\n", map->ceiling.rgb,
		map->ceiling.r, map->ceiling.g, map->ceiling.b);
	ft_printf("Floor color:\trgb:%x\tr:%d\tg:%d\tb:%d\n", map->floor.rgb,
		map->floor.r, map->floor.g, map->floor.b);
	i = 0;
	while (i < 4)
	{
		ft_printf("tex_paths[%d]: %s\n", i, map->tex_paths[i]);
		i++;
	}
	ft_printf("/-----------------------------------------/\n");
}
