/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:03:25 by dderny            #+#    #+#             */
/*   Updated: 2025/04/14 22:00:37 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

t_rgba	split_channels(u_int rgba, int alpha)
{
	t_rgba	chans;
	u_int	max;

	max = 0xFF;
	if (alpha)
		chans.a = rgba >> 24 & max;
	chans.r = rgba >> 16 & max;
	chans.g = rgba >> 8 & max;
	chans.b = rgba & max;
	return (chans);
}

u_int	combine_channels(t_rgba chans)
{
	return (chans.r << 16 | chans.g << 8 | chans.b);
}

t_rgba	blend_by_alpha(t_rgba dst, t_rgba src)
{
	int		inv_src_a;
	t_rgba	blended;

	inv_src_a = 255 - src.a;
	blended.r = (src.r * inv_src_a + dst.r * src.a) / 255;
	blended.g = (src.g * inv_src_a + dst.g * src.a) / 255;
	blended.b = (src.b * inv_src_a + dst.b * src.a) / 255;
	return (blended);
}
