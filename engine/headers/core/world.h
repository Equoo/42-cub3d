

#ifndef WORLD_H
# define WORLD_H
# include <stdint.h>
# include "types/vector2.h"
# include "core/draw.h"
# include "core/camera.h"

# define TRACE_LEN 1000
//65536

typedef struct {
    t_image		*tex;
    t_vec2		uva;
    t_vec2		uvb;
    uint16_t	alpha;
}   t_tex_map;

typedef struct {
	int32_t		portal;
	int32_t		portal_face;
    t_vec2		pos;
    t_rgba		color;
    //t_tex_map   *texture;
}   t_face;

typedef struct {
	int		hit;
	t_vec2	pos;
	int		dir;
	float	dist;
}	t_hit;

typedef struct {
	char *cells;
	int width;
	int	height;
}	t_map;

int  draw_walls(t_image *buffer, t_map map, t_camera cam);

#endif
