/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:10:51 by dderny            #+#    #+#             */
/*   Updated: 2025/09/28 22:14:06 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "classes/element.h"
#include "cub3d.h"
#include "scene.h"
#include <errno.h>
#include <mlx.h>



#include <math.h>

inline void put_pixel(const t_image img, const int x, const int y, const u_int color)
{
	img.data[y * img.size_line + x] = color;
}

void draw_line(const t_image img, const t_vec2 p1, const t_vec2 p2, const u_int color)
{
	double dx = p2.x - p1.x;
	double dy = p2.y - p1.y;
	int steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
	double x_inc = dx / (double)steps;
	double y_inc = dy / (double)steps;
	double x = p1.x;
	double y = p1.y;

	for (int i = 0; i <= steps; i++)
	{
		if (x < 0 || x >= img.width || y < 0 || y >= img.height)
			break;
		put_pixel(img, (int)x, (int)y, color);
		x += x_inc;
		y += y_inc;
	}
}

void draw_square(const t_image img, const t_vec2 p1, const t_vec2 p2, const u_int color)
{
	int x;
	int y;
	int x_end;
	int y_end;
	
	x = ft_clamp(p1.x, 0, img.width - 1);
	y = ft_clamp(p1.y, 0, img.height - 1);
	x_end = ft_clamp(p2.x, 0, img.width - 1);
	y_end = ft_clamp(p2.y, 0, img.height - 1);
	while (y < y_end)
	{
		ft_memsetint(img.data + y * img.size_line + x, color, (x_end - x));
		y++;
	}
}



#include "vector2d.h"
#include "colors.h"
#include <math.h>

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
    t_face      faces[5];
}   t_sector;

#define NSECTORS 2

typedef struct s_world {
    t_sector    sectors[NSECTORS]; // replace to vec
    size_t      n_sectors;
}   t_world;

int is_left(t_vec2 *a, t_vec2 *b)
{
    return (-a->x * b->y + a->y * b->x < 0);
}

static int  is_inpolygon(t_face *points, int npoints, t_vec3 point)
{
    int     i;
    int     next;
    int     isleft;
    t_vec2  va;
    t_vec2  vb;

    isleft = 1;
    i = 0;
    while (i < npoints)
    {
        next = (i + 1) % npoints;
        va = vec2_sub(points[i].pos, points[next].pos);
        vb = vec2_sub((t_vec2){point.x, point.y}, points[next].pos);
        //__builtin_printf("Npoints: %i, i %i, a(%f, %f), b(%f, %f), va(%f, %f), vb(%f, %f), Isleft %i\n", npoints, i, points[i].pos.x, points[i].pos.y, points[i + 1].pos.x, points[i + 1].pos.y, va.x, va.y, vb.x, vb.y, is_left(&vb, &va));
        if (!is_left(&vb, &va)) {
            isleft = 0;
            break ;
        }
        i++;
    }
    return (isleft);
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


    /* Direction vector of the segment */
    /* Vector from line origin to segment start */
    /* Compute cross products */
    
    /* Check if line and segment are parallel */

    /* Solve for parameters t (line) and u (segment)
     * Line: P = linePos + t * lineDir
     * Segment: Q = segA + u * segDir, where u ∈ [0, 1]
     */
    /* Check if intersection point lies on the segment (u must be in [0, 1]) */
    /* Compute intersection point if requested */

static  int intersect_line_segment(const t_vec2 line_pos,
                         t_vec2 line_dir,
                         const t_2vec2 seg,
                          t_vec2* hit_pos)
{
    t_vec2 seg_dir = {seg.b.x - seg.a.x, seg.b.y - seg.a.y};
    t_vec2 diff = {seg.a.x - line_pos.x, seg.a.y - line_pos.y};
    float cross_dirs = vec2_cross(&line_dir, &seg_dir);
    if (fabsf(cross_dirs) < 1e-6f)
        return (0);    
    float u = vec2_cross(&diff, &line_dir) / cross_dirs;
    if (u < 0.0f || u > 1.0f)
        return (0);
    float t = vec2_cross(&diff, &seg_dir) / cross_dirs;
    hit_pos->x = line_pos.x + line_dir.x * t;
    hit_pos->y = line_pos.y + line_dir.y * t;
    return (1);
}

static int  trace_wall(t_sector sector, t_vec2 pos, float angle, t_vec2 *hit_pos)
{
    t_vec2  dir = {cos(angle), sin(angle)};
    t_vec2  hit_dir;
    int     i;

    i = 0;
    while (i < sector.n_points)
    {
        if (intersect_line_segment(pos, dir, (t_2vec2){sector.faces[i].pos, sector.faces[(i + 1) % sector.n_points].pos}, hit_pos))
        {
            hit_dir = vec2_sub(*hit_pos, pos);
            if (vec2_dot(&dir, &hit_dir) > 0)
                return (1);
        }
        i++;
    }
    __builtin_printf("EHYYY;\n");
    return (0);
}

