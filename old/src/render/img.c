/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:54:12 by dderny            #+#    #+#             */
/*   Updated: 2025/04/25 23:25:07 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "mlx_int.h"
#include "render.h"
#include "vector2d.h"
#include <errno.h>
#include <mlx.h>
#include <stdio.h>

t_img	*mylx_xpm_to_img(void *mlx, char *path, int *width, int *height)
{
	int		olderrno;
	t_img	*img;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	close(fd);
	olderrno = errno;
	img = mlx_xpm_file_to_image(mlx, path, width, height);
	if (errno == EAGAIN && img)
		errno = olderrno;
	else if (!img && (!errno || errno == EAGAIN))
		errno = EINVALTEX;
	return (img);
}

static int	new_image(void *mlx, t_img *img, int scale, t_img **dest)
{
	int	olderrno;

	olderrno = errno;
	*dest = mlx_new_image(mlx, img->width * scale, img->height * scale);
	if (!*dest)
		return (1);
	if (errno == EAGAIN)
		errno = olderrno;
	return (0);
}

void	*mylx_img_scale(void *mlx, t_img *img, int scale)
{
	t_img			*dest;
	t_vec2i			pos;
	unsigned int	*src_pixels;
	unsigned int	*dst_pixels;
	int				i;

	if (new_image(mlx, img, scale, &dest))
		return (NULL);
	pos.y = -1;
	while (++pos.y < img->height)
	{
		src_pixels = mylx_pixel_get(img, 0, pos.y);
		dst_pixels = mylx_pixel_get(dest, 0, pos.y * scale);
		pos.x = img->width * scale;
		while (pos.x-- > 0)
			dst_pixels[pos.x] = src_pixels[pos.x / scale];
		i = 1;
		while (i < scale)
			ft_memcpy(mylx_pixel_get(dest, 0, pos.y * scale + i++), dst_pixels,
				dest->width * sizeof(int));
	}
	return (dest);
}
