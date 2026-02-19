/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 22:18:22 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/19 06:35:20 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define POSSIBLE_CHAR "01NWSE "

# define MAP_FOLDER "game/maps/"
# define TEXTURE_FOLDER "game/textures/"
# define MAP_FORMAT ".cub"
# define MAP_MAXSIZE 1024
# define MAP_NORTH "NO "
# define MAP_SOUTH "SO "
# define MAP_WEST "WE "
# define MAP_EAST "EA "
# define MAP_FLOOR "F "
# define MAP_CEILING "C "

# include "world.h"


void	flood_fill(char **tab, int size_x, int size_y, t_vec2 begin);

// parse_checker.c
void	check_textures(char *tex_path, char *line, t_map *map, int valid[]);
int		check_floor_and_ceiling(char *line, t_map *map, int valid[]);
int		check_player_position(t_map *map);
int		possible_char_checker(t_map *map);

// parse debug
void	map_debug(t_map *map);

// parse_files.c
int		map_path_checker(char *map_name, char **path);
int		textures_path_checker(t_map *map);

// parse_utils.c
int		secure_open(char *path, int *fd);
int		is_empty_line(char *line);
int		assign_textures_and_colors(int fd, t_map *map);
void	free_map_copy(char **dup, int height);

// parse.c
int		check_map_validity(char *map_name, t_map *map);
int		build_map_grid(t_map *map);

#endif
