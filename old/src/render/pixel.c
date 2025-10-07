/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 20:20:29 by dderny            #+#    #+#             */
/*   Updated: 2025/04/14 22:00:37 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mm256.h>
#include "render.h"
#include <mlx_int.h>

void	mylx_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->data + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	*mylx_pixel_get(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->data + (y * img->size_line + x * (img->bpp / 8));
	return ((unsigned int *)dst);
}

void	mylx_m256_pixel_put(t_img *img, int x, int y, __m256i_u color)
{
	char	*dst;

	dst = img->data + (y * img->size_line + x * (img->bpp / 8));
	*(__m256i_u *)dst = color;
}

__m256i_u	*mylx_m256_pixel_get(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->data + (y * img->size_line + x * (img->bpp / 8));
	return ((__m256i_u *)dst);
}
