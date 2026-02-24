/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 22:18:22 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/24 03:47:00 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# if BONUS
#  define POSSIBLE_CHAR "01NWSED "
# else
#  define POSSIBLE_CHAR "01NWSE "
# endif

# define MAP_MAXSIZE 256
# define MAP_FOLDER "game/maps/"
# define MAP_FORMAT ".cub"

# define TEX_FOLDER "game/textures/"
# define TEX_FORMAT ".xpm"
# define TEX_NORTH "NO "
# define TEX_SOUTH "SO "
# define TEX_WEST "WE "
# define TEX_EAST "EA "
# define COL_FLOOR "F "
# define COL_CEILING "C "

# define DOOR_CHAR "D"
# define TEX_CLOSED_DOOR "CD "

# include "err.h"
# include "world.h"

// flood_fill.c
void	flood_fill(char **tab, int size_x, int size_y, t_vec2 begin);
int		check_surrounded_with_flood_fill(t_map *map);

// grid_build.c
int		build_map_grid(t_map *map);
char	**duplicate_map_grid(t_map *map);

// assign_textures.c
int		assign_textures_and_colors(int fd, t_map *map);
void	check_textures(char *tex_path, char *line, t_map *map, int valid[]);
int		check_floor_and_ceiling(char *line, t_map *map, int valid[]);

// assign.c
int		assign_map(int fd, t_map *map);
int		assign_player_pos(t_map *map);
int		dir_to_int(char c);

// door_bonus.c
int		texture_path_assign_bonus(char *line, t_map *map, int valid[]);
int		door_texture_path_checker(t_map *map);

// check.c
int		is_identifier_line(char *line);
int		is_empty_line(char *line);
int		is_map_line(char *line);
int		is_player_char(char c);

// debug.c
void	map_debug(t_map *map);

// err.c
int		properties_err(char *line, int valid[]);

// path_format.c
int		map_path_checker(char *map_name, char **path);
int		textures_path_checker(t_map *map);

// free.c
void	free_map_copy(char **dup, int height);
void	cleanup_map_resources(t_map *map);

// utils.c
int		secure_open(char *path, int *fd);
int		valid_properties(int valid[]);
int		valid_rgb_format(char *str);

// parse.c
int		map_init(char *map_name, t_map *map);

#endif
