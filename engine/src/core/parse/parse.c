/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:06:36 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/13 23:57:14 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/parse.h"
#include "core/world.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

// int	init_img_from_xpm(t_gameenv *env)
// {
// 	set_path_and_size(env);
// 	if (texture_check_and_init(env, &env->img.img_wall, env->img.wall_path))
// 		return (1);
// 	if (texture_check_and_init(env, &env->img.img_ground, env->img.ground_path))
// 		return (1);
// 	if (texture_check_and_init(env, &env->img.img_exit, env->img.exit_path))
// 		return (1);
// 	if (texture_check_and_init(env, &env->img.img_collect, env->img.coin_path))
// 		return (1);
// 	if (texture_check_and_init(env, &env->img.img_player, env->img.player_path))
// 		return (1);
// 	if (texture_check_and_init(env, &env->img.img_player_exit,
// 			env->img.player_exit_path))
// 		return (1);
// 	return (0);
// }

static int	format_check(char *to_check, char *format)
{
	int	format_start;

	format_start = ft_strlen(to_check) - ft_strlen(format);
	if (ft_strncmp(&to_check[format_start], format,
			ft_strlen(format)) != 0)
	{
		perror("Error\n: Wrong format\n");
		return (0);
	}
	return (1);
}
static void	check_textures(char *tex_path, char *line, t_map *map, int valid[])
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

static void check_floor_and_ceiling(char *line, t_map *map, int valid[])
{
	int i;
	char *color;

	i = 2;
	while(line[i] == ' ')
		i++;
	color = ft_strdup(&line[i]);
	if (ft_strncmp(line, MAP_FLOOR, 2) == 0)
	{
		map->colors[0] = color;
		valid[4]++;
	}
	else if (ft_strncmp(line, MAP_CEILING, 2) == 0)
	{
		map->colors[1] = color;
		valid[5]++;
	}
}

static int	texture_path_assign(char *line, t_map *map, int valid[])
{
	int		i;
	char	*tex_path;

	if (ft_strncmp(line, MAP_NORTH, 3) == 0 || ft_strncmp(line, MAP_WEST,
			3) == 0 || ft_strncmp(line, MAP_SOUTH, 3) == 0 || ft_strncmp(line,
			MAP_EAST, 3) == 0 || ft_strncmp(line, MAP_FLOOR, 2) == 0
		|| ft_strncmp(line, MAP_CEILING, 2) == 0)
	{
		i = 3;
		while (line[i] == ' ')
			i++;
		tex_path = ft_strdup(&line[i]);
		check_textures(tex_path, line, map, valid);
		check_floor_and_ceiling(line, map, valid);
	}
	else
	{
		ft_printf("Wrong input into map file\n");
		return 1;
	}
	return (0);
}

int	check_map_validity(char *map_name, t_map *map)
{
	char	*line;
	int		fd;
	int		i;
	char	*path;
	int		valid[6];

	i = -1;
	while (++i < 7)
		valid[i] = 0;
	if (!format_check(map_name, MAP_FORMAT))
		return (0);
	path = ft_strjoin(MAP_FOLDER, map_name);
	if (!path)
	{
		free(path);
		return (0);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free(path);
		close(fd);
		perror("Error\n");
		return (0);
	}
	i = 0;
	while ((line = get_next_line(fd)) != 0)
	{
		// ft_printf("line= %s", line);
		// ft_printf("i= %d\n", i);
		texture_path_assign(line, map, valid);
		i++;
	}
	
	i = 0;
	while (i < 6)
	{
		ft_printf("valid[%d]= %d\n", i, valid[i]);
		i++;
	}
	return (1);
}
