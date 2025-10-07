/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:13:19 by dderny            #+#    #+#             */
/*   Updated: 2025/04/18 16:33:23 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2d.h"

t_vec2	vec2_multiply(t_vec2 self, t_vec2 other)
{
	t_vec2	result;

	result.x = self.x * other.x;
	result.y = self.y * other.y;
	return (result);
}

t_vec2i	vec2i_multiply(t_vec2i self, t_vec2i other)
{
	t_vec2i	result;

	result.x = self.x * other.x;
	result.y = self.y * other.y;
	return (result);
}
