/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:08:27 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/27 09:25:55 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/parse.h"
#include "ft_printf.h"
#include "libft.h"

static void	check_door_texture(char *tex_path, char *line, t_map *map)
{
	if (ft_strncmp(line, TEX_CLOSED_DOOR, 3) == 0)
		map->door_tex_path = tex_path;
}

int	texture_path_assign_bonus(char *line, t_map *map, int valid[])
{
	int		i;
	int		len;
	char	*tex_path;

	if (ft_strncmp(line, TEX_NORTH, 3) == 0 || ft_strncmp(line, TEX_WEST,
			3) == 0 || ft_strncmp(line, TEX_SOUTH, 3) == 0 || ft_strncmp(line,
			TEX_EAST, 3) == 0 || ft_strncmp(line, TEX_CLOSED_DOOR, 3) == 0)
	{
		i = 3;
		while (line[i] == ' ')
			i++;
		tex_path = ft_strdup(&line[i]);
		if (!tex_path)
			return (1);
		len = ft_strlen(tex_path);
		if (len > 0 && tex_path[len - 1] == '\n')
			tex_path[len - 1] = '\0';
		check_textures(tex_path, line, map, valid);
		check_door_texture(tex_path, line, map);
		return (0);
	}
	if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		return (check_floor_and_ceiling(line, map, valid));
	return (0);
}
