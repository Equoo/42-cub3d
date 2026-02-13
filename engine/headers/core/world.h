

#ifndef WORLD_H
# define WORLD_H
# include <stdint.h>
# include "types/vector2.h"
# include "core/draw.h"
# include "core/camera.h"

# define TRACE_LEN 65536

typedef struct {
    t_image		tex;
    t_vec2		uva;
    t_vec2		uvb;
    uint16_t	alpha;
}   t_tex_map;

typedef enum {
    NORTH = 0,
    SOUTH = 1,
	EAST = 2,
    WEST = 3
} t_orient;

typedef struct {
	int			hit;
	t_vec2		pos;
	t_orient	dir;
	float		dist;
}	t_hit;

typedef struct {
	t_vec2 sided;
	t_vec2 deltad;
	t_vec2 step;
}	t_dda;

typedef struct {
	char		*cells;
	int			width;
	int			height;
	t_tex_map	textures[4];
}	t_map;

int  draw_walls(t_image *buffer, t_map map, t_camera cam);

#endif
