/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 22:18:22 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/20 20:53:12 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define POSSIBLE_CHAR "01NWSE "

# define MAP_FOLDER "game/maps/"
# define TEXTURE_FOLDER "game/textures/"
# define MAP_FORMAT ".cub"
# define MAP_MAXSIZE 1024
# define TEX_NORTH "NO "
# define TEX_SOUTH "SO "
# define TEX_WEST "WE "
# define TEX_EAST "EA "
# define COL_FLOOR "F "
# define COL_CEILING "C "

# define ERR_TEXTURE_PATH "Error: Texture path format issue: %s\n"
# define ERR_TEXTURE_OPEN "Error: Cannot open texture at index[%d]: %s\n"
# define ERR_XPM_FORMAT "Error: XPM validation failed at index[%d]\n"
# define ERR_SURROUNDED_SPACE "Error: Map not properly surrounded\
 - space reached from filled area\n"
# define ERR_SURROUNDED_EDGE "Error: Map not properly surrounded\
 - filled area touches edge\n"

# include "world.h"

// flood_fill.c
void	flood_fill(char **tab, int size_x, int size_y, t_vec2 begin);
int		check_surrounded_with_flood_fill(t_map *map);

// grid_build.c
int		build_map_grid(t_map *map);
char	**duplicate_map_grid(t_map *map);

// parse_assign.c
int		assign_map(int fd, t_map *map);
int		assign_player_pos(t_map *map);
int		assign_textures_and_colors(int fd, t_map *map);

// parse_checker.c
void	check_textures(char *tex_path, char *line, t_map *map, int valid[]);
int		check_floor_and_ceiling(char *line, t_map *map, int valid[]);
int		check_possible_char(t_map *map);
int		check_map_format(t_map *map, char *line, char **result, int *i);

// parse_debug.c
void	map_debug(t_map *map);

// parse_files.c
int		map_path_checker(char *map_name, char **path);
int		textures_path_checker(t_map *map);

// parse_free.c
void	free_map_copy(char **dup, int height);
void	cleanup_map_resources(t_map *map);

// parse_utils.c
int		secure_open(char *path, int *fd);
int		is_empty_line(char *line);
int		is_player_char(char c);

// parse.c
int		map_init(char *map_name, t_map *map);

#endif
