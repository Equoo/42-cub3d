/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_cubic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:52:33 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/17 03:10:16 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math/extend.h>

float	ease_in_cubic(int x)
{
	return (x * x * x);
}

float	ease_out_cubic(int x)
{
	return (1 - pow(1 - x, 3));
}

float	ease_in_out_cubic(int x)
{
	if (x < 0.5)
		return (4 * x * x * x);
	else
		return (1 - pow(-2 * x + 2, 3) / 2);
}
