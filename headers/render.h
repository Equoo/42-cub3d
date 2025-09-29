/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:54:37 by dderny            #+#    #+#             */
/*   Updated: 2025/09/28 23:16:00 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "ft_vector.h"
# include "vector2d.h"
# include <libft.h>
# include <mlx_int.h>
# include <mm256.h>

// (int)(sizeof(__m256i_u) / sizeof(unsigned int))
# define M256_NPIXEL 8

typedef struct s_rtext
{
	char		*text;
	t_vec2i		pos;
	int			font_size;
}				t_rtext;

typedef struct s_image
{
	t_img	*img;
	u_int	*data;
	int		size_line;
	int		width;
	int		height;
	int		size;
}   t_image;

typedef struct s_render
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;

	t_list		*textures;
	t_img		*buffer;
	t_image		buffer_img;
	void		*font;
	t_vec   	texts;
}				t_render;

typedef enum e_imgflip
{
	FLIP_NONE,
	FLIP_HORIZ,
	FLIP_VERT
}				t_imgflip;

typedef struct s_copyimg
{
	t_vec2i		from;
	t_vec2i		size;
	t_vec2i		to;
	t_img		*src;
	t_img		*dest;
	t_imgflip	flip;
	int			angle;
}				t_copyimg;

void			render_texts(t_render *render, t_img *buffer);

void            put_pixel(const t_image img, const int x, const int y, u_int color);
void			mylx_pixel_put(t_img *img, int x, int y, unsigned int color);
void			mylx_m256_pixel_put(t_img *img, int x, int y, __m256i_u color);
unsigned int	*mylx_pixel_get(t_img *img, int x, int y);
__m256i_u		*mylx_m256_pixel_get(t_img *img, int x, int y);

/**
** Secure way to open a xpm image
** @param mlx: the mlx pointer
** @param path: the image path
** @param width: width pointer
** @param height: height pointer
** @return the new image
*/
t_img			*mylx_xpm_to_img(void *mlx, char *path, int *width,
					int *height);

/**
** Copy and scale an image to a new image
** @param mlx: the mlx pointer
** @param img: the image to scale
** @param scale: the scale factor
** @return the new image
*/
void			*mylx_img_scale(void *mlx, t_img *img, int scale);

/*
** Copy an image to a new image
** @param sqr: the square to copy
** @param pos: the position to paste
** @param dest: the destination image
** @param src: the source image
** @return the destination image
*/
void			*mylx_img_fast_blend(t_2vec2i sqr, t_vec2i pos, t_img *dest,
					t_img *src);

void			*mylx_img_blend(t_copyimg data);

/*
** Blend an image to a new image with alpha channel
** @param sqr: the square to blend
** @param pos: the position to paste
** @param dest: the destination image
** @param src: the source image
** @return the destination image
*/
void			*mylx_img_fast_copy(t_2vec2i sqr, t_vec2i pos, t_img *dest,
					t_img *src);

void			*mylx_img_copy(t_copyimg data);

int				draw_text(t_render *render, char *text, t_vec2 pos,
					int font_size);

#endif
