/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:58:57 by dderny            #+#    #+#             */
/*   Updated: 2025/04/23 16:57:06 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"
#include "render.h"
#include "vector2d.h"
#include <mlx.h>

static void	clamp_square_to_dest(t_2vec2i *sqr, t_vec2i pos, t_img *dest)
{
	if (pos.x + sqr->b.x - sqr->a.x > dest->width)
		sqr->b.x -= (pos.x + sqr->b.x - sqr->a.x) - dest->width;
	if (pos.y + sqr->b.y - sqr->a.y > dest->height)
		sqr->b.y -= (pos.y + sqr->b.y - sqr->a.y) - dest->height;
}

static void	copy_row(t_2vec2i sqr, t_2vec2i pos_i, t_img *dest,
	t_img *src)
{
	void	*src_pixels;
	int		x_offset;

	while (pos_i.b.x < sqr.b.x)
	{
		x_offset = pos_i.b.x + pos_i.a.x - sqr.a.x;
		if (x_offset < 0 || x_offset >= dest->width)
			break ;
		src_pixels = mylx_pixel_get(src, pos_i.b.x, pos_i.b.y);
		if (sqr.b.x - pos_i.b.x >= M256_NPIXEL)
		{
			mylx_m256_pixel_put(dest, x_offset, pos_i.b.y + pos_i.a.y - sqr.a.y,
				*(__m256i_u *)src_pixels);
			pos_i.b.x += M256_NPIXEL - 1;
		}
		else
			mylx_pixel_put(dest, x_offset, pos_i.b.y + pos_i.a.y - sqr.a.y,
				*(unsigned int *)src_pixels);
		pos_i.b.x++;
	}
}

static void	copy_pixels(t_2vec2i sqr, t_vec2i pos, t_img *dest, t_img *src)
{
	t_vec2i	i;
	int		y_offset;

	i.y = sqr.a.y;
	while (pos.y + sqr.a.y - i.y < dest->height && i.y < sqr.b.y)
	{
		y_offset = i.y + pos.y - sqr.a.y;
		if (y_offset < 0 || y_offset >= dest->height)
			break ;
		i.x = sqr.a.x;
		copy_row(sqr, (t_2vec2i){pos, i}, dest, src);
		i.y++;
	}
}

void	*mylx_img_fast_copy(t_2vec2i sqr, t_vec2i pos, t_img *dest, t_img *src)
{
	clamp_square_to_dest(&sqr, pos, dest);
	copy_pixels(sqr, pos, dest, src);
	return (dest);
}
