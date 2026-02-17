/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_sine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:39:48 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/17 03:15:53 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math/extend.h>

float	ease_in_sine(int x)
{
	return (1 - cos((x * PI) / 2));
}

float	ease_out_sine(int x)
{
	return (sin((x * PI) / 2));
}

float	ease_in_out_sine(int x)
{
	return (-(cos(PI * x) - 1) / 2);
}
