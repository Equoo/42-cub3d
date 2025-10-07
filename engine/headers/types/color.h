/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:02:00 by dderny            #+#    #+#             */
/*   Updated: 2025/10/06 17:56:54 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include <mm256.h>
# include <sys/types.h>

typedef struct
{
    struct {
        __m256i_u	b;
        __m256i_u	g;
        __m256i_u	r;
        __m256i_u	a;
    };
    __m256i_u rgba;
}				t_m256i_color;

typedef union
{
    struct {
	    u_int16_t		b;
	    u_int16_t		g;
	    u_int16_t		r;
	    u_int16_t		a;
    };
    u_int rgba;
}				t_color;

#endif
