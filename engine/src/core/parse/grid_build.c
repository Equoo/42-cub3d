/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 05:10:10 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/22 08:27:21 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/parse.h"
#include "libft.h"

static int	row_to_grid(t_map *map, int i)
{
	char	*row;

	row = ft_calloc(map->width + 1, sizeof(char));
	if (!row)
		return (1);
	ft_memcpy(row, map->cells + i * map->width, map->width);
	map->grid[i] = row;
	return (0);
}

char	**duplicate_map_grid(t_map *map)
{
	char	**dup;
	int		i;

	dup = ft_calloc(map->height + 1, sizeof(char *));
	if (!dup)
		return (NULL);
	i = -1;
	while (++i < map->height)
	{
		dup[i] = ft_strdup(map->grid[i]);
		if (!dup[i])
		{
			while (--i >= 0)
				free(dup[i]);
			free(dup);
			return (NULL);
		}
	}
	dup[map->height] = NULL;
	return (dup);
}

int	build_map_grid(t_map *map)
{
	int	i;

	map->grid = ft_calloc(map->height + 1, sizeof(char *));
	if (!map->grid)
		return (1);
	i = -1;
	while (++i < map->height)
	{
		if (row_to_grid(map, i))
			return (1);
	}
	map->grid[map->height] = NULL;
	return (0);
}
