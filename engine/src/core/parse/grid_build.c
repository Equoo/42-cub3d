/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 05:10:10 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/19 19:55:33 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/parse.h"
#include "libft.h"

static char	*create_row(char *cell_ptr, int row_len)
{
	char	*row;
	int		end;

	end = row_len - 1;
	while (end >= 0 && cell_ptr[end] == ' ')
		end--;
	if (end < 0)
	{
		row = ft_calloc(1, sizeof(char));
		if (!row)
			return (NULL);
		row[0] = '\0';
	}
	else
	{
		row = ft_calloc(end + 2, sizeof(char));
		if (!row)
			return (NULL);
		ft_memcpy(row, cell_ptr, end + 1);
		row[end + 1] = '\0';
	}
	return (row);
}

static int	get_row_len(char *cell_ptr)
{
	int	len;

	len = 0;
	while (cell_ptr[len] && cell_ptr[len] != '\n')
		len++;
	return (len);
}

int	build_map_grid(t_map *map)
{
	int		i;
	int		row_len;
	char	*row;
	char	*cell_ptr;

	map->grid = ft_calloc((map->height + 1), sizeof(char *));
	if (!map->grid)
		return (1);
	i = -1;
	while (++i < map->height)
		map->grid[i] = NULL;
	i = -1;
	cell_ptr = map->cells;
	while (++i < map->height && cell_ptr && *cell_ptr)
	{
		row_len = get_row_len(cell_ptr);
		row = create_row(cell_ptr, row_len);
		if (!row)
			return (1);
		map->grid[i] = row;
		if (ft_strlen(row) > (unsigned long)map->width)
			map->width = ft_strlen(row);
		cell_ptr += row_len;
		if (*cell_ptr == '\n')
			cell_ptr++;
	}
	map->grid[map->height] = NULL;
	return (0);
}
