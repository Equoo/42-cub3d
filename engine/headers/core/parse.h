/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 22:18:22 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/13 22:46:47 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#define POSSIBLE_CHAR "01NWSE"
#define FLOOR "0"
#define WALL "1"
#define NORTH "N"
#define SOUTH "S"
#define WEST "W"
#define EAST "E"

#define MAP_FOLDER "game/maps/"
#define MAP_FORMAT ".cub"
#define MAP_MAXSIZE 1024
#define MAP_NORTH "NO "
#define MAP_SOUTH "SO "
#define MAP_WEST "WE "
#define MAP_EAST "EA "
#define MAP_FLOOR "F "
#define MAP_CEILING "C "

#include "world.h"

int check_map_validity(char *map_name, t_map *map);

#endif