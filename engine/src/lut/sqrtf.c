/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqrtf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 04:37:42 by zsonie            #+#    #+#             */
/*   Updated: 2025/10/30 04:53:38 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lut/sqrtf.h"
#include <math.h>
#include <stdlib.h>

sqrtf_lut	*create_sqrtf_lut(void)
{
	sqrtf_lut	*lut;
	int			i;

	lut = malloc(sizeof(sqrtf_lut));
	if (!lut)
		return (NULL);
	i = 0;
	while (i < SQRTF_TABLE_SIZE)
	{
		lut->values[i] = sqrtf((float)i);
	}
	return (lut);
}

void	destroy_sqrtf_lut(sqrtf_lut *lut)
{
	free(lut);
}

float	fast_sqrtf_lut(const sqrtf_lut *lut, int value)
{
	if (value < 0)
		return (0.0f);
	if (value >= SQRTF_TABLE_SIZE)
		return (sqrtf((float)value));
	return (lut->values[value]);
}
