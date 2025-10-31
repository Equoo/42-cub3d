/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 04:07:42 by zsonie            #+#    #+#             */
/*   Updated: 2025/10/31 05:47:07 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math_extend.h>
#include <math.h>
#include <stdlib.h>

inline float	get_distance_lut(int dx, int dy)
{
	static float	distances[MAX_DIST * MAX_DIST] = {0};
	int				x;
	int				y;

	if (distances[MAX_DIST * MAX_DIST -1] == .0f)
	{
		x = -1;
		while (++x < MAX_DIST)
		{
			y = -1;
			while (++y < MAX_DIST)
			{
				distances[y * MAX_DIST + x] = sqrtf((float)(x * x + y * y));
			}
		}
	}
	dx = abs(dx);
	dy = abs(dy);
	if (dx >= MAX_DIST)
		dx = MAX_DIST - 1;
	if (dy >= MAX_DIST)
		dy = MAX_DIST - 1;
	return (distances[dy * MAX_DIST + dx]);
}
