/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 04:00:59 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/20 22:04:18 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math/extend.h"
#include <math.h>

float	sanitize_angle(float f)
{
	if (f > 360)
		f -= 360;
	else if (f < 0)
		f += 360;
	return (f);
}

inline float	sin_lut(const float angle)
{
	static float	sin_table[TABLE_SIZE] = {0};
	int				i;
	float			radians;
	int				angle_deg;

	angle_deg = (int)(angle * 10);
	if (sin_table[TABLE_SIZE - 1] == .0f)
	{
		i = 0;
		while (i < TABLE_SIZE)
		{
			radians = i * (PI / (180.0 * 10));
			sin_table[i] = sin(radians);
			i++;
		}
	}
	angle_deg = angle_deg % 3600;
	if (angle_deg < 0)
		angle_deg += 3600;
	return (sin_table[angle_deg]);
}

inline float	cos_lut(const float angle)
{
	static float	cos_table[TABLE_SIZE] = {0};
	int				i;
	float			radians;
	int				angle_deg;

	angle_deg = (int)(angle * 10);
	if (cos_table[TABLE_SIZE - 1] == .0f)
	{
		i = 0;
		while (i < TABLE_SIZE)
		{
			radians = i * (PI / (180.0 * 10));
			cos_table[i] = cos(radians);
			i++;
		}
	}
	angle_deg = angle_deg % 3600;
	if (angle_deg < 0)
		angle_deg += 3600;
	return (cos_table[angle_deg]);
}
