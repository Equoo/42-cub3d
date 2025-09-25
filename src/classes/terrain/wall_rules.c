/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:50:38 by dderny            #+#    #+#             */
/*   Updated: 2025/04/26 19:04:54 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/terrain.h"
#include "vector2d.h"
#include "ft_bool.h"
#include "libft.h"
#include "seed.h"

t_bool	rule_topgrass(t_terrain *self, t_vec2i pos, char **slice,
		t_transform *transform)
{
	const char	textures[][19] = {"ground_top_green_1", "ground_top_green_2"};
	int			dirs[4];

	if (get_facing(self, pos, dirs) != 3)
		return (FALSE);
	if (dirs[DIR_BOTTOM] == 0)
		transform->angle = 180;
	else if (dirs[DIR_LEFT] == 0)
		transform->angle = 90;
	else if (dirs[DIR_RIGHT] == 0)
		transform->angle = -90;
	*slice = ft_strdup(textures[rand_int() % 2]);
	return (TRUE);
}

t_bool	rule_corgrass(t_terrain *self, t_vec2i pos, char **slice,
		t_transform *transform)
{
	const char	textures[][22] = {"ground_corner_green_1",
		"ground_corner_green_2"};
	int			dirs[4];

	if (get_facing(self, pos, dirs) != 2)
		return (FALSE);
	if (dirs[DIR_TOP] == 0 && dirs[DIR_RIGHT] == 0)
		transform->angle = -90;
	else if (dirs[DIR_BOTTOM] == 0 && dirs[DIR_LEFT] == 0)
		transform->angle = 90;
	else if (dirs[DIR_BOTTOM] == 0 && dirs[DIR_RIGHT] == 0)
		transform->angle = 180;
	if (!transform->angle && !(dirs[DIR_TOP] == 0 && dirs[DIR_LEFT] == 0))
		return (FALSE);
	*slice = ft_strdup(textures[rand_int() % 2]);
	return (TRUE);
}

static t_bool	basic_platform(t_terrain *self, t_vec2i pos, char **slice,
			int dirs[4]);

t_bool	rule_platform(t_terrain *self, t_vec2i pos, char **slice,
		__attribute__((unused)) t_transform *transform)
{
	const char	textures[][21] = {"platform", "platform_left_end",
		"platform_right_end"};
	int			dirs[4];
	int			facings;

	facings = get_facing(self, pos, dirs);
	if (facings > 2)
		return (FALSE);
	if (get_facing(self, pos, dirs) == 0 && slice)
		*slice = ft_strdup(textures[0]);
	else if (facings == 1)
	{
		if (dirs[DIR_TOP] == 1 || dirs[DIR_TOP] == 1)
			return (FALSE);
		if (slice && dirs[DIR_LEFT] == 1)
			*slice = ft_strdup(textures[2]);
		else if (slice)
			*slice = ft_strdup(textures[1]);
	}
	else if (facings == 2 && !basic_platform(self, pos, slice, dirs))
		return (FALSE);
	return (TRUE);
}

static t_bool	basic_platform(t_terrain *self, t_vec2i pos, char **slice,
		int dirs[4])
{
	const char	textures[][21] = {"platform_left_start", "platform",
		"platform_right_start"};

	if (!(dirs[DIR_TOP] == 0 && dirs[DIR_BOTTOM] == 0))
		return (FALSE);
	if (slice && !rule_platform(self, vec2i_add(pos, (t_vec2i){1, 0}), NULL,
		NULL))
		*slice = ft_strdup(textures[0]);
	else if (slice && !rule_platform(self, vec2i_add(pos, (t_vec2i){-1, 0}),
		NULL, NULL))
		*slice = ft_strdup(textures[2]);
	else if (slice)
		*slice = ft_strdup(textures[1]);
	return (TRUE);
}
