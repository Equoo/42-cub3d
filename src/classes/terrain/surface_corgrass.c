/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_corgrass.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:50:38 by dderny            #+#    #+#             */
/*   Updated: 2025/04/27 00:53:50 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/terrain.h"
#include "ft_bool.h"
#include "libft.h"
#include "seed.h"
#include "vector2d.h"

t_bool	rs_corgrass(t_terrain *self, t_vec2i *pos, char **slice,
	t_rule_data data)
{
	const char	textures[][19] = {"corner_grass_1", "corner_grass_2"};
	int			dirs[4];
	int			dir;

	if (get_facing(self, *pos, dirs) < 2)
		return (FALSE);
	dir = -1;
	while (++dir < 4)
		if (dirs[dir] && rule_platform(self, getposindir(*pos, dir), NULL,
				data.transform))
			return (FALSE);
	if (dirs[DIR_TOP] == 1 && dirs[DIR_RIGHT] == 1)
		data.transform->angle = 90;
	else if (dirs[DIR_TOP] == 1 && dirs[DIR_LEFT] == 1)
		data.transform->angle = 180;
	else if (dirs[DIR_BOTTOM] == 1 && dirs[DIR_LEFT] == 1)
		data.transform->angle = -90;
	data.used[pos->x + pos->y * self->w] = 1;
	*slice = ft_strdup(textures[rand_int() % 2]);
	return (TRUE);
}
