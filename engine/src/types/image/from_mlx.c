/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 03:00:06 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 03:00:12 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/image.h"
#include <mlx.h>
#include <mlx_int.h>

t_image	image_from_mlx(t_img *img)
{
	const int	width = img->width;
	const int	height = img->height;
	t_image		out;

	out.img = img;
	out.data = (t_rgba *)mlx_get_data_addr(out.img, &out.byte_size_line,
			&out.byte_size_line, &out.height);
	out.size_line = out.byte_size_line / 4;
	out.width = width;
	out.height = height;
	out.size = out.size_line * out.height;
	out.byte_size = out.byte_size_line * out.height;
	return (out);
}
