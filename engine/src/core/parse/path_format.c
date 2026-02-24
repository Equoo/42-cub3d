/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 04:43:58 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/24 04:03:19 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/parse.h"
#include "ft_printf.h"
#include "libft.h"

static int	suffix_format_checker(char *to_check, char *suffix)
{
	int	format_start;

	format_start = ft_strlen(to_check) - ft_strlen(suffix);
	if (ft_strncmp(&to_check[format_start], suffix, ft_strlen(suffix)) != 0)
		return (0);
	return (1);
}

static int	check_door_tex_path(t_map *map)
{
	int	fd;

	if (!map->door_tex_path
		|| !suffix_format_checker(map->door_tex_path, ".xpm"))
	{
		ft_printf(ERR_TEXTURE_PATH, map->door_tex_path);
		return (-1);
	}
	fd = open(map->door_tex_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf(ERR_TEXTURE_OPEN, 4, map->door_tex_path);
		return (-1);
	}
	close(fd);
	return (0);
}

int	door_texture_path_checker(t_map *map)
{
	int	i;
	int	fd;

	i = -1;
	while (++i < 4)
	{
		if (!suffix_format_checker(map->tex_paths[i], ".xpm"))
		{
			ft_printf(ERR_TEXTURE_PATH, map->tex_paths[i]);
			return (-1);
		}
		fd = open(map->tex_paths[i], O_RDONLY);
		if (fd == -1)
		{
			ft_printf(ERR_TEXTURE_OPEN, i, map->tex_paths[i]);
			return (-1);
		}
		close(fd);
	}
	return (check_door_tex_path(map));
}

int	map_path_checker(char *map_name, char **path)
{
	if (!suffix_format_checker(map_name, ".cub"))
	{
		ft_printf(ERR_MAP_FORMAT);
		return (0);
	}
	if (ft_strchr(map_name, '/') != NULL)
		*path = ft_strdup(map_name);
	else
		*path = ft_strjoin(MAP_FOLDER, map_name);
	if (!*path)
		return (0);
	return (1);
}

int	textures_path_checker(t_map *map)
{
	int	i;
	int	fd;

	i = -1;
	while (++i < 4)
	{
		if (!suffix_format_checker(map->tex_paths[i], ".xpm"))
		{
			ft_printf(ERR_TEXTURE_PATH, map->tex_paths[i]);
			return (-1);
		}
		fd = open(map->tex_paths[i], O_RDONLY);
		if (fd == -1)
		{
			ft_printf(ERR_TEXTURE_OPEN, i, map->tex_paths[i]);
			return (-1);
		}
		close(fd);
	}
	return (0);
}
