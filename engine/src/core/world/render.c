/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:02:12 by dderny            #+#    #+#             */
/*   Updated: 2026/02/24 04:07:21 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/camera.h"
#include "core/engine.h"
#include "core/world.h"
#include "libft.h"
#include "math/algorithm.h"
#include "math/extend.h"
#include "types/image.h"
#include "types/vector2.h"
#include <sys/cdefs.h>

static t_image	get_wall_tex(t_map map, t_hit hit)
{
	if (BONUS && hit.cell == 'D')
		return (map.door_texture);
	return (map.textures[hit.dir]);
}

static int	is_cam_in_wall(t_map map, t_camera cam)
{
	t_vec2	pos;
	char	cell;

	pos = (t_vec2){cam.pos.x, cam.pos.y};
	if (!is_inmap(pos, &map))
		return (1);
	cell = map.cells[vec2_index(pos, map.width)];
	return (cell == '1' || cell == ' ');
}

static int	clear_buffer(t_image *buffer, t_map map, t_camera cam)
{
	if (!is_cam_in_wall(map, cam))
		return (0);
	ft_memset(buffer->data, 0, buffer->byte_size);
	return (1);
}

int	draw_walls(t_image *buffer, t_map map, t_camera cam)
{
	const int	rays = (float)buffer->width * RAYS_DENSITY;
	const float	angle_steps = (float)cam.fov / rays;
	float		ray_angle;
	t_hit		hit;
	int			i;

	if (clear_buffer(buffer, map, cam))
		return (0);
	ray_angle = cam.rot.z - (float)cam.fov / 2;
	i = -1;
	while (++i < rays)
	{
		if (i % RAYS_FILLING && ++i)
			continue ;
		ray_angle += angle_steps;
		hit = dda_trace((t_vec2){cam.pos.x, cam.pos.y},
				(t_vec2){cos_lut(ray_angle), sin_lut(ray_angle)}, map);
		draw_wall((t_draw_ctx){buffer, get_wall_tex(map, hit), map, i, 0},
			hit.dist * cos_lut(-(float)cam.fov / 2 + i * angle_steps), hit);
	}
	return (0);
}
