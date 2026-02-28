/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:02:12 by dderny            #+#    #+#             */
/*   Updated: 2026/02/24 14:27:15 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/camera.h"
#include "core/world.h"
#include "core/engine.h"
#include "libft.h"
#include "math/algorithm.h"
#include "math/extend.h"
#include "types/image.h"
#include "types/vector2.h"
#include <sys/cdefs.h>

static int	clear_buffer(t_image *buffer, t_map map, t_camera cam)
{
	if (!is_inmap((t_vec2){cam.pos.x, cam.pos.y}, &map)
		|| map.cells[vec2_index(*(t_vec2 *)&cam.pos, map.width)] == '1'
		|| map.cells[vec2_index(*(t_vec2 *)&cam.pos, map.width)] == ' ')
	{
		ft_memset(buffer->data, 0, buffer->byte_size);
		return (1);
	}
	return (0);
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
	i = 0;
	ray_angle = cam.rot.z - (float)cam.fov / 2;
	while (i < rays)
	{
		if (i % RAYS_FILLING && ++i)
			continue ;
		ray_angle += angle_steps;
		hit = dda_trace((t_vec2){cam.pos.x, cam.pos.y},
				(t_vec2){cos_lut(ray_angle), sin_lut(ray_angle)}, map);
		draw_wall((t_draw_ctx){buffer, map.textures[hit.dir], map, i, 0},
			hit.dist * cos_lut(-(float)cam.fov / 2 + i * angle_steps), hit);
		i++;
	}
	return (0);
}
