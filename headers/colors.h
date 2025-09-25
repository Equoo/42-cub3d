/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:02:00 by dderny            #+#    #+#             */
/*   Updated: 2025/04/26 01:45:59 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H
# include <mm256.h>

typedef struct s_m256i_rgba
{
    struct {
        __m256i_u	r;
        __m256i_u	g;
        __m256i_u	b;
        __m256i_u	a;
    };
    __m256i_u rgba;
}				t_m256i_rgba;

typedef union s_rgba
{
    struct {
	    u_int		r;
	    u_int		g;
	    u_int		b;
	    u_int		a;
    };
    u_int rgba;
}				t_rgba;

t_m256i_rgba	m256_split_channels(__m256i_u rgba, int alpha);
__m256i_u		m256_combine_channels(t_m256i_rgba chans);
t_m256i_rgba	m256_blend_by_alpha(t_m256i_rgba dst, t_m256i_rgba src);

t_rgba			split_channels(u_int rgba, int alpha);
u_int			combine_channels(t_rgba chans);
t_rgba			blend_by_alpha(t_rgba dst, t_rgba src);

#endif
