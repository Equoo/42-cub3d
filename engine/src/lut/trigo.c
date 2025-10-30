/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 04:00:59 by zsonie            #+#    #+#             */
/*   Updated: 2025/10/30 04:52:34 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lut/trigo.h"
#include "math_extend.h"
#include <math.h>
#include <stdlib.h>

trigo_lut	*create_trigo_lut(void)
{
	trigo_lut	*lut;
	float		radians;
    int         i;

	lut = malloc(sizeof(trigo_lut));
	if (!lut)
        return (NULL);
    i = 0;
	while (i < TABLE_SIZE)
	{
		radians = i * (PI / 180.0);
		lut->sin_table[i] = sin(radians);
		lut->cos_table[i] = cos(radians);
        i++;
	}
	return (lut);
}

void	destroy_trigo_lut(trigo_lut *lut)
{
	free(lut);
}

float	sin_lut(const trigo_lut *lut, int angle_deg)
{
	angle_deg = angle_deg % 360;
	if (angle_deg < 0)
		angle_deg += 360;
	return (lut->sin_table[angle_deg]);
}

float	cos_lut(const trigo_lut *lut, int angle_deg)
{
	angle_deg = angle_deg % 360;
	if (angle_deg < 0)
		angle_deg += 360;
	return (lut->cos_table[angle_deg]);
}
