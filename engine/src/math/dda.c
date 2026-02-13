
#include "core/world.h"
#include "types/vector2.h"
#include <math.h>

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
	{
		res.dist = (pos.x - origin.x + (1 - data.step.x) / 2) / dir.x;
        res.dir = WEST;
		if (data.step.x > 0)
			res.dir = EAST;
	}
	else
	{
		res.dist = (pos.y - origin.y + (1 - data.step.y) / 2) / dir.y;
        res.dir = NORTH;
		if (data.step.y > 0)
			res.dir = SOUTH;
	}
    res.pos = vec2_add(origin, vec2_mulf(dir, res.dist));
	res.hit = get_cell(grid, (int)pos.x, (int)pos.y) == '1';
    return res;
}
