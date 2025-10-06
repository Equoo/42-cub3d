/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:32:24 by dderny            #+#    #+#             */
/*   Updated: 2025/10/06 16:48:05 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <types/vector2.h>

float	vec2_sqrdist(t_vec2 a, t_vec2 b)
{
	return ((a.x - b.x) * (a.x - b.x)
		+ (a.y - b.y) * (a.y - b.y));
}

float	vec2_dist(t_vec2 a, t_vec2 b)
{
	return (sqrtf(vec2_sqrdist(a, b)));
}