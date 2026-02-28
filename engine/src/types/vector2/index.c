/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:31:50 by dderny            #+#    #+#             */
/*   Updated: 2026/02/28 16:42:01 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <types/vector2.h>

int	vec2_index(t_vec2 self, int width)
{
	return (width * (int)self.y + (int)self.x);
}

t_vec2	vec2_from_index(int index, int width)
{
	return ((t_vec2){index % width, index / width});
}
