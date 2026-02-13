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

typedef union u_rgba
{
	unsigned int	rgb;
	struct
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	};
}			t_rgba;

#endif
