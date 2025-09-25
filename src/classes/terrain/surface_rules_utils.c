/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_rules_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:58:31 by dderny            #+#    #+#             */
/*   Updated: 2025/04/27 00:15:16 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/terrain.h"
#include "collisions.h"
#include "seed.h"

int	get_random(t_prob *table, int size)
{
	int	i;
	int	rate_total;
	int	rand;

	i = 0;
	rate_total = 0;
	while (i < size)
	{
		rate_total += table[i].rate;
		i++;
	}
	i = 0;
	if (rate_total == 0)
		return (-1);
	rand = rand_int() % rate_total;
	while (i < size)
	{
		if (rand < table[i].rate)
			return (i);
		rand -= table[i].rate;
		i++;
	}
	return (-1);
}

t_bool	check_space(t_terrain *self, t_vec2i pos, t_vec2i size, int *used)
{
	int	i;
	int	j;
	int	index;

	i = -1;
	while (++i < size.x)
	{
		j = -1;
		while (++j < ft_fabs(size.y))
		{
			index = (pos.x + i) + (pos.y + j * (int)getsign(size.y)) * self->w;
			if (used[index] || self->grid[index] == MAP_WALL)
				return (FALSE);
		}
		if (self->grid[(pos.x + i) + (pos.y - 1 * (int)getsign(size.y))
				* self->w] != MAP_WALL)
			return (FALSE);
	}
	return (TRUE);
}
