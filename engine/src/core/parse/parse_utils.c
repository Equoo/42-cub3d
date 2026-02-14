/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 06:31:54 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/14 16:57:12 by dderny                  ###   ########   */
/*                                                                            */
/* ************************************************************************** */

#include "core/parse.h"
#include "libft.h"
#include "types/rgba.h"

int	suffix_format_checker(char *to_check, char *suffix)
{
	int	format_start;

	format_start = ft_strlen(to_check) - ft_strlen(suffix);
	if (ft_strncmp(&to_check[format_start], suffix, ft_strlen(suffix)) != 0)
	{
		perror("Error\n: Wrong format\n");
		return (0);
	}
	return (1);
}

void	check_textures(char *tex_path, char *line, t_map *map, int valid[])
{
	if (ft_strncmp(line, MAP_NORTH, 3) == 0)
	{
		map->tex_paths[0] = tex_path;
		valid[0]++;
	}
	else if (ft_strncmp(line, MAP_WEST, 3) == 0)
	{
		map->tex_paths[1] = tex_path;
		valid[1]++;
	}
	else if (ft_strncmp(line, MAP_SOUTH, 3) == 0)
	{
		map->tex_paths[2] = tex_path;
		valid[2]++;
	}
	else if (ft_strncmp(line, MAP_EAST, 3) == 0)
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
	if (rgba_from_str(&line[i] + 2, &color))
		return (1);
	if (ft_strncmp(line, MAP_FLOOR, 2) == 0)
	{
		map->floor = color;
		valid[4]++;
	}
	else if (ft_strncmp(line, MAP_CEILING, 2) == 0)
	{
		map->ceiling = color;
		valid[5]++;
	}
	return (0);
}
