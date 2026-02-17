/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 03:00:15 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 03:00:18 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/image.h"
#include <mlx.h>

int	image_from_xpm(void *mlx, char *path, t_image *out)
{
	void	*img;
	int		nil;

	img = mlx_xpm_file_to_image(mlx, path, &nil, &nil);
	if (!img)
		return (1);
	*out = image_from_mlx(img);
	return (0);
}
