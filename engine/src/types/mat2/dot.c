/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:03:32 by dderny            #+#    #+#             */
/*   Updated: 2025/10/30 13:03:28 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/mat2.h"

float	mat2_tdotx(t_mat2 m, t_vec2 v)
{
	return (m.col[0].x * v.x + m.col[0].y * v.y);
}

float	mat2_tdoty(t_mat2 m, t_vec2 v)
{
	return (m.col[1].x * v.x + m.col[1].y * v.y);
}
