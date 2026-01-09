/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:50:41 by dderny            #+#    #+#             */
/*   Updated: 2025/10/30 12:06:45 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_H
# define VECTOR2_H

# include <ft_bool.h>
# include <math.h>

# define VEC2_ZERO (t_vec2){0, 0}
# define VEC2_ONE (t_vec2){1, 1}
# define VEC2_UP (t_vec2){0, 1}
# define VEC2_DOWN (t_vec2){0, -1}
# define VEC2_RIGHT (t_vec2){1, 0}
# define VEC2_LEFT (t_vec2){-1, 0}
# define VEC2_INF (t_vec2){INFINITY, INFINITY}

typedef struct
{
	float		x;
	float		y;
}				t_vec2;

/**
 * @brief Adds two vectors component-wise
 * @param a First vector
 * @param b Second vector
 * @return Result vector (a.x + b.x, a.y + b.y)
 */
t_vec2		vec2_add(t_vec2 a, t_vec2 b);

/**
 * @brief Subtracts two vectors component-wise
 * @param a First vector
 * @param b Second vector
 * @return Result vector (a.x - b.x, a.y - b.y)
 */
t_vec2		vec2_sub(t_vec2 a, t_vec2 b);

/**
 * @brief Multiplies two vectors component-wise
 * @param a First vector
 * @param b Second vector
 * @return Result vector (a.x * b.x, a.y * b.y)
 */
t_vec2		vec2_mul(t_vec2 a, t_vec2 b);

/**
 * @brief Divides two vectors component-wise
 * @param a First vector (numerator)
 * @param b Second vector (denominator)
 * @return Result vector (a.x / b.x, a.y / b.y)
 */
t_vec2		vec2_div(t_vec2 a, t_vec2 b);

/**
 * @brief Multiplies a vector by a scalar float
 * @param a Vector to multiply
 * @param b Scalar multiplier
 * @return Result vector (a.x * b, a.y * b)
 */
t_vec2		vec2_mulf(t_vec2 a, float b);

/**
 * @brief Divides a vector by a scalar float
 * @param a Vector to divide
 * @param b Scalar divisor
 * @return Result vector (a.x / b, a.y / b)
 */
t_vec2		vec2_divf(t_vec2 a, float b);

/**
 * @brief Multiplies a vector by a scalar integer
 * @param a Vector to multiply
 * @param b Scalar multiplier
 * @return Result vector (a.x * b, a.y * b)
 */
t_vec2		vec2_muli(t_vec2 a, int b);

/**
 * @brief Divides a vector by a scalar integer
 * @param a Vector to divide
 * @param b Scalar divisor
 * @return Result vector (a.x / b, a.y / b)
 */
t_vec2		vec2_divi(t_vec2 a, int b);

/**
 * @brief Adds a vector to another vector in-place
 * @param a Pointer to vector to modify (a += b)
 * @param b Vector to add
 * @return Modified vector a
 */
t_vec2		vec2_add_by(t_vec2 *a, t_vec2 b);

/**
 * @brief Subtracts a vector from another vector in-place
 * @param a Pointer to vector to modify (a -= b)
 * @param b Vector to subtract
 * @return Modified vector a
 */
t_vec2		vec2_sub_by(t_vec2 *a, t_vec2 b);

/**
 * @brief Multiplies a vector by another vector in-place
 * @param a Pointer to vector to modify (a *= b)
 * @param b Vector to multiply by
 * @return Modified vector a
 */
t_vec2		vec2_mul_by(t_vec2 *a, t_vec2 b);

/**
 * @brief Divides a vector by another vector in-place
 * @param a Pointer to vector to modify (a /= b)
 * @param b Vector to divide by
 * @return Modified vector a
 */
t_vec2		vec2_div_by(t_vec2 *a, t_vec2 b);

/**
 * @brief Multiplies a vector by a scalar float in-place
 * @param a Pointer to vector to modify (a *= b)
 * @param b Scalar multiplier
 * @return Modified vector a
 */
t_vec2		vec2_mulf_by(t_vec2 *a, float b);

/**
 * @brief Divides a vector by a scalar float in-place
 * @param a Pointer to vector to modify (a /= b)
 * @param b Scalar divisor
 * @return Modified vector a
 */
t_vec2		vec2_divf_by(t_vec2 *a, float b);

/**
 * @brief Multiplies a vector by a scalar integer in-place
 * @param a Pointer to vector to modify (a *= b)
 * @param b Scalar multiplier
 * @return Modified vector a
 */
t_vec2		vec2_muli_by(t_vec2 *a, int b);

/**
 * @brief Divides a vector by a scalar integer in-place
 * @param a Pointer to vector to modify (a /= b)
 * @param b Scalar divisor
 * @return Modified vector a
 */
t_vec2		vec2_divi_by(t_vec2 *a, int b);

/**
 * @brief Checks if two vectors are equal
 * @param a First vector
 * @param b Second vector
 * @return true if all components are equal, false otherwise
 */
t_bool		vec2_eq(t_vec2 a, t_vec2 b);

