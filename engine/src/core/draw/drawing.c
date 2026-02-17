/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 02:53:54 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 03:50:21 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/draw.h"
#include "types/vector2.h"
#include <libft.h>

inline void	draw_pixel(const t_image *img, const int x, const int y,
		const t_rgba color)
{
	img->data[y * img->size_line + x] = color;
}

void	draw_line(const t_image *img, t_vec2 p1, const t_vec2 p2,
		const t_rgba color)
{
	const t_vec2	delta = (t_vec2){p2.x - p1.x, p2.y - p1.y};
	const int		total = ft_fmax(fabs(delta.x), fabs(delta.y));
	const t_vec2	step = (t_vec2){delta.x / (float)total, delta.y
			/ (float)total};
	int				i;

	i = 0;
	while (i < total)
	{
		if (p1.x < 0 || p1.x >= img->width || p1.y < 0 || p1.y >= img->height)
			break ;
		draw_pixel(img, (int)p1.x, (int)p1.y, color);
		p1.x += step.x;
		p1.y += step.y;
		i++;
	}
}

void	draw_square(const t_image *img, const t_vec2 p1, const t_vec2 p2,
		const t_rgba color)
{
	int	x;
	int	y;
	int	x_end;
	int	y_end;

	x = ft_clamp(p1.x, 0, img->width - 1);
	y = ft_clamp(p1.y, 0, img->height - 1);
	x_end = ft_clamp(p2.x, 0, img->width - 1);
	y_end = ft_clamp(p2.y, 0, img->height - 1);
	while (y < y_end)
	{
		ft_memsetint((uint *)img->data + y * img->width + x, color.rgb, (x_end
				- x));
		y++;
	}
}
