/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 22:35:51 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/17 23:12:41 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "types/vector2.h"

static void	fill(char **tab, t_vec2 size, t_vec2 cur, char to_fill)
{
	if (cur.y < 0)
		return ;
	if (cur.y > size.y)
		return ;
	if (cur.x < 0)
		return ;
	if (cur.x > size.x)
		return ;
	if (tab[(int)cur.y][(int)cur.x] == '1')
		return ;
	if (tab[(int)cur.y][(int)cur.x] == to_fill)
		tab[(int)cur.y][(int)cur.x] = 'F';
	fill(tab, size, (t_vec2){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_vec2){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_vec2){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_vec2){cur.x, cur.y + 1}, to_fill);
}

static void	flood_fill(char **tab, int size_x, int size_y, t_vec2 begin)
{
	fill(tab, (t_vec2){size_x, size_y}, begin, '0');
}
