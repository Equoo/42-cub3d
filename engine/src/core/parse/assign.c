/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 21:49:24 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/22 09:14:32 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "core/parse.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"

static void	free_lines(char **lines, int height)
{
	while (--height >= 0)
		free(lines[height]);
	free(lines);
}

static char	**collect_map_lines(int fd, int *height, int *width)
{
	char	**lines;
	char	*line;
	int		len;

	lines = ft_calloc(MAP_MAXSIZE, sizeof(char *));
	if (!lines)
		return (NULL);
	*height = 0;
	*width = 0;
	while (*height < MAP_MAXSIZE && get_next_line(fd, &line) != -1 && line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[--len] = '\0';
		if (!len || is_empty_line(line) || !is_map_line(line))
		{
			free(line);
			continue ;
		}
		if (len > *width)
			*width = len;
		lines[(*height)++] = line;
	}
	return (lines);
}

static char	*build_cells(char **lines, int height, int width)
{
	char	*cells;
	int		i;
	int		len;

	cells = ft_calloc(width * height + 1, sizeof(char));
	if (!cells)
		return (NULL);
	i = -1;
	while (++i < height)
	{
		len = ft_strlen(lines[i]);
		ft_memcpy(cells + i * width, lines[i], len);
		while (len < width)
			cells[i * width + len++] = ' ';
	}
	return (cells);
}

int	assign_map(int fd, t_map *map)
{
	char	**lines;

	errno = 0;
	lines = collect_map_lines(fd, &map->height, &map->width);
	if (!lines)
		return (1);
	if (!map->height || errno)
	{
		if (!errno)
			ft_printf("Error: No map found in file\n");
		free_lines(lines, map->height);
		return (1);
	}
	if (map->width > MAP_MAXSIZE || map->height > MAP_MAXSIZE)
	{
		ft_printf(ERR_MAP_SIZE, MAP_MAXSIZE);
		free_lines(lines, map->height);
		return (1);
	}
	map->cells = build_cells(lines, map->height, map->width);
	free_lines(lines, map->height);
	if (!map->cells)
		return (1);
	return (0);
}

int	assign_player_pos(t_map *map)
{
	int	i;
	int	player_count;
	int	j;

	i = -1;
	player_count = 0;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (is_player_char(map->grid[i][j]))
			{
				player_count++;
				map->spawn.x = j;
				map->spawn.y = i;
				map->dir = map->grid[i][j];
			}
		}
	}
	if (player_count != 1)
		return (1);
	return (0);
}
