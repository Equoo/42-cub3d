/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawbuffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:49:39 by dderny            #+#    #+#             */
/*   Updated: 2026/02/14 19:49:45 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/window.h"
#include "mlx.h"

int	window_drawbuffer(t_window *self)
{
	mlx_put_image_to_window(self->mlx, self->mlx_win, self->buffer.img, 0, 0);
	return (0);
}
