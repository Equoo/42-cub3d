/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 19:40:29 by dderny            #+#    #+#             */
/*   Updated: 2025/10/03 20:30:55 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "vector3d.h"

int sector_from_pos(t_world *world, t_vec3 pos)
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

static int	sector_trace_wall()
{

}

int  sector_trace_walls(t_sector **sectors, int sec_id, t_vec2 pos, float angle, t_hit *hit, int face_ignore)
{
    t_vec2  	dir = {cos(angle), sin(angle)};
    t_vec2  	hit_dir;
    int     	i;
	const t_sector	*sector = sectors[sec_id];

    i = 0;
    while (i < sector->n_points)
    {
        if (i != face_ignore && intersect_line_segment(pos, dir, (t_2vec2){sector->faces[i].pos, sector->faces[(i + 1) % sector->n_points].pos}, &hit->pos))
        {
            hit_dir = vec2_sub(hit->pos, pos);
            if (vec2_dot(&dir, &hit_dir) > 0)
			{
				if (sector->faces[i].portal != -1)
				{
					return (trace_wall(sectors, sector->faces[i].portal, pos, angle, hit, sector->faces[i].portal_face));
				}
				else {
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


