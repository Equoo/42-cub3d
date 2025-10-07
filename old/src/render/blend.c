/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:59:04 by dderny            #+#    #+#             */
/*   Updated: 2025/04/27 01:30:18 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "mlx_int.h"
#include "render.h"
#include "vector2d.h"
#include <mlx.h>

static int	isoutofbounds(t_copyimg *data, t_vec2i real_size, t_vec2i pos,
		int *i)
{
	t_vec2i	dstpos;

	dstpos = vec2i_add(pos, data->to);
	if (dstpos.x < 0 || dstpos.y < 0 || dstpos.x >= data->dest->width
		|| dstpos.y >= data->dest->height)
	{
		if (dstpos.x >= data->dest->width)
			(*i) += real_size.x - pos.x;
		else if (dstpos.y >= data->dest->height)
			(*i) = real_size.x * real_size.y;
		return (1);
	}
	return (0);
}

static void	do_blend(t_copyimg *data, t_vec2i spos, t_vec2i pos)
{
	mylx_pixel_put(data->dest, pos.x, pos.y,
		combine_channels(
			blend_by_alpha(
				split_channels(*mylx_pixel_get(data->dest, pos.x, pos.y), 0),
				split_channels(*mylx_pixel_get(data->src, spos.x, spos.y), 1)
				)
			)
		);
}

static void	blend(t_copyimg *data, t_vec2i real_size, int *i)
{
	t_vec2i	pos;
	t_vec2i	srcpos;

	while (++(*i) < real_size.x * real_size.y)
	{
		pos = (t_vec2i){(*i) % real_size.x, (*i) / real_size.x};
		if (isoutofbounds(data, real_size, pos, i))
			continue ;
		if (ft_abs(data->angle) == 90)
			pos = (t_vec2i){pos.y, pos.x};
		if (data->flip & FLIP_HORIZ)
			srcpos.x = data->from.x + data->size.x - pos.x - 1;
		else
			srcpos.x = data->from.x + pos.x;
		if (data->flip & FLIP_VERT)
			srcpos.y = data->from.y + data->size.y - pos.y - 1;
		else
			srcpos.y = data->from.y + pos.y;
		pos = (t_vec2i){(*i) % real_size.x, (*i) / real_size.x};
		pos = vec2i_add(pos, data->to);
		do_blend(data, srcpos, pos);
	}
}

static void	apply_angle(t_copyimg *data)
{
	if (data->angle == 0)
		return ;
	if (data->angle == 90)
	{
		data->flip = data->flip ^ FLIP_HORIZ;
	}
	else if (data->angle == -90)
	{
		data->flip = data->flip ^ FLIP_VERT;
	}
	else if (data->angle == 180)
	{
		data->flip = data->flip ^ (FLIP_HORIZ | FLIP_VERT);
	}
}

void	*mylx_img_blend(t_copyimg data)
{
	t_vec2i	real_size;
	int		i;

	real_size = data.size;
	i = -1;
	if (real_size.x + data.to.x > data.dest->width)
		real_size.x -= real_size.x + data.to.x - data.dest->width;
	if (real_size.y + data.to.y > data.dest->height)
		real_size.y -= real_size.y + data.to.y - data.dest->height;
	if (real_size.x < 0 || real_size.y < 0)
		return (data.dest);
	apply_angle(&data);
	blend(&data, real_size, &i);
	return (data.dest);
}
