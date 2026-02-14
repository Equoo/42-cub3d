/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 04:30:48 by dderny            #+#    #+#             */
/*   Updated: 2026/02/14 21:44:54 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RGBA_H
# define RGBA_H
# include <mm256.h>
# include <sys/types.h>

typedef struct
{
	struct
	{
		__m256i_u		b;
		__m256i_u		g;
		__m256i_u		r;
		__m256i_u		a;
	};
	__m256i_u			rgba;
}						t_m256i_color;

typedef union u_rgba
{
	unsigned int		rgb;
	int					_;
	struct
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	};
}						t_rgba;

int						rgba_from_str(char *str, t_rgba *out);
t_rgba					apply_darkness(t_rgba color, float darkness);

#endif
