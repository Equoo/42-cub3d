/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:14:21 by dderny            #+#    #+#             */
/*   Updated: 2026/02/14 16:16:53 by dderny                  ###   ########   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H
# include "core/camera.h"
# include "types/image.h"
# include "types/rgba.h"
# include "types/vector2.h"
# include <stdint.h>

# define TRACE_LEN 65536

typedef struct s_tex_map
{
	t_image		tex;
	t_vec2		uva;
	t_vec2		uvb;
	uint16_t	alpha;
}				t_tex_map;

typedef enum e_orient
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
}				t_orient;

typedef struct s_hit
{
	int			hit;
	t_vec2		pos;
	t_orient	dir;
	float		dist;
}				t_hit;

typedef struct s_dda
{
	t_vec2		sided;
	t_vec2		deltad;
	t_vec2		step;
}				t_dda;

typedef struct s_map
{
	char		*cells;
	int			width;
	int			height;
	t_tex_map	textures[4];
	char		*tex_paths[4];
	t_rgba		ceiling;
	t_rgba		floor;
}				t_map;

int				draw_walls(t_image *buffer, t_map map, t_camera cam);

#endif
