/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqrtf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 04:37:42 by zsonie            #+#    #+#             */
/*   Updated: 2025/10/31 05:28:12 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <math_extend.h>

inline float	fast_sqrtf_lut(int value)
{
	static float	values[SQRTF_TABLE_SIZE] = {0};
	int				i;

	i = -1;
	if (values[SQRTF_TABLE_SIZE - 1] == .0f)
	{
		while (++i < SQRTF_TABLE_SIZE)
			values[i] = sqrtf((float)i);
	}
	if (value < 0)
		return (.0f);
	if (value >= SQRTF_TABLE_SIZE)
		return (sqrtf((float)value));
	return (values[value]);
}
