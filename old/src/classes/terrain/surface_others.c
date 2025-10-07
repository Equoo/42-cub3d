/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_others.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:50:38 by dderny            #+#    #+#             */
/*   Updated: 2025/04/27 00:49:45 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/terrain.h"
#include "ft_bool.h"
#include "libft.h"
#include "seed.h"
#include "vector2d.h"

static void	rs_basic(char **slice, t_transform *transform, int dir)
{
	const char	textures[][19] = {"grass_1", "grass_2", "grass_3"};

	if (*slice)
		free(*slice);
	if (dir == DIR_TOP)
		transform->angle = 180;
	else if (dir == DIR_RIGHT)
		transform->angle = 90;
	else if (dir == DIR_LEFT)
		transform->angle = -90;
	*slice = ft_strdup(textures[rand_int() % 3]);
}

static t_bool	rs_falling(t_terrain *self, char **slice, t_vec2i *pos,
		int *used)
{
	t_prob	textures[5];
	int		i;
	int		res;

	ft_memcpy(textures, (const t_prob[5]){{5, {{1, 1}, {1, 1}}, "moss"}, {15,
	{{1, 3}, {1, 3}}, "moss_flower_2"}, {20, {{1, 1}, {1, 1}},
		"moss_flower_1"}, {10, {{1, 4}, {1, 4}}, "moss_flower_3"}, {30, {{1, 1},
	{1, 1}}, ""}}, 5 * sizeof(t_prob));
	i = -1;
	while (++i < 5)
		if (!check_space(self, *pos, textures[i].size.a, used))
			textures[i].rate = 0;
	res = get_random(textures, 5);
	if (res == -1)
		return (FALSE);
	*slice = ft_strdup(textures[res].slice);
	if (!*slice)
		return (FALSE);
	i = 0;
	while (++i < textures[res].size.b.x * textures[res].size.b.y)
		used[(pos->x + i % textures[res].size.b.x) + (pos->y + i
				/ textures[res].size.b.x) * self->w] = 1;
	return (TRUE);
}

static void	rs_ground_textures(t_prob *textures)
{
	const t_prob	texs[] = {{100, {{4, 4}, {2, 4}}, "tree"}, {400, {{8, 9},
	{4, 9}}, "big_tree"}, {10, {{1, 1}, {1, 1}}, "rock"}, {40, {{5, 2},
	{5, 2}}, "large_bush"}, {25, {{3, 2}, {3, 2}}, "bush"}, {10, {{1,
		1}, {1, 1}}, "flower_4"}, {18, {{3, 2}, {3, 2}}, "big_rock"}, {10,
	{{1, 1}, {1, 1}}, "flower_1"}, {10, {{1, 1}, {1, 1}}, "flower_2"},
	{10, {{1, 1}, {1, 1}}, "flower_3"}, {100, {{1, 1}, {1, 1}}, ""}};

	ft_memcpy(textures, texs, 11 * sizeof(t_prob));
}

static t_bool	rs_ground(t_terrain *self, char **slice, t_vec2i *pos,
		int *used)
{
	t_prob	textures[11];
	int		i;
	int		res;
	int		space;

	rs_ground_textures(textures);
	i = -1;
	while (++i < 11)
		if (!check_space(self, *pos, vec2i_multiply(textures[i].size.a,
					(t_vec2i){1, -1}), used))
			textures[i].rate = 0;
	res = get_random(textures, 11);
	if (res != -1)
		*slice = ft_strdup(textures[res].slice);
	if (!*slice)
		return (FALSE);
	space = (textures[res].size.a.x - textures[res].size.b.x) / 2;
	while (++i - 11 < textures[res].size.b.x * textures[res].size.b.y)
		used[(pos->x + space + (i - 11) % textures[res].size.b.x) + (pos->y + (i
					- 11) / textures[res].size.b.x * -1) * self->w] = 1;
	pos->y -= textures[res].size.b.y - 1;
	return (TRUE);
}

t_bool	rs_other(t_terrain *self, t_vec2i *pos, char **slice, t_rule_data data)
{
	int		dirs[4];
	int		dir;
	t_vec2i	lastpos;

	if (get_facing(self, *pos, dirs) < 1)
		return (FALSE);
	dir = -1;
	while (++dir < 4)
		if (dirs[dir] && !rule_platform(self, getposindir(*pos, dir), NULL,
				NULL))
			break ;
	if (dir == 4)
		return (FALSE);
	if (rand_int() % 2)
		data.transform->scale.x = -1;
	lastpos = *pos;
	if (dir == DIR_BOTTOM && rs_ground(self, slice, pos, data.used) && **slice)
		return (TRUE);
	*pos = lastpos;
	if (dir == DIR_TOP && rs_falling(self, slice, pos, data.used) && **slice)
		return (TRUE);
	*pos = lastpos;
	rs_basic(slice, data.transform, dir);
	data.used[pos->x + pos->y * self->w] = 1;
	return (TRUE);
}
