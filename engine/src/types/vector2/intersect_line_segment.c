/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_line_segment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:14:09 by dderny            #+#    #+#             */
/*   Updated: 2025/10/06 12:14:11 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "types/vector2.h"

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

int intersect_line_segment(const t_intersect data)
{
	const t_vec2	seg_dir = {data.segb.x - data.sega.x, data.segb.y - data.sega.y};
	const t_vec2	diff = {data.sega.x - data.line_pos.x, data.sega.y - data.line_pos.y};
	const float		cross_dirs = vec2_cross(data.line_dir, seg_dir).x;
	float			u;
	float			t;

	if (fabsf(cross_dirs) < 1e-6f)
		return (0);
	u = vec2_cross(&data.diff, &data.line_dir) / cross_dirs;
	if (u < 0.0f || u > 1.0f)
		return (0);
	t = vec2_cross(&data.diff, &seg_dir) / cross_dirs;
	data->hit_pos->x = data.line_pos.x + data.line_dir.x * t;
	data->hit_pos->y = data.line_pos.y + data.line_dir.y * t;
	return (1);
}

