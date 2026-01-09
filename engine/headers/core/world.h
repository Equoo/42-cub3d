

#ifndef WORLD_H
# define WORLD_H
# include <stdint.h>
# include "types/vector2.h"
# include "core/draw.h"

typedef struct s_worldhit {
	t_vec2	pos;
	int		sector;
	int		face;
}	t_hit;

typedef struct  s_tex_map {
    t_image		*tex;
    t_vec2		uva;
    t_vec2		uvb;
    uint16_t	alpha;
}   t_tex_map;

typedef struct s_face {
	int32_t		portal;
	int32_t		portal_face;
    t_vec2		pos;
    t_rgba		color;
    //t_tex_map   *texture;
}   t_face;

// Minimum 4 faces;
// have to be CONVEX
typedef struct s_sector {
    float       pos_z;
    float       height;
    //t_tex_map   *top_face;
    //t_tex_map   *bot_face;
    t_rgba      top_face;
    t_rgba      bot_face;
    int         n_points;
    t_face      faces[];
}   t_sector;

typedef struct s_world {
    t_sector    **sectors;
    size_t      n_sectors;
}   t_world;

#endif
