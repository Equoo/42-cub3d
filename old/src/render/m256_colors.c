/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m256_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:13:28 by dderny            #+#    #+#             */
/*   Updated: 2025/04/14 22:00:37 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include <stdio.h>

t_m256i_rgba	m256_split_channels(__m256i_u rgba, int alpha)
{
	t_m256i_rgba	chans;

	if (alpha)
		chans.a = ft_mm256_and(ft_mm256_srli(rgba, 24), ft_mm256_set1(0xFF));
	chans.r = ft_mm256_and(ft_mm256_srli(rgba, 16), ft_mm256_set1(0xFF));
	chans.g = ft_mm256_and(ft_mm256_srli(rgba, 8), ft_mm256_set1(0xFF));
	chans.b = ft_mm256_and(rgba, ft_mm256_set1(0xFF));
	return (chans);
}

__m256i_u	m256_combine_channels(t_m256i_rgba chans)
{
	return (ft_mm256_or(ft_mm256_or(ft_mm256_slli(chans.r, 16),
				ft_mm256_slli(chans.g, 8)), chans.b));
}

t_m256i_rgba	m256_blend_by_alpha(t_m256i_rgba dst, t_m256i_rgba src)
{
	t_m256i_rgba	blended;
	__m256i_u		inv_src_a;

	inv_src_a = ft_mm256_sub(ft_mm256_set1(255), src.a);
	blended.r = ft_mm256_div(ft_mm256_add(ft_mm256_mullo(src.r, inv_src_a),
				ft_mm256_mullo(dst.r, src.a)), ft_mm256_set1(255));
	blended.g = ft_mm256_div(ft_mm256_add(ft_mm256_mullo(src.g, inv_src_a),
				ft_mm256_mullo(dst.g, src.a)), ft_mm256_set1(255));
	blended.b = ft_mm256_div(ft_mm256_add(ft_mm256_mullo(src.b, inv_src_a),
				ft_mm256_mullo(dst.b, src.a)), ft_mm256_set1(255));
	return (blended);
}
