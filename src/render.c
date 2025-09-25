/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:10:51 by dderny            #+#    #+#             */
/*   Updated: 2025/04/26 01:51:35 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "classes/element.h"
#include "cub3d.h"
#include "scene.h"
#include <errno.h>
#include <mlx.h>

#include "vector2d.h"
#include "colors.h"

typedef struct  s_tex_map {
    t_texture  *tex;
    t_vec2      uva;
    t_vec2      uvb;
    uint16_t    alpha;
}   t_tex_map;

// if texture NULL -> portal
typedef struct s_face {
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
    t_face      faces[4];
}   t_sector;

typedef struct  s_camera {
    t_vec3  pos;
    t_vec3  rot;
    int     fov;
}   t_camera;

#define NSECTORS 2

typedef struct s_world {
    t_sector    sectors[NSECTORS]; // replace to vec
    size_t      n_sectors;
}   t_world;

static int  is_inpolygon(t_face *points, int npoints, t_vec3 point)
{
    int     i;
    int     isleft;
    t_vec2  va;

    isleft = 1;
    i = 0;
    while (i < npoints)
    {
        va = vec2_sub(points[i].po, points[i + 1].pos);
        
    }
    return (0);
}

static t_sector *sector_from_pos(t_world *world, t_vec3 pos)
{
    size_t      i;
    t_sector    *sec;

    i = 0;
    while (i < world->n_sectors)
    {
        sec = world->sectors + i;
        if (is_inpolygon(sec->faces, sec->n_points, pos))
            return (sec);
        i++;
    }
    return (NULL);
}

#define RED 0xff00ffff
#define BLUE 0xffff00ff
#define GREEN 0xffffff00
#define RDM 0xfff0fef0

static void draw_world(t_render *render)
{
    int x;

    t_world     world = (t_world){.n_sectors = NSECTORS};
    world.sectors[0] = (t_sector){ 0, 100, {.rgba=0xffffffff}, {.rgba=0xfffffff}, 4, {
        {{-100, -100}, {.rgba=RED}},
        {{100, -100}, {.rgba=BLUE}},
        {{100, 100}, {.rgba=GREEN}},
        {{-100, 100}, {.rgba=RDM}}
    }};
    world.sectors[0] = (t_sector){ 0, 100, {.rgba=0xffffffff}, {.rgba=0xfffffff}, 4, {
        {{-100, -100}, {.rgba=RED}},
        {{100, -100}, {.rgba=BLUE}},
        {{100, 100}, {.rgba=GREEN}},
        {{-100, 100}, {.rgba=RDM}}
    }};
    t_camera    cam = (t_camera){.fov = 90};
    t_sector    *main_sector = sector_from_pos(&world, cam.pos);

    x = 0;
    while (x < render->width)
    {
        mylx_pixel_put(render->buffer, x, 100, 0xff15ffff);
        x++;
    }
}

void	tick_render(t_gameenv *env, t_render *render)
{
	t_img		*buffer;
	t_list		*node;
	t_element	*node_elem;

	node = ((t_scene *)env->scene)->elements;
	while (node)
	{
        draw_world(render);
		node_elem = (t_element *)node->content;
		if (node_elem->draw)
			node_elem->draw(node_elem, render);
		node = node->next;
	}
	buffer = render->buffer;
	render_texts(render, buffer);
	mlx_put_image_to_window(render->mlx, render->win,
		buffer, -ft_abs(buffer->width - render->width) / 2,
		-ft_abs(buffer->height - render->height) / 2);
}

int	render_init(t_gameenv *env)
{
	t_render	*render;

	render = &env->render;
	render->mlx = mlx_init();
	render->width = 1920;
	render->height = 1080;
	if (render->mlx)
		render->win = mlx_new_window(render->mlx, render->width,
				render->height, "So long");
	if (render->win)
		render->buffer = mlx_new_image(render->mlx, render->width,
				render->height);
	if (errno == EAGAIN)
		errno = 0;
	if (render->win)
		render->font = ft_texture(render, "textures/font.xpm");
	if (!render->buffer || !render->font || !render->win || !render->mlx)
		return (1);
	render->texts = vec_new(sizeof(t_rtext), 32);
	if (!render->texts)
		return (1);
	return (0);
}
