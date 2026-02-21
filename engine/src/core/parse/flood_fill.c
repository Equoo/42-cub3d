/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 22:35:51 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/21 03:06:53 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/parse.h"
#include "ft_printf.h"
#include "libft.h"
#include "types/vector2.h"

static void	fill(char **tab, t_vec2 size, t_vec2 cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y)
		return ;
	if (cur.x < 0 || cur.x >= size.x)
		return ;
	if (!tab[(int)cur.y])
		return ;
	if (cur.x >= (int)ft_strlen(tab[(int)cur.y]))
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
	if (start_char == '0' || start_char == 'N' || start_char == 'S'
		|| start_char == 'E' || start_char == 'W')
		fill(tab, (t_vec2){size_x, size_y}, begin, start_char);
}

static int	check_filled_boundaries_copy(char **map_copy, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < (int)ft_strlen(map_copy[i]))
		{
			if (map_copy[i][j] == 'F')
			{
				if (i == 0 || i == map->height - 1)
				{
					ft_printf(ERR_SURROUNDED_EDGE);
					return (1);
				}
				if (j == 0 || j == (int)ft_strlen(map_copy[i]) - 1)
				{
					ft_printf(ERR_SURROUNDED_EDGE);
					return (1);
				}
			}
		}
	}
	return (0);
}

static int	check_filled_spaces_copy(char **map_copy, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < (int)ft_strlen(map_copy[i]))
		{
			if (map_copy[i][j] == 'F')
			{
				if ((j > 0 && map_copy[i][j - 1] == ' ')
					|| (j < (int)ft_strlen(map_copy[i]) - 1 && map_copy[i][j
						+ 1] == ' ') || (i > 0 && j < (int)ft_strlen(map_copy[i
							- 1]) && map_copy[i - 1][j] == ' ')
					|| (i < map->height - 1 && j < (int)ft_strlen(map_copy[i
							+ 1]) && map_copy[i + 1][j] == ' '))
				{
					ft_printf(ERR_SURROUNDED_SPACE);
					return (1);
				}
			}
		}
	}
	return (0);
}

int	check_surrounded_with_flood_fill(t_map *map)
{
	char	**map_copy;
	int		result;

	if (!map || !map->grid || map->height <= 0)
		return (1);
	if (map->spawn.y < 0 || map->spawn.y >= map->height || (map->spawn.x < 0
			|| map->spawn.x >= (int)ft_strlen(map->grid[(int)map->spawn.y])))
	{
		ft_printf("Error: Invalid player spawn\n");
		return (1);
	}
	map_copy = duplicate_map_grid(map);
	if (!map_copy)
		return (1);
	flood_fill(map_copy, map->width, map->height, map->spawn);
	result = 0;
	if (check_filled_boundaries_copy(map_copy, map))
		result = 1;
	if (!result && check_filled_spaces_copy(map_copy, map))
		result = 1;
	free_map_copy(map_copy, map->height);
	return (result);
}
