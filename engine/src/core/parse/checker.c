/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 03:00:01 by dderny            #+#    #+#             */
/*   Updated: 2026/02/20 21:02:49 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/parse.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"

void	check_textures(char *tex_path, char *line, t_map *map, int valid[])
{
	if (ft_strncmp(line, TEX_NORTH, 3) == 0)
	{
		map->tex_paths[0] = tex_path;
		valid[0]++;
	}
	else if (ft_strncmp(line, TEX_SOUTH, 3) == 0)
	{
		map->tex_paths[1] = tex_path;
		valid[1]++;
	}
	else if (ft_strncmp(line, TEX_WEST, 3) == 0)
	{
		map->tex_paths[2] = tex_path;
		valid[2]++;
	}
	else if (ft_strncmp(line, TEX_EAST, 3) == 0)
	{
		map->tex_paths[3] = tex_path;
		valid[3]++;
	}
}

int	check_floor_and_ceiling(char *line, t_map *map, int valid[])
{
	int		i;
	t_rgba	color;

	i = 2;
	while (line[i] == ' ')
		i++;
	color.rgb = 0;
	if (ft_strncmp(line, COL_FLOOR, 2) == 0)
	{
		if (rgba_from_str(line + i, &color))
			return (1);
		map->floor = color;
		valid[4]++;
	}
	else if (ft_strncmp(line, COL_CEILING, 2) == 0)
	{
		if (rgba_from_str(line + i, &color))
			return (1);
		map->ceiling = color;
		valid[5]++;
	}
	return (0);
}

int	check_possible_char(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->cells[++i])
	{
		if (map->cells[i] == '\n')
			continue ;
		j = 0;
		while (POSSIBLE_CHAR[j])
		{
			if (map->cells[i] != POSSIBLE_CHAR[j])
				j++;
			else
				break ;
			if (j >= 7)
				return (1);
		}
	}
	return (0);
}

static int	append_line_to_result(char **result, char *line)
{
	char	*temp;

	if (!*result)
	{
		*result = ft_strdup(line);
		if (!*result)
			return (-1);
	}
	else
	{
		temp = ft_strjoin(*result, "\n");
		free(*result);
		if (!temp)
			return (-1);
		*result = ft_strjoin(temp, line);
		free(temp);
		if (!*result)
			return (-1);
	}
	return (0);
}

int	check_map_format(t_map *map, char *line, char **result, int *i)
{
	int	line_len;

	if (!line || !line[0] || is_empty_line(line))
	{
		free(line);
		return (0);
	}
	if (line[0] == '0' || line[0] == '1' || line[0] == ' ')
	{
		line_len = ft_strlen(line);
		if (line[line_len - 1] == '\n')
			line[line_len - 1] = '\0';
		if (ft_strlen(line) > (unsigned long)map->width)
			map->width = ft_strlen(line);
		if (append_line_to_result(result, line) == -1)
			return (-1);
		free(line);
		map->cells = *result;
		(*i)++;
	}
	return (0);
}
