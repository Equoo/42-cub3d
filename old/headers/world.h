/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:25:03 by dderny            #+#    #+#             */
/*   Updated: 2025/10/03 20:28:20 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2d.h"
#include "texture.h"
#include "colors.h"

typedef struct  s_tex_map {
    t_texture  *tex;
    t_vec2      uva;
    t_vec2      uvb;
    uint16_t    alpha;
}   t_tex_map;

// if texture NULL -> portal
typedef struct s_face {
	int32_t		portal;
	int32_t		portal_face;
    t_vec2      pos;
    t_rgba      color;
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

#define NSECTORS 2

typedef struct s_world {
    t_sector    **sectors; // replace to vec
    size_t      n_sectors;
}   t_world;

