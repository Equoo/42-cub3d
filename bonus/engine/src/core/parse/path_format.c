/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 04:43:58 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/21 01:57:12 by zsonie           ###   ########lyon.fr   */
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
	if (ft_strchr(map_name, '/') != NULL)
		*path = ft_strdup(map_name);
	else
		*path = ft_strjoin(MAP_FOLDER, map_name);
	if (!*path)
		return (0);
	return (1);
}

static int	check_xpm_format(char *path)
{
	int		fd;
	char	header[9];
	int		bytes_read;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: Cannot open texture file: %s\n", path);
		return (1);
	}
	bytes_read = read(fd, header, 8);
	close(fd);
	if (bytes_read < 8)
	{
		ft_printf("Error: Texture file too small: %s\n", path);
		return (1);
	}
	header[8] = '\0';
	if (ft_strncmp(header, "/* XPM */", 8) != 0)
	{
		ft_printf("Error: Invalid XPM header in: %s\n", path);
		return (1);
	}
	return (0);
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
		if (check_xpm_format(map->tex_paths[i]))
		{
			ft_printf(ERR_XPM_FORMAT, i);
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
