/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 03:48:26 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 03:48:35 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include "types/image.h"
# include "types/vector2.h"
# include <sys/types.h>

void	draw_pixel(const t_image *img, const int x, const int y,
			const t_rgba color);
void	draw_line(const t_image *img, t_vec2 p1, const t_vec2 p2,
			const t_rgba color);
void	draw_square(const t_image *img, const t_vec2 p1, const t_vec2 p2,
			const t_rgba color);

#endif
