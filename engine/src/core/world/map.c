

#include "core/draw.h"
#include "core/world.h"
#include "core/camera.h"
#include "libft.h"
#include "math/extend.h"
#include "types/vector2.h"
#include <math.h>

typedef struct {
	t_vec2 sided;
	t_vec2 deltad;
	t_vec2 step;
}	t_dda;

static char get_cell(t_map grid, int x, int y)
{
    if (x < 0 || x >= grid.width || y < 0 || y >= grid.height)
        return '1';
    return grid.cells[y * grid.width + x];
}

int	dda_core(t_vec2 *origin, t_dda data, t_map grid)
{
	t_vec2	pos;
	int		max_steps;
	int		side;

	max_steps = grid.width + grid.height;
	pos = (t_vec2){(int)origin->x, (int)origin->y};
	side = 0;
    while (get_cell(grid, (int)pos.x, (int)pos.y) != '1' && max_steps-- > 0) {
        if (data.sided.x < data.sided.y) {
            data.sided.x += data.deltad.x;
            pos.x += data.step.x;
            side = 0;
        } else {
            data.sided.y += data.deltad.y;
            pos.y += data.step.y;
            side = 1;
        }
    }
	*origin = pos;
	return (side);
}

void	dda_init(t_vec2 posdir, float *delta, float *side, float *step)
{
	*delta = fabsf(1.0f / posdir.y);
	if (posdir.y == 0)
		*delta = 1e30f;
    if (posdir.y < 0) {
        *step = -1;
        *side = (posdir.x - (int)posdir.x) * *delta;
    } else {
        *step = 1;
        *side = ((int)posdir.x + 1.0f - posdir.x) * *delta;
    }
}

t_hit dda_trace(t_vec2 pos, t_vec2 dir, t_map grid)
{
    const t_vec2	origin = pos;
    t_dda			data;
	int				side;
    t_hit			res;

	dda_init((t_vec2){origin.x, dir.x}, &data.deltad.x, &data.sided.x, &data.step.x);
	dda_init((t_vec2){origin.y, dir.y}, &data.deltad.y, &data.sided.y, &data.step.y);
	side = dda_core(&pos, data, grid);
    if (side == 0)
        res.dist = (pos.x - origin.x + (1 - data.step.x) / 2) / dir.x;
    else
        res.dist = (pos.y - origin.y + (1 - data.step.y) / 2) / dir.y;
    res.pos = pos;
	res.hit = get_cell(grid, (int)pos.x, (int)pos.y) == '1';
    return res;
}

static int draw_wall(t_image *buffer, int x, float dist)
{
    int height = ft_clamp(1 / dist * 1200, 0, 1080);
    int i = 0;
	const float dark = 1 - 0.05 - (dist / 20);
	const t_rgba color = (t_rgba){.r=190*dark, .g=190*dark, .b=134*dark};
    while (i < height) {
        draw_pixel(buffer, 200 + x, 1080 / 2 - height / 2 + i++, color);
	}
    return (0);
}

int  draw_walls(t_image *buffer, t_map map, t_camera cam)
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
        ray_angle = cam.rot.z - (float)cam.fov / 2 + i * angle_steps;
        t_vec2 off = (t_vec2){100, 500};
        t_vec2 origin = vec2_add(vec2_mulf((t_vec2){cam.pos.x, cam.pos.y}, 10), off);
		t_vec2 dir = {cos_lut(ray_angle), sin_lut(ray_angle)};
		hit = dda_trace((t_vec2){cam.pos.x, cam.pos.y}, dir, map);

        if (hit.hit)
        {
			float correction = cos_lut(-(float)cam.fov / 2 + i * angle_steps);
			draw_wall(buffer, i, hit.dist * correction);
            draw_line(buffer, origin, vec2_add(vec2_mulf((t_vec2){
							cos_lut(ray_angle), sin_lut(ray_angle)}, 100), origin), (t_rgba)0xff00ff00);
			t_vec2 a = (t_vec2){100 + hit.pos.x * 10, 500 + hit.pos.y * 10};
			t_vec2 b = vec2_add(a, (t_vec2){10, 10});
            draw_square(buffer, a, b, (t_rgba)0xff0000ff);
        }
        else
            draw_line(buffer, origin, vec2_add(vec2_muli((t_vec2){
							cos_lut(ray_angle), sin_lut(ray_angle)}, 100), origin), (t_rgba)0xffff0000);
        i++;
    }
    return (0);
}

