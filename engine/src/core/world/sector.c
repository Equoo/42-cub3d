
#include "core/draw.h"
#include "core/world.h"
#include "core/camera.h"
#include "math/extend.h"
#include "types/vector2.h"

static int is_left(t_vec2 *a, t_vec2 *b)
{
    return (-a->x * b->y + a->y * b->x < 0);
}

static int  is_inpolygon(t_face *points, int npoints, t_vec2 point)
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
        vb = vec2_sub(point, points[next].pos);
        if (!is_left(&vb, &va)) {
            isleft = 0;
            break ;
        }
        i++;
    }
    return (isleft);
}


int sector_from_pos(t_world *world, t_vec2 pos)
{
    size_t      i;
    t_sector    *sec;

    i = 0;
    while (i < world->n_sectors)
    {
        sec = world->sectors[i];
        if (is_inpolygon(sec->faces, sec->n_points, pos))
            return (i);
        i++;
    }
    return (-1);
}

static int  trace_wall(t_sector **sectors, int sec_id, t_vec2 pos, float angle, t_hit *hit, int face_ignore)
{
	t_vec2  	dir = {cos(angle), sin(angle)};
	t_vec2  	hit_dir;
	int     	i;
	const t_sector	*sector = sectors[sec_id];

	i = 0;
	while (i < sector->n_points)
	{
		if (i != face_ignore && intersect_line_segment((t_intersect){
					pos, dir, sector->faces[i].pos, sector->faces[(i + 1) % sector->n_points].pos, &hit->pos
					}))
		{
			hit_dir = vec2_sub(hit->pos, pos);
			if (vec2_dot(dir, hit_dir) > 0)
			{
				if (sector->faces[i].portal != -1)
				{
					return (trace_wall(sectors, sector->faces[i].portal, pos, angle, hit, sector->faces[i].portal_face));
				}
				else
				{
					hit->sector = sec_id;
					hit->face = i;
					return (1);
				}
			}
		}
		i++;
	}
	return (0);
}

static int draw_wall(t_image *buffer, int x, t_vec2 origin, t_vec2 hit_pos)
{
    float length = vec2_len(vec2_sub(origin, hit_pos));
    int height = 1 / length * 500000;
    int i = 0;
	const float dark = 1 - 0.05 - (length / 4000);
	const t_rgba color = (t_rgba){.r=190*dark, .g=190*dark, .b=134*dark};
    while (i < height)
        draw_pixel(buffer, 200 + x, 1080 / 2 - height / 2 + i++, color);
    return (0);
}

int  draw_walls(t_image *buffer, t_world world, t_camera cam, int first_sec)
{
    const int   rays = buffer->width - 200;
    // const int   slice_width = render->width / rays;
    const float angle_steps = (float)cam.fov / (float)rays;
	const int	rays_filling = 1;
    int         i;
    float       ray_angle;
    t_hit      	hit;

    i = 0;
    while (i < rays)
    {
		if (i % rays_filling && ++i)
			continue;
        ray_angle = (M_PI / 180) * (cam.rot.z - ((float)cam.fov / 2) + i * angle_steps);
        t_vec2 off = (t_vec2){100, 500};
        t_vec2 origin = vec2_add(vec2_divf((t_vec2){cam.pos.x, cam.pos.y}, 20), off);
        if (trace_wall(world.sectors, first_sec, (t_vec2){cam.pos.x, cam.pos.y}, ray_angle, &hit, -1))
        {
            draw_wall(buffer, i, (t_vec2){cam.pos.x, cam.pos.y}, hit.pos);
            draw_line(buffer, origin, vec2_add(vec2_mulf((t_vec2){
							cos_lut(ray_angle), sin_lut(ray_angle)}, 100), origin), (t_rgba)0xff00ff00);
            draw_pixel(buffer, 100 + hit.pos.x / 20, 500 + hit.pos.y / 20, (t_rgba)0xff0000ff);
        }
        else
            draw_line(buffer, origin, vec2_add(vec2_muli((t_vec2){
							cos_lut(ray_angle), sin_lut(ray_angle)}, 100), origin), (t_rgba)0xffff0000);
        i++;
    }
    return (0);
}

