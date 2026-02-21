/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 03:00:23 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 03:00:23 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/image.h"
#include <mlx.h>

int	image_new(void *mlx, int width, int height, t_image *out)
{
	void	*img;

	img = mlx_new_image(mlx, width, height);
	if (!img)
		return (1);
	*out = image_from_mlx(img);
	return (0);
}
