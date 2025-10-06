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
#include "types/vector2d.h"

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

int intersect_line_segment(const t_vec2 line_pos,
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

