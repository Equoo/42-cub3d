/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:14:21 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 03:50:09 by dderny           ###   ########.fr       */
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
# define PROJECTION_SCALE 1200.0f
# define DIST_ATTENUATION 0.8f
# define DIST_OFFSET 0.3f
# define MIN_DARKNESS 0.05f
# define MAX_DARKNESS 1.0f
# define HALF_DIVISOR 2.0f
# define RAYS_FILLING 1
# define RAYS_DENSITY 1

typedef struct s_wall_params
{
	int			w_height;
	int			s_height;
	float		img_off;
	float		img_step;
	uint		img_x;
	int			wall_start_y;
}				t_wall_params;

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
	t_image		textures[4];
	char		*tex_paths[4];
	t_rgba		ceiling;
	t_rgba		floor;
	t_vec2		spawn;
}				t_map;

typedef struct s_draw_ctx
{
	t_image		*buffer;
	t_image		img;
	t_map		map;
	int			x;
	int			half_height;
}				t_draw_ctx;

void			calc_wall_dimensions(t_wall_params *params, float dist,
					int buffer_height);
void			calc_texture_params(t_wall_params *params, t_hit hit,
					t_image img);
float			calc_sky_darkness(int y, float inv_half_height);

void			draw_wall(t_draw_ctx ctx, float dist, t_hit hit);

int				draw_walls(t_image *buffer, t_map map, t_camera cam);

int				map_destroy(void *mlx, t_map *map);

int				load_map(void *mlx, t_map *map);

#endif
