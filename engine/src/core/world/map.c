/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:10:14 by dderny            #+#    #+#             */
/*   Updated: 2026/02/14 18:44:00 by dderny                  ###   ########   */
/*                                                                            */
/* ************************************************************************** */

#include "core/camera.h"
#include "core/draw.h"
#include "core/world.h"
#include "libft.h"
#include "math/algorithm.h"
#include "math/extend.h"
#include "types/image.h"
#include "types/rgba.h"
#include "types/vector2.h"

static void	draw_wall(t_image *buffer, int x, float dist, t_hit hit,
		t_image img)
{
	const int	w_height = 1 / dist * 1200;
	const int	s_height = ft_clamp(w_height, 0, buffer->height);
	float		img_off;
	float		img_step;
	uint		img_x;
	int			i;
	const float	darkness = ft_fclamp(1 / (dist * 0.8), 0.05, 1);
	float		darkness2;
	t_rgba		color;

	i = 0;
	if (s_height == 0)
		return ;
	img_off = (float)(w_height - s_height) / 2 / (float)w_height * img.height;
	img_x = (int)(hit.pos.y * img.width) % img.width;
	if (hit.dir == 0 || hit.dir == 1)
		img_x = (int)(hit.pos.x * img.width) % img.width;
	img_step = (float)img.height / (float)w_height;
	while (i < buffer->height / 2 - s_height / 2 + 1)
	{
		darkness2 = ft_fclamp(1. / i, 0.05, 1);
		color = (t_rgba)(0x002e5a89);
		color.r *= darkness2;
		color.g *= darkness2;
		color.b *= darkness2;
		draw_pixel(buffer, x, i, color);
		color = (t_rgba)(0x004e89c6);
		color.r *= darkness2;
		color.g *= darkness2;
		color.b *= darkness2;
		draw_pixel(buffer, x, buffer->height - i, color);
		i++;
	}
	i = 0;
	while (i < s_height)
	{
		color = img.data[img_x + (int)(i * img_step + img_off) * img.width];
		color.r *= darkness;
		color.g *= darkness;
		color.b *= darkness;
		draw_pixel(buffer, x, buffer->height / 2 - s_height / 2 + i, color);
		i++;
	}
}

int	draw_walls(t_image *buffer, t_map map, t_camera cam)
{
	const int	rays = buffer->width;
	const float	angle_steps = (float)cam.fov / (float)rays;
	const int	rays_filling = 1;
	int			i;
	float		ray_angle;
	t_hit		hit;
	t_vec2		off;
	t_vec2		origin;
	t_vec2		dir;
	t_vec2		a;
	t_vec2		b;

	// const int   slice_width = render->width / rays;
	i = 0;
	while (i < rays)
	{
		if (i % rays_filling && ++i)
			continue ;
		ray_angle = cam.rot.z - (float)cam.fov / 2 + i * angle_steps;
		off = (t_vec2){100, 500};
		origin = vec2_add(vec2_mulf((t_vec2){cam.pos.x, cam.pos.y}, 10), off);
		dir = (t_vec2){cos_lut(ray_angle), sin_lut(ray_angle)};
		hit = dda_trace((t_vec2){cam.pos.x, cam.pos.y}, dir, map);
		if (hit.hit)
		{
			draw_wall(buffer, i, hit.dist * cos_lut(-(float)cam.fov / 2 + i
					* angle_steps), hit, map.textures[hit.dir].tex);
			draw_line(buffer, origin,
				vec2_add(vec2_mulf((t_vec2){cos_lut(ray_angle),
						sin_lut(ray_angle)}, 100), origin), (t_rgba)0xff00ff00);
			a = (t_vec2){100 + hit.pos.x * 10, 500 + hit.pos.y * 10};
			b = vec2_add(a, (t_vec2){10, 10});
			draw_square(buffer, a, b, (t_rgba)0xff0000ff);
		}
		else
			draw_line(buffer, origin,
				vec2_add(vec2_muli((t_vec2){cos_lut(ray_angle),
						sin_lut(ray_angle)}, 100), origin), (t_rgba)0xffff0000);
		i++;
	}
	return (0);
}
