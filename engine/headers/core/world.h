/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:14:21 by dderny            #+#    #+#             */
/*   Updated: 2026/02/27 09:25:33 by zsonie           ###   ########lyon.fr   */
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

# define MMAP_OFFSET 100
# define SIZE 200
# define SIZEHALF 100
# define ZOOM 15.f
# define ZOOM_MIN 3.f
# define ZOOM_MAX 30.f
# define ZOOM_STEP 1.f
# define MMAP_PLY_SIZE 3.f

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
	char		cell;
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
	char		**grid;
	int			width;
	int			height;
	t_image		textures[4];
	char		*tex_paths[4];
	t_image		door_texture;
	char		*door_tex_path;
	t_rgba		ceiling;
	t_rgba		floor;
	t_vec2		spawn;
	char		dir;
}				t_map;

typedef struct s_draw_ctx
{
	t_image		*buffer;
	t_image		img;
	t_map		map;
	int			x;
	int			half_height;
}				t_draw_ctx;

int				is_inmap(t_vec2 pos, t_map *map);

void			calc_wall_dimensions(t_wall_params *params, float dist,
					int buffer_height);
void			calc_texture_params(t_wall_params *params, t_hit hit,
					t_image img);
float			calc_sky_darkness(int y, float inv_half_height);

void			draw_wall(t_draw_ctx ctx, float dist, t_hit hit);

int				draw_walls(t_image *buffer, t_map map, t_camera cam);

int				map_destroy(void *mlx, t_map *map);

int				load_map(void *mlx, t_map *map);

void			draw_minimap(t_image *buffer, t_map *map, t_camera camera,
					float zoom);

#endif
