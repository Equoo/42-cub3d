/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_sweep_aabb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:25:58 by dderny            #+#    #+#             */
/*   Updated: 2025/04/25 19:11:31 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/element.h"
#include "classes/entity.h"
#include "classes/terrain.h"
#include "collisions.h"
#include "libft.h"
#include "scene.h"
#include "vector3d.h"
#include <math.h>
#include <stdint.h>

static t_sweep	sweep_entities(t_entity *entity, t_trace *trace)
{
	t_aabb	hulla;
	t_aabb	hullb;

	if (!entity || entity->nocollision)
		return ((t_sweep){{0}, {0}, 1});
	hulla = trace->hull;
	hulla.min = vec3_add(hulla.min, trace->from);
	hulla.max = vec3_add(hulla.max, trace->from);
	hulla = aabb_from_mm(hulla.min, hulla.max);
	hullb = entity->hull;
	hullb.min = vec3_add(hullb.min, entity->base->pos);
	hullb.max = vec3_add(hullb.max, entity->base->pos);
	hullb = aabb_from_mm(hullb.min, hullb.max);
	return (sweep_aabb(hulla, hullb, vec3_sub(trace->to, trace->from)));
}

static t_sweep	sweep_terrain_voxel(t_terrain *terrain, t_trace *trace, uint i)
{
	uint	voxels_w;
	uint	gridindex;
	t_aabb	hulla;
	t_aabb	hullb;

	hulla = trace->hull;
	hulla.min = vec3_add(hulla.min, trace->from);
	hulla.max = vec3_add(hulla.max, trace->from);
	hulla = aabb_from_mm(hulla.min, hulla.max);
	voxels_w = ceil(round(aabb_w(hulla)) / TR_GRID_SIZE) * 4;
	gridindex = (int)floor(hulla.min.x / TR_GRID_SIZE) + i % voxels_w - 1
		+ ((int)floor(hulla.min.y / TR_GRID_SIZE) + i / voxels_w - 1)
		* terrain->w;
	if (gridindex < 0 || gridindex >= (uint)terrain->w * (uint)terrain->h)
		return ((t_sweep){.time = 1});
	if (terrain->grid[gridindex] != MAP_WALL)
		return ((t_sweep){.time = 1});
	hullb = (t_aabb){{(gridindex % terrain->w) * TR_GRID_SIZE, gridindex
		/ terrain->w * TR_GRID_SIZE, 0}, {TR_GRID_SIZE, TR_GRID_SIZE, 0}, {0}, {0}};
	hullb.max = vec3_add(hullb.min, hullb.max);
	hullb = aabb_from_mm(hullb.min, hullb.max);
	return (sweep_aabb(hulla, hullb, vec3_sub(trace->to, trace->from)));
}

static t_sweep	sweep_terrain(t_terrain *terrain, t_trace *trace)
{
	t_sweep	sweep;
	t_sweep	nearest;
	uint	i;
	uint	voxels;

	nearest = (t_sweep){{0}, {0}, 1};
	voxels = ceil(round(aabb_w(trace->hull)) * round(aabb_h(trace->hull))
			/ (TR_GRID_SIZE * TR_GRID_SIZE)) * 16;
	i = -1;
	while (++i < voxels)
	{
		sweep = sweep_terrain_voxel(terrain, trace, i);
		if (sweep.time < nearest.time)
			nearest = sweep;
	}
	return (nearest);
}

t_sweep	world_sweep_aabb(t_scene *scene, t_trace trace)
{
	t_list		*current;
	t_element	*element;
	t_sweep		sweep;
	t_sweep		act;

	sweep = (t_sweep){0};
	sweep.time = 1;
	current = scene->elements;
	while (current)
	{
		element = current->content;
		if (element->class & trace.mask && trace.ignore != element->id)
		{
			act = (t_sweep){{0}, {0}, 1};
			if (element->class == CLASS_TERRAIN)
				act = sweep_terrain((t_terrain *)element->parent, &trace);
			else if (element->class & CGROUP_ENTITY)
				act = sweep_entities(cast_entity(element->parent), &trace);
			act.hit.element = element;
			if (act.time < sweep.time)
				sweep = act;
		}
		current = current->next;
	}
	return (sweep);
}
