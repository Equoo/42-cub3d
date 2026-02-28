/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:53:43 by dderny            #+#    #+#             */
/*   Updated: 2026/02/28 15:53:51 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/vector2.h"

double	vec2_angle(t_vec2 from, t_vec2 to)
{
	t_vec2	dir;
	double	angle;

	dir = (t_vec2){to.x - from.x, to.y - from.y};
	angle = atan2(dir.y, dir.x) * (180.0 / M_PI);
	if (angle < 0)
		angle += 360.0;
	return (angle);
}
