/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:02:52 by dderny            #+#    #+#             */
/*   Updated: 2026/02/28 16:55:08 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/camera.h"
#include "core/world.h"
#include "core/game.h"
#include "core/draw.h"
#include "types/image.h"
#include "types/vector2.h"
#include <sys/cdefs.h>

static t_rgba	get_cell_color(t_map *map, t_vec2 map_pos)
{
	if (!is_inmap(map_pos, map)
		|| map->cells[vec2_index(map_pos, map->width)] == '1')
		return ((t_rgba)0xffffffff);
	if (map->cells[vec2_index(map_pos, map->width)] == 'D')
		return ((t_rgba)0xffff0000);
	if (map->cells[vec2_index(map_pos, map->width)] == 'O')
		return ((t_rgba)0xff00ff00);
	if (map->cells[vec2_index(map_pos, map->width)] == 'B')
		return ((t_rgba)0xff134f5e);
	return ((t_rgba)0x00000000);
}

static void	draw_minimap_player(t_image *buffer, t_vec2 pos)
{
	draw_square(buffer,
		(t_vec2){pos.x + SIZEHALF - MMAP_PLY_SIZE,
		pos.y + SIZEHALF - MMAP_PLY_SIZE},
		(t_vec2){pos.x + SIZEHALF + MMAP_PLY_SIZE,
		pos.y + SIZEHALF + MMAP_PLY_SIZE}, (t_rgba)0xffff0000);
}

void	draw_minimap(t_image *buffer, t_map *map, t_camera camera, float zoom)
{
	int		i;
	t_vec2	pos;
	t_vec2	map_pos;
	t_rgba	color;

	pos = (t_vec2){g_win_width - MMAP_OFFSET - SIZE, MMAP_OFFSET};
	i = -1;
	while (++i < SIZE * SIZE)
	{
		if (vec2_dist((t_vec2){pos.x + i % SIZE, pos.y + i / SIZE},
			(t_vec2){pos.x + SIZEHALF, pos.y + SIZEHALF}) > SIZEHALF && ++i)
			continue ;
		map_pos = (t_vec2){(i % SIZE) / zoom + camera.pos.x - SIZEHALF / zoom,
			i / SIZE / zoom + camera.pos.y - SIZEHALF / zoom};
		color = get_cell_color(map, map_pos);
		if (color.rgb)
			draw_pixel(buffer, pos.x + i % SIZE, pos.y + i / SIZE, color);
	}
	draw_minimap_player(buffer, pos);
}
