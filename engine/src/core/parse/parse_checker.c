/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 03:00:01 by dderny            #+#    #+#             */
/*   Updated: 2026/02/15 03:00:04 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/parse.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"

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

int	map_path_checker(char *map_name, char **path)
{
	ft_printf("map: %s\n", map_name);
	if (!suffix_format_checker(map_name, ".cub"))
		return (0);
	*path = ft_strjoin(MAP_FOLDER, map_name);
	if (!*path)
	{
		free(*path);
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
	else if (ft_strncmp(line, MAP_SOUTH, 3) == 0)
	{
		map->tex_paths[1] = tex_path;
		valid[1]++;
	}
	else if (ft_strncmp(line, MAP_WEST, 3) == 0)
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
	if (ft_strncmp(line, MAP_FLOOR, 2) == 0)
	{
		if (rgba_from_str(line + i, &color))
			return (1);
		map->floor = color;
		valid[4]++;
	}
	else if (ft_strncmp(line, MAP_CEILING, 2) == 0)
	{
		if (rgba_from_str(line + i, &color))
			return (1);
		map->ceiling = color;
		valid[5]++;
	}
	return (0);
}

int	textures_path_checker(t_map *map)
{
	int	i;
	int	fd;

<<<<<<< HEAD
	i = 0;
	while (i < 4)
	{
		map->tex_paths[i][ft_strlen(map->tex_paths[i]) - 1] = '\0';
		if (!suffix_format_checker(map->tex_paths[i], ".xpm\0"))
		{
			ft_printf("Error:\nTexturespath issue at index[%d]\n", i);
			return (-1);
		}
=======
	i = 0;
	while (i < 4)
	{
		map->tex_paths[i][ft_strlen(map->tex_paths[i]) - 1] = '\0';
		if (!suffix_format_checker(map->tex_paths[i], ".xpm\0"))
		{
			ft_printf("Error:\nTexturespath issue at index[%d]\n", i);
			return (-1);
		}
		ft_printf("Debug: tex_paths[%d]: %s\n", i, map->tex_paths[i]);
>>>>>>> 40422ca (add: map destroying)
		fd = open(map->tex_paths[i], O_RDONLY);
		if (fd == -1)
		{
			ft_printf("Error:\nopen issue at index[%d]\n", i);
			close(fd);
			return (-1);
		}
		i++;
	}
	return (0);
}
