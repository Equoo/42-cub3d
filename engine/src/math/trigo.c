/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 04:00:59 by zsonie            #+#    #+#             */
/*   Updated: 2025/10/31 05:04:51 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "math/extend.h"
#include <math.h>

inline float	sin_lut(int angle_deg)
{
	static float	sin_table[TABLE_SIZE] = {0};
	int				i;
	float			radians;

	if (sin_table[TABLE_SIZE - 1] == .0f)
	{
		i = 0;
		while (i < TABLE_SIZE)
		{
			radians = i * (PI / 180.0);
			sin_table[i] = sin(radians);
			i++;
		}
	}
	angle_deg = angle_deg % 360;
	if (angle_deg < 0)
		angle_deg += 360;
	return (sin_table[angle_deg]);
}

inline float	cos_lut(int angle_deg)
{
	static float	cos_table[TABLE_SIZE] = {0};
	int				i;
	float			radians;

	if (cos_table[TABLE_SIZE - 1] == .0f)
	{
		i = 0;
		while (i < TABLE_SIZE)
		{
			radians = i * (PI / 180.0);
			cos_table[i] = cos(radians);
			i++;
		}
	}
	angle_deg = angle_deg % 360;
	if (angle_deg < 0)
		angle_deg += 360;
	return (cos_table[angle_deg]);
}
