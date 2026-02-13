/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 04:30:48 by dderny            #+#    #+#             */
/*   Updated: 2025/11/02 04:31:15 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RGBA_H
# define RGBA_H
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

typedef union u_rgba
{
	unsigned int	rgb;
	int				_;
	struct
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	};
}			t_rgba;

#endif
