/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 22:35:51 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/19 05:58:37 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "types/vector2.h"

static void	fill(char **tab, t_vec2 size, t_vec2 cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y)
		return ;
	if (cur.x < 0 || cur.x >= size.x)
		return ;
	if (tab[(int)cur.y][(int)cur.x] == '1')
		return ;
	if (tab[(int)cur.y][(int)cur.x] == 'F')
		return ;
	if (tab[(int)cur.y][(int)cur.x] == ' ')
		return ;
	tab[(int)cur.y][(int)cur.x] = 'F';
	fill(tab, size, (t_vec2){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_vec2){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_vec2){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_vec2){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, int size_x, int size_y, t_vec2 begin)
{
	char	start_char;

	if (begin.x < 0 || begin.x >= size_x || begin.y < 0 || begin.y >= size_y)
		return ;
	start_char = tab[(int)begin.y][(int)begin.x];
	if (start_char == '0' || start_char == 'N' || start_char == 'S' || 
		start_char == 'E' || start_char == 'W')
		fill(tab, (t_vec2){size_x, size_y}, begin, start_char);
}
