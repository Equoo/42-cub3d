/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 06:15:54 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/23 23:55:16 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/camera.h"
#include "core/engine.h"
#include "core/world.h"

static int	is_wall(t_map *map, float x, float y)
{
	int	new_x;
	int	new_y;

	if (x < 0 || y < 0)
		return (1);
	new_x = (int)x;
	new_y = (int)y;
	if (new_x >= map->width || new_y >= map->height)
		return (1);
	if (BONUS)
		return (map->cells[new_y * map->width + new_x] == '1'
			|| map->cells[new_y * map->width + new_x] == 'D');
	return (map->cells[new_y * map->width + new_x] == '1');
}

static int	collides(t_map *map, float cx, float cy)
{
	if (is_wall(map, cx - CAMERA_RADIUS, cy - CAMERA_RADIUS))
		return (1);
	if (is_wall(map, cx + CAMERA_RADIUS, cy - CAMERA_RADIUS))
		return (1);
	if (is_wall(map, cx - CAMERA_RADIUS, cy + CAMERA_RADIUS))
		return (1);
	if (is_wall(map, cx + CAMERA_RADIUS, cy + CAMERA_RADIUS))
		return (1);
	return (0);
}

void	move_with_collision(t_engine *engine, float dx, float dy)
{
	t_camera	*cam;
	t_map		*map;
	float		nx;
	float		ny;

	cam = &engine->camera;
	map = engine->map;
	nx = cam->pos.x + dx;
	ny = cam->pos.y + dy;
	if (!collides(map, nx, ny))
	{
		cam->pos.x = nx;
		cam->pos.y = ny;
		return ;
	}
	if (!collides(map, nx, cam->pos.y))
	{
		cam->pos.x = nx;
		return ;
	}
	if (!collides(map, cam->pos.x, ny))
	{
		cam->pos.y = ny;
		return ;
	}
}
