/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:50:41 by dderny            #+#    #+#             */
/*   Updated: 2025/10/30 12:06:48 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

# include <ft_bool.h>
# include <math.h>

# define VEC3_ZERO (t_vec3){0, 0, 0}
# define VEC3_ONE (t_vec3){1, 1, 1}
# define VEC3_UP (t_vec3){0, 1, 0}
# define VEC3_DOWN (t_vec3){0, -1, 0}
# define VEC3_RIGHT (t_vec3){1, 0, 0}
# define VEC3_LEFT (t_vec3){-1, 0, 0}
# define VEC3_FORWARD (t_vec3){0, 0, 1}
# define VEC3_BACKWARD (t_vec3){0, 0, -1}
# define VEC3_INF (t_vec3){INFINITY, INFINITY, INFINITY}

typedef struct
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

/**
 * @brief Adds two vectors component-wise
 * @param a First vector
 * @param b Second vector
 * @return Result vector (a.x + b.x, a.y + b.y, a.z + b.z)
 */
t_vec3		vec3_add(t_vec3 a, t_vec3 b);

/**
 * @brief Subtracts two vectors component-wise
 * @param a First vector
 * @param b Second vector
 * @return Result vector (a.x - b.x, a.y - b.y, a.z - b.z)
 */
t_vec3		vec3_sub(t_vec3 a, t_vec3 b);

/**
 * @brief Multiplies two vectors component-wise
 * @param a First vector
 * @param b Second vector
 * @return Result vector (a.x * b.x, a.y * b.y, a.z * b.z)
 */
t_vec3		vec3_mul(t_vec3 a, t_vec3 b);

/**
 * @brief Divides two vectors component-wise
 * @param a First vector (numerator)
 * @param b Second vector (denominator)
 * @return Result vector (a.x / b.x, a.y / b.y, a.z / b.z)
 */
t_vec3		vec3_div(t_vec3 a, t_vec3 b);

/**
 * @brief Multiplies a vector by a scalar float
 * @param a Vector to multiply
 * @param b Scalar multiplier
 * @return Result vector (a.x * b, a.y * b, a.z * b)
 */
t_vec3		vec3_mulf(t_vec3 a, float b);

/**
 * @brief Divides a vector by a scalar float
 * @param a Vector to divide
 * @param b Scalar divisor
 * @return Result vector (a.x / b, a.y / b, a.z / b)
 */
t_vec3		vec3_divf(t_vec3 a, float b);

/**
 * @brief Multiplies a vector by a scalar integer
 * @param a Vector to multiply
 * @param b Scalar multiplier
 * @return Result vector (a.x * b, a.y * b, a.z * b)
 */
t_vec3		vec3_muli(t_vec3 a, int b);

/**
 * @brief Divides a vector by a scalar integer
 * @param a Vector to divide
 * @param b Scalar divisor
 * @return Result vector (a.x / b, a.y / b, a.z / b)
 */
t_vec3		vec3_divi(t_vec3 a, int b);

/**
 * @brief Adds a vector to another vector in-place
 * @param a Pointer to vector to modify (a += b)
 * @param b Vector to add
 * @return Modified vector a
 */
t_vec3		vec3_add_by(t_vec3 *a, t_vec3 b);

/**
 * @brief Subtracts a vector from another vector in-place
 * @param a Pointer to vector to modify (a -= b)
 * @param b Vector to subtract
 * @return Modified vector a
 */
t_vec3		vec3_sub_by(t_vec3 *a, t_vec3 b);

/**
 * @brief Multiplies a vector by another vector in-place
 * @param a Pointer to vector to modify (a *= b)
 * @param b Vector to multiply by
 * @return Modified vector a
 */
t_vec3		vec3_mul_by(t_vec3 *a, t_vec3 b);

/**
 * @brief Divides a vector by another vector in-place
 * @param a Pointer to vector to modify (a /= b)
 * @param b Vector to divide by
 * @return Modified vector a
 */
t_vec3		vec3_div_by(t_vec3 *a, t_vec3 b);

/**
 * @brief Multiplies a vector by a scalar float in-place
 * @param a Pointer to vector to modify (a *= b)
 * @param b Scalar multiplier
 * @return Modified vector a
 */
t_vec3		vec3_mulf_by(t_vec3 *a, float b);

/**
 * @brief Divides a vector by a scalar float in-place
 * @param a Pointer to vector to modify (a /= b)
 * @param b Scalar divisor
 * @return Modified vector a
 */
t_vec3		vec3_divf_by(t_vec3 *a, float b);

/**
 * @brief Multiplies a vector by a scalar integer in-place
 * @param a Pointer to vector to modify (a *= b)
 * @param b Scalar multiplier
 * @return Modified vector a
 */
t_vec3		vec3_muli_by(t_vec3 *a, int b);

/**
 * @brief Divides a vector by a scalar integer in-place
 * @param a Pointer to vector to modify (a /= b)
 * @param b Scalar divisor
 * @return Modified vector a
 */
t_vec3		vec3_divi_by(t_vec3 *a, int b);

