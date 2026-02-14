/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:32:44 by dderny            #+#    #+#             */
/*   Updated: 2026/02/14 16:56:04 by dderny                  ###   ########   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AABB_H
# define AABB_H

# include "vector3.h"
# include <ft_bool.h>

/**
 * @brief Axis-Aligned Bounding Box (AABB) structure
 * @details Represents a 3D box aligned with the coordinate axes, defined by
 *          two opposite corners (position and end point) and its size
 */
typedef struct s_aabb
{
	t_vec3	pos;
	t_vec3	end;
	t_vec3	size;
}			t_aabb;

/**
 * @brief Creates an AABB from two corner points
 * @param start Minimum corner of the bounding box
 * @param end Maximum corner of the bounding box
 * @return New AABB with calculated size
 */
t_aabb		aabb(t_vec3 start, t_vec3 end);

/**
 * @brief Creates an AABB from center point and size
 * @param center Center position of the bounding box
 * @param size Dimensions of the box (width, height, depth)
 * @return New AABB with calculated position and end points
 */
t_aabb		aabb_from_size(t_vec3 center, t_vec3 size);

/**
 * @brief Creates an AABB that encompasses two AABBs
 * @param a First AABB
 * @param b Second AABB
 * @return New AABB that contains both input AABBs
 */
t_aabb		aabb_union(t_aabb a, t_aabb b);

/**
 * @brief Checks if two AABBs are equal
 * @param a First AABB
 * @param b Second AABB
 * @return true if position, end, and size are equal, false otherwise
 */
t_bool		aabb_eq(t_aabb a, t_aabb b);

/**
 * @brief Calculates the center point of an AABB
 * @param aabb AABB to measure
 * @return Center position: (pos + end) / 2
 */
t_vec3		aabb_center(t_aabb aabb);

/**
 * @brief Returns the end point (maximum corner) of an AABB
 * @param aabb AABB to query
 * @return Maximum corner position
 */
t_vec3		aabb_end(t_aabb aabb);

/**
 * @brief Calculates the volume of an AABB
 * @param aabb AABB to measure
 * @return Volume: size.x * size.y * size.z
 */
float		aabb_volume(t_aabb aabb);

/**
 * @brief Returns the support point of an AABB
 * @param aabb AABB to query
 * @return Support point (typically the farthest point in a given direction)
 * @note Used in collision detection algorithms like GJK
 */
t_vec3		aabb_support(t_aabb aabb);

/**
 * @brief Checks if a point is inside an AABB
 * @param aabb AABB to test against
 * @param point Point to check
 * @return true if point is within the bounds, false otherwise
 */
t_bool		aabb_has_point(t_aabb aabb, t_vec3 point);

/**
 * @brief Calculates the intersection of two AABBs
 * @param a First AABB
 * @param b Second AABB
 * @return New AABB representing the overlapping region,
	or empty if no intersection
 */
t_aabb		aabb_intersection(t_aabb a, t_aabb b);

/**
 * @brief Checks if two AABBs intersect
 * @param a First AABB
 * @param b Second AABB
 * @return true if the AABBs overlap, false otherwise
 */
t_bool		aabb_intersects(t_aabb a, t_aabb b);

/**
 * @brief Tests if a ray intersects with an AABB
 * @param a AABB to test against
 * @param ray_origin Starting point of the ray
 * @param ray_dir Direction vector of the ray (should be normalized)
 * @param hit_point Output parameter for the intersection point (can be NULL)
 * @return true if ray intersects the AABB, false otherwise
 */
t_bool		aabb_intersects_ray(t_aabb a, t_vec3 ray_origin, t_vec3 ray_dir,
				t_vec3 *hit_point);

/**
 * @brief Tests if a line segment intersects with an AABB
 * @param a AABB to test against
 * @param ray_from Start point of the line segment
 * @param ray_to End point of the line segment
 * @param hit_point Output parameter for the intersection point (can be NULL)
 * @return true if segment intersects the AABB, false otherwise
 */
t_bool		aabb_intersects_segment(t_aabb a, t_vec3 ray_from, t_vec3 ray_to,
				t_vec3 *hit_point);

/**
 * @brief Tests if an AABB intersects with a plane
 * @param a AABB to test against
 * @param b Plane to test intersection with
 * @return true if AABB intersects or touches the plane, false otherwise
 */
t_bool		aabb_intersects_plane(t_aabb a, t_plane b);

#endif
