/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 04:07:42 by zsonie            #+#    #+#             */
/*   Updated: 2025/10/30 04:51:45 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lut/dist.h"
#include <math.h>
#include <stdlib.h>

dist_lut	*create_distance_lut(void)
{
	dist_lut	*lut;
    int         x;
    int         y;

	lut = malloc(sizeof(dist_lut));
	if (!lut)
		return (NULL);
    x = 0;
    y = 0;
	while (x < MAX_DIST)
	{
		while (y < MAX_DIST)
		{
			lut->distances[x][y] = sqrtf((float)(x * x + y * y));
            y++;
		}
        x++;
	}
	return (lut);
}

void	destroy_distance_lut(dist_lut *lut)
{
	free(lut);
}

float	get_distance_lut(const dist_lut *lut, int dx, int dy)
{
	dx = abs(dx);
	dy = abs(dy);
	if (dx >= MAX_DIST)
		dx = MAX_DIST - 1;
	if (dy >= MAX_DIST)
		dy = MAX_DIST - 1;
	return (lut->distances[dx][dy]);
}
