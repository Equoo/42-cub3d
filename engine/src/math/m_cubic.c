/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_cubic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:52:33 by zsonie            #+#    #+#             */
/*   Updated: 2025/10/31 05:34:14 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math/extend.h>

float	easeInCubic(int x)
{
	return (x * x * x);
}

float	easeOutCubic(int x)
{
	return (1 - pow(1 - x, 3));
}

float	easeInOutCubic(int x)
{
    if (x < 0.5)
        return (4 * x * x * x);
    else
        return (1 - pow(-2 * x + 2, 3) / 2);
}