/**
 * @brief Checks if two vectors are equal
 * @param a First vector
 * @param b Second vector
 * @return true if all components are equal, false otherwise
 */
t_bool		vec3_eq(t_vec3 a, t_vec3 b);

/**
 * @brief Checks if all components of a are less than b
 * @param a First vector
 * @param b Second vector
 * @return true if a.x < b.x && a.y < b.y && a.z < b.z
 */
t_bool		vec3_less(t_vec3 a, t_vec3 b);

/**
 * @brief Checks if all components of a are less than or equal to b
 * @param a First vector
 * @param b Second vector
 * @return true if a.x <= b.x && a.y <= b.y && a.z <= b.z
 */
t_bool		vec3_lesseq(t_vec3 a, t_vec3 b);

/**
 * @brief Checks if all components of a are greater than b
 * @param a First vector
 * @param b Second vector
 * @return true if a.x > b.x && a.y > b.y && a.z > b.z
 */
t_bool		vec3_great(t_vec3 a, t_vec3 b);

/**
 * @brief Checks if all components of a are greater than or equal to b
 * @param a First vector
 * @param b Second vector
 * @return true if a.x >= b.x && a.y >= b.y && a.z >= b.z
 */
t_bool		vec3_greateq(t_vec3 a, t_vec3 b);

/**
 * @brief Calculates the length (magnitude) of a vector
 * @param self Vector to measure
 * @return Length of the vector: sqrt(x² + y² + z²)
 */
float		vec3_len(t_vec3 self);

/**
 * @brief Calculates the squared length of a vector
 * @param self Vector to measure
 * @return Squared length: x² + y² + z² (faster than vec3_len, avoids sqrt)
 */
float		vec3_sqrlen(t_vec3 self);

/**
 * @brief Calculates the dot product of two vectors
 * @param a First vector
 * @param b Second vector
 * @return Dot product: a.x*b.x + a.y*b.y + a.z*b.z
 */
float		vec3_dot(t_vec3 a, t_vec3 b);

/**
 * @brief Calculates the Euclidean distance between two vectors
 * @param a First vector
 * @param b Second vector
 * @return Distance between vectors: sqrt((a.x-b.x)² + (a.y-b.y)² + (a.z-b.z)²)
 */
float		vec3_dist(t_vec3 a, t_vec3 b);

/**
 * @brief Calculates the squared distance between two vectors
 * @param a First vector
 * @param b Second vector
 * @return Squared distance (faster than vec3_dist, avoids sqrt)
 */
float		vec3_sqrdist(t_vec3 a, t_vec3 b);

/**
 * @brief Normalizes a vector in-place (makes its length 1)
 * @param self Pointer to vector to normalize
 * @note After normalization, the vector maintains its direction but has unit length
 */
void		vec3_norm(t_vec3 *self);

/**
 * @brief Returns a normalized copy of a vector
 * @param self Vector to normalize
 * @return New vector with same direction but unit length (length = 1)
 */
t_vec3		vec3_normed(t_vec3 self);

/**
 * @brief Clamps each component of a vector between min and max values
 * @param self Vector to clamp
 * @param min Minimum values for each component
 * @param max Maximum values for each component
 * @return Clamped vector
 */
void		vec3_clamp(t_vec3 *self, t_vec3 min, t_vec3 max);

/**
 * @brief Returns a clamped copy of a vector
 * @param self Vector to clamp
 * @param min Minimum values for each component
 * @param max Maximum values for each component
 * @return New vector with clamped components
 */
t_vec3		vec3_clamped(t_vec3 self, t_vec3 min, t_vec3 max);

/**
 * @brief Calculates the cross product of two vectors
 * @param a First vector
 * @param b Second vector
 * @return Vector perpendicular to both a and b (follows right-hand rule)
 */
t_vec3		vec3_cross(t_vec3 a, t_vec3 b);

/**
 * @brief Performs linear interpolation between two vectors
 * @param a Start vector (when t = 0)
 * @param b End vector (when t = 1)
 * @param t Interpolation parameter (typically between 0 and 1)
 * @return Interpolated vector: a + t * (b - a)
 */
t_vec3		vec3_lerp(t_vec3 a, t_vec3 b, float t);

/**
 * @brief Returns a vector with the minimum components from two vectors
 * @param a First vector
 * @param b Second vector
 * @return Vector (min(a.x, b.x), min(a.y, b.y), min(a.z, b.z))
 */
t_vec3		vec3_min(t_vec3 a, t_vec3 b);

/**
 * @brief Returns a vector with the maximum components from two vectors
 * @param a First vector
 * @param b Second vector
 * @return Vector (max(a.x, b.x), max(a.y, b.y), max(a.z, b.z))
 */
t_vec3		vec3_max(t_vec3 a, t_vec3 b);

/**
 * @brief Returns a vector with absolute values of all components
 * @param self Vector to process
 * @return Vector (|x|, |y|, |z|)
 */
t_vec3		vec3_abs(t_vec3 self);

#endif