static int draw_wall(t_render *render, int x, t_vec2 origin, t_vec2 hit_pos)
{
    float length = vec2_length(vec2_sub(origin, hit_pos));
    int height = 1 / length * 500000;
    int i = 0;
    while (i < height)
        put_pixel(render->buffer_img, 200 + x, 1080 / 2 - height / 2 + i++, 0xffeeee00);
    return (0);
}

static int  draw_walls(t_render *render, t_world world, t_camera cam, t_sector first_sec)
{
    const int   rays = render->width - 200;
    const int   slice_width = render->width / rays;
    const float angle_steps = (float)cam.fov / (float)rays;
    int         i;
    float       ray_angle;
    t_vec2      hit_pos;

    (void)slice_width;
    (void)world;
    i = 0;
    while (i < rays)
    {
        ray_angle = (M_PI / 180) * (cam.rot.z - ((float)cam.fov / 2) + i * angle_steps);
        t_vec2 off = (t_vec2){100, 500};
        t_vec2 origin = vec2_add(vec2_scale_dived((t_vec2){cam.pos.x, cam.pos.y}, 12), off);
        if (trace_wall(first_sec, (t_vec2){cam.pos.x, cam.pos.y}, ray_angle, &hit_pos))
        {
            draw_wall(render, i, (t_vec2){cam.pos.x, cam.pos.y}, hit_pos);
            draw_line(render->buffer_img, origin, vec2_add(vec2_scaled((t_vec2){cos(ray_angle), sin(ray_angle)}, 100), origin), 0xff00ff00);
            put_pixel(render->buffer_img, 200 + hit_pos.x / 12, 500 + hit_pos.y / 12, 0xff0000ff);
        }
        else
            draw_line(render->buffer_img, origin, vec2_add(vec2_scaled((t_vec2){cos(ray_angle), sin(ray_angle)}, 100), origin), 0xffff0000);
        i++;
    }
    return (0);
}

#define RED 0xff00ffff
#define BLUE 0xffff00ff
#define GREEN 0xffffff00
#define RDM 0xfff0fef0

static void draw_world(t_render *render)
{
    t_world     world = (t_world){.n_sectors = NSECTORS};
    world.sectors[0] = (t_sector){ 0, 100, {.rgba=0xffffffff}, {.rgba=0xfffffff}, 5, {
        {{-1000, -1000}, {.rgba=RED}},
        {{1000, -1000}, {.rgba=BLUE}},
        {{1000, 1000}, {.rgba=GREEN}},
        {{0, 1450}, {.rgba=RDM}},
        {{-1000, 1000}, {.rgba=RDM}}
    }};
    world.sectors[1] = (t_sector){ 0, 100, {.rgba=0xffffffff}, {.rgba=0xfffffff}, 5, {
        {{-100, -200}, {.rgba=RED}},
        {{100, -200}, {.rgba=BLUE}},
        {{100, -100}, {.rgba=GREEN}},
        {{-100, -100}, {.rgba=RDM}},
        {{-100, -100}, {.rgba=RDM}}
    }};
    t_sector    *main_sector = sector_from_pos(&world, render->camera.pos);

    draw_square(render->buffer_img, (t_vec2){0, 400}, (t_vec2){300, 600}, 0xff999999);
    int i = 0;
    t_vec2 off = (t_vec2){100, 500}; 
    while (i < main_sector->n_points)
    {
        t_face face_a = main_sector->faces[i];
        t_face face_b = main_sector->faces[(i + 1) % main_sector->n_points];
        draw_line(render->buffer_img, vec2_add(vec2_scale_dived(face_a.pos, 12), off), vec2_add(vec2_scale_dived(face_b.pos, 12), off), face_a.color.rgba);
        i++;
    }

    draw_walls(render, world, render->camera, *main_sector);
}

void	tick_render(t_gameenv *env, t_render *render)
{
	t_img		*buffer;
	t_list		*node;
	t_element	*node_elem;

    draw_world(render);
	node = ((t_scene *)env->scene)->elements;
	while (node)
	{
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
	if (errno == EAGAIN)
		errno = 0;
	if (render->win)
		render->font = ft_texture(render, "textures/font.xpm");
	if (!render->font || !render->win || !render->mlx)
		return (1);
	render->texts = vec_new(sizeof(t_rtext), 32);
	if (!render->texts)
		return (1);
	return (0);
}
