/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_sine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:39:48 by zsonie            #+#    #+#             */
/*   Updated: 2025/10/31 05:34:19 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math_extend.h>

float	easeInSine(int x)
{
	return (1 - cos((x * PI) / 2));
}

float	easeOutSine(int x)
{
	return (sin((x * PI) / 2));
}

float	easeInOutSine(int x)
{
	return (-(cos(PI * x) - 1) / 2);
}
