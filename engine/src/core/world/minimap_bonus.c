/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:02:52 by dderny            #+#    #+#             */
/*   Updated: 2026/02/23 16:05:17 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/camera.h"
#include "core/world.h"
#include "core/game.h"
#include "core/draw.h"
#include "types/image.h"
#include "types/vector2.h"
#include <sys/cdefs.h>

void	draw_minimap(t_image *buffer, t_map *map, t_camera camera)
{
	int		i;
	t_vec2	pos;
	t_vec2	map_pos;

	pos = (t_vec2){g_win_width - MMAP_OFFSET - SIZE, MMAP_OFFSET};
	i = 0;
	while (i < SIZE * SIZE)
	{
		if (vec2_dist((t_vec2){pos.x + i % SIZE, pos.y + i / SIZE},
			(t_vec2){pos.x + SIZEHALF, pos.y + SIZEHALF}) > SIZEHALF && ++i)
			continue ;
		map_pos = (t_vec2){(i % SIZE) / ZOOM + camera.pos.x - SIZEHALF / ZOOM,
			i / SIZE / ZOOM + camera.pos.y - SIZEHALF / ZOOM};
		if (!is_inmap(map_pos, map)
			|| map->cells[vec2_index(map_pos, map->width)] == '1')
			draw_pixel(buffer, pos.x + i % SIZE,
				pos.y + i / SIZE, (t_rgba)0xffffffff);
		i++;
	}
	draw_square(buffer, (t_vec2){pos.x + SIZEHALF - MMAP_PLY_SIZE,
		pos.y + SIZEHALF - MMAP_PLY_SIZE},
		(t_vec2){pos.x + SIZEHALF + MMAP_PLY_SIZE,
		pos.y + SIZEHALF + MMAP_PLY_SIZE}, (t_rgba)0xffff0000);
}
