/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_inmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 03:34:59 by dderny            #+#    #+#             */
/*   Updated: 2026/02/23 03:36:21 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/world.h"

int	is_inmap(t_vec2 pos, t_map *map)
{
	if (pos.x >= 0 && pos.x < map->width && pos.y >= 0 && pos.y < map->height)
		return (1);
	else
		return (0);
}
