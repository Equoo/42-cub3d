/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 04:30:48 by dderny            #+#    #+#             */
/*   Updated: 2025/11/02 04:31:15 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H
# include <mlx_int.h>
# include "types/rgba.h"

typedef struct s_image
{
	void	*img;
	t_rgba	*data;
	int		size_line;
	int		width;
	int		height;
	int		size;
	int		byte_size_line;
	int		byte_size;
} t_image;

t_image image_from_mlx(t_img *img);
int		image_from_xpm(void *mlx, char *path, t_image *out);
int		image_new(void *mlx, int width, int height, t_image *out);

#endif