/**
 * @brief Checks if all components of a are less than b
 * @param a First vector
 * @param b Second vector
 * @return true if a.x < b.x && a.y < b.y
 */
t_bool		vec2_less(t_vec2 a, t_vec2 b);

/**
 * @brief Checks if all components of a are less than or equal to b
 * @param a First vector
 * @param b Second vector
 * @return true if a.x <= b.x && a.y <= b.y
 */
t_bool		vec2_lesseq(t_vec2 a, t_vec2 b);

/**
 * @brief Checks if all components of a are greater than b
 * @param a First vector
 * @param b Second vector
 * @return true if a.x > b.x && a.y > b.y
 */
t_bool		vec2_great(t_vec2 a, t_vec2 b);

/**
 * @brief Checks if all components of a are greater than or equal to b
 * @param a First vector
 * @param b Second vector
 * @return true if a.x >= b.x && a.y >= b.y
 */
t_bool		vec2_greateq(t_vec2 a, t_vec2 b);

/**
 * @brief Calculates the length (magnitude) of a vector
 * @param self Vector to measure
 * @return Length of the vector: sqrt(x² + y²)
 */
float		vec2_len(t_vec2 self);

/**
 * @brief Calculates the squared length of a vector
 * @param self Vector to measure
 * @return Squared length: x² + y² (faster than vec2_len, avoids sqrt)
 */
float		vec2_sqrlen(t_vec2 self);

/**
 * @brief Calculates the dot product of two vectors
 * @param a First vector
 * @param b Second vector
 * @return Dot product: a.x*b.x + a.y*b.y
 */
float		vec2_dot(t_vec2 a, t_vec2 b);

/**
 * @brief Calculates the Euclidean distance between two vectors
 * @param a First vector
 * @param b Second vector
 * @return Distance between vectors: sqrt((a.x-b.x)² + (a.y-b.y)²)
 */
float		vec2_dist(t_vec2 a, t_vec2 b);

/**
 * @brief Calculates the squared distance between two vectors
 * @param a First vector
 * @param b Second vector
 * @return Squared distance (faster than vec2_dist, avoids sqrt)
 */
float		vec2_sqrdist(t_vec2 a, t_vec2 b);

/**
 * @brief Normalizes a vector in-place (makes its length 1)
 * @param self Pointer to vector to normalize
 * @note After normalization, the vector maintains its direction but has unit length
 */
void		vec2_norm(t_vec2 *self);

/**
 * @brief Returns a normalized copy of a vector
 * @param self Vector to normalize
 * @return New vector with same direction but unit length (length = 1)
 */
t_vec2		vec2_normed(t_vec2 self);

/**
 * @brief Clamps each component of a vector between min and max values
 * @param self Pointer to vector to clamp in-place
 * @param min Minimum values for each component
 * @param max Maximum values for each component
 */
void		vec2_clamp(t_vec2 *self, t_vec2 min, t_vec2 max);

/**
 * @brief Returns a clamped copy of a vector
 * @param self Vector to clamp
 * @param min Minimum values for each component
 * @param max Maximum values for each component
 * @return New vector with clamped components
 */
t_vec2		vec2_clamped(t_vec2 self, t_vec2 min, t_vec2 max);

/**
 * @brief Calculates the 2D cross product (perpendicular dot product)
 * @param a First vector
 * @param b Second vector
 * @return Scalar value: a.x*b.y - a.y*b.x (z-component of 3D cross product)
 * @note Returns a scalar representing the signed area of the parallelogram
 */
t_vec2		vec2_cross(t_vec2 a, t_vec2 b);

/**
 * @brief Performs linear interpolation between two vectors
 * @param a Start vector (when t = 0)
 * @param b End vector (when t = 1)
 * @param t Interpolation parameter (typically between 0 and 1)
 * @return Interpolated vector: a + t * (b - a)
 */
t_vec2		vec2_lerp(t_vec2 a, t_vec2 b, float t);

/**
 * @brief Returns a vector with the minimum components from two vectors
 * @param a First vector
 * @param b Second vector
 * @return Vector (min(a.x, b.x), min(a.y, b.y))
 */
t_vec2		vec2_min(t_vec2 a, t_vec2 b);

/**
 * @brief Returns a vector with the maximum components from two vectors
 * @param a First vector
 * @param b Second vector
 * @return Vector (max(a.x, b.x), max(a.y, b.y))
 */
t_vec2		vec2_max(t_vec2 a, t_vec2 b);

/**
 * @brief Returns a vector with absolute values of all components
 * @param self Vector to process
 * @return Vector (|x|, |y|)
 */
t_vec2		vec2_abs(t_vec2 self);

/**
 * @brief Rotates a vector by a given angle in radians
 * @param v Vector to rotate
 * @param angle Rotation angle in radians (positive is counter-clockwise)
 * @return New rotated vector
 */
t_vec2		vec2_rot(t_vec2 v, float angle);

typedef struct s_intersect {
	t_vec2	line_pos;
	t_vec2	line_dir;
	t_vec2	sega;
	t_vec2	segb;
	t_vec2	*hit_pos;
}	t_intersect;

int			intersect_line_segment(t_intersect data);

#endif
