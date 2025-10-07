/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:46:39 by dderny            #+#    #+#             */
/*   Updated: 2025/04/25 21:18:44 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/terrain.h"
#include "ft_vector.h"
#include "vector2d.h"
#include <fcntl.h>
#include <stddef.h>
#include <sys/types.h>

static int	findpath(t_terrain *map, int *checked, t_2vec2i pos,
	t_vec *queue)
{
	const int	dir[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
	int			i;
	int			x;
	int			y;
    t_2vec2i    tmp;

	i = 0;
	while (i < 4)
	{
		x = pos.a.x + dir[i][0];
		y = pos.a.y + dir[i][1];
		if (((pos.b.x == x && pos.b.y == y) || checked[map->w * y + x]) && ++i)
			continue ;
		checked[map->w * y + x] = 1;
		if (map->grid[map->w * y + x] == MAP_PLAYER)
			return (1);
		if (map->grid[map->w * y + x] != MAP_WALL && map->grid[map->w * y
				+ x] != MAP_EXIT)
		{
			tmp = (t_2vec2i){(t_vec2i){x, y}, pos.a};
            vec_append(queue, &tmp);
		}
		i++;
	}
	return (0);
}

int	terrain_findpath(t_terrain *map, int *checkedmap, t_vec2i pos, t_vec2i last)
{
	t_2vec2i    *queue;
	t_2vec2i	val;
	size_t		i;
	int			res;

	queue = (t_2vec2i *)vec_new(sizeof(t_2vec2i), map->w * map->h);
	if (!queue)
		return (-1);
	queue[0] = (t_2vec2i){pos, last};
	_vec_header(queue)->size = 1;
	res = 0;
	i = -1;
    while (++i < vec_size((t_vec)queue) && !res)
	{
		val = queue[i];
		res = findpath(map, checkedmap, val, (t_vec *)&queue);
	}
	vec_free(queue);
	return (res);
}
