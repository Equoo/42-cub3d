/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:02:12 by dderny            #+#    #+#             */
/*   Updated: 2026/02/14 22:49:00 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/camera.h"
#include "core/world.h"
#include "math/algorithm.h"
#include "math/extend.h"
#include "types/image.h"
#include "types/vector2.h"

const int	rays_filling = 1;
const int	rays_density = 1;

int	draw_walls(t_image *buffer, t_map map, t_camera cam)
{
	const int	rays = (float)buffer->width * rays_density;
	const float	angle_steps = (float)cam.fov / rays;
	float		ray_angle;
	t_hit		hit;
	int			i;

	i = 0;
	ray_angle = cam.rot.z - (float)cam.fov / 2;
	while (i < rays)
	{
		if (i % rays_filling && ++i)
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

// int	draw_walls(t_image *buffer, t_map map, t_camera cam)
// {
// 	const int	rays = buffer->width;
// 	const float	angle_steps = (float)cam.fov / (float)rays;
// 	const int	rays_filling = 1;
// 	int			i;
// 	float		ray_angle;
// 	t_hit		hit;
// 	t_vec2		off;
// 	t_vec2		origin;
// 	t_vec2		dir;
// 	t_vec2		a;
// 	t_vec2		b;
//
// 	// const int   slice_width = render->width / rays;
// 	i = 0;
// 	while (i < rays)
// 	{
// 		if (i % rays_filling && ++i)
// 			continue ;
// 		ray_angle = cam.rot.z - (float)cam.fov / 2 + i * angle_steps;
// 		off = (t_vec2){100, 500};
// 		origin = vec2_add(vec2_mulf((t_vec2){cam.pos.x, cam.pos.y}, 10), off);
// 		dir = (t_vec2){cos_lut(ray_angle), sin_lut(ray_angle)};
// 		hit = dda_trace((t_vec2){cam.pos.x, cam.pos.y}, dir, map);
// 		if (hit.hit)
// 		{
// 			draw_wall((t_draw_ctx){buffer, map.textures[hit.dir], map, i, 0},
// 				hit.dist * cos_lut(-(float)cam.fov / 2 + i * angle_steps), hit);
// 			draw_line(buffer, origin,
// 				vec2_add(vec2_mulf((t_vec2){cos_lut(ray_angle),
// 						sin_lut(ray_angle)}, 100), origin), (t_rgba)0xff00ff00);
// 			a = (t_vec2){100 + hit.pos.x * 10, 500 + hit.pos.y * 10};
// 			b = vec2_add(a, (t_vec2){10, 10});
// 			draw_square(buffer, a, b, (t_rgba)0xff0000ff);
// 		}
// 		else
// 			draw_line(buffer, origin,
// 				vec2_add(vec2_muli((t_vec2){cos_lut(ray_angle),
// 						sin_lut(ray_angle)}, 100), origin), (t_rgba)0xffff0000);
// 		i++;
// 	}
// 	return (0);
// }
