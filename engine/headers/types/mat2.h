/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:30:59 by dderny            #+#    #+#             */
/*   Updated: 2025/10/07 16:38:47 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM2D_H
# define TRANSFORM2D_H

# include <ft_bool.h>
#include <math.h>
# include "rect2.h"
# include "vector2.h"

/**
 * @brief Identity matrix (no transformation)
 * @details x = (1, 0), y = (0, 1), origin = (0, 0)
 *	Equivalent to no transformation.
 */
# define MAT2_IDENTITY (t_mat2){.col =				\
	{(t_vec2){1, 0}, (t_vec2){0, 1}, (t_vec2){0, 0}}	\
}

/**
 * @brief Horizontal flip matrix
 * @details x = (-1, 0), y = (0, 1), origin = (0, 0)
 *	When any transform is multiplied by FLIP_X, it negates all components
 *	of the x axis (the X column).
 *	When FLIP_X is multiplied by any transform, it negates the Vector2.x
 * 	component of all axes (the X row).
 */
# define MAT2_FLIP_X (t_mat2){.col =				\
	{(t_vec2){-1, 0}, (t_vec2){0, 1}, (t_vec2){0, 0}}	\
}

/**
 * @brief Vertical flip matrix
 * @details x = (1, 0), y = (0, -1), origin = (0, 0)
*	When any transform is multiplied by FLIP_Y, it negates all components
 *	of the y axis (the Y column).
 *	When FLIP_Y is multiplied by any transform, it negates the Vector2.y
 * 	component of all axes (the Y row).
 */
# define MAT2_FLIP_Y (t_mat2){.col = 				\
	{(t_vec2){1, 0}, (t_vec2){0, -1}, (t_vec2){0, 0}}	\
}

/**
 * @brief 2D transformation matrix (2×3 matrix)
 * @details Represents affine transformations in 2D space including:
 *          translation, rotation, scale, and skew.
 * 
 * The x and y axes form a 2×2 basis matrix that defines rotation, scale,
 * and skew. The origin vector provides translation.
 * 
 * - Length of x and y axes controls scale
 * - Direction of axes controls rotation
 * - Non-perpendicular axes create skew (distortion)
 */
typedef struct
{
	union {
		struct
		{
			t_vec2	x;
			t_vec2	y;
			t_vec2	origin;
		};
		t_vec2	col[3];
	};
}				t_mat2;

/**
 * @brief Creates a 2D transformation matrix from basis vectors
 * @param x X axis (right direction)
 * @param y Y axis (up direction)
 * @param origin Translation vector (position)
 * @return New transformation matrix
 */
t_mat2		mat2(t_vec2 x, t_vec2 y, t_vec2 origin);

/**
 * @brief Creates a 2D transformation matrix from rotation and position
 * @param rot Rotation angle in radians
 * @param pos Position (translation)
 * @return New transformation matrix with rotation and translation
 */
t_mat2		mat2_from_rp(float rot, t_vec2 pos);

/**
 * @brief Creates a 2D transformation matrix from rotation, scale,
 * 	skew, and position
 * @param rot Rotation angle in radians
 * @param scale Scale factors (x, y)
 * @param skew Skew factors (x, y)
 * @param pos Position (translation)
 * @return New transformation matrix with all transformations applied
 */
t_mat2		mat2_from_rssp(float rot, t_vec2 scale, t_vec2 skew, t_vec2 pos);

/**
 * @brief Inverts a 2D transformation matrix
 * @param m Matrix to invert
 * @return New matrix that is the inverse of m
 */
void		mat2_invert(t_mat2 *m);

/**
 * @brief Inverts a 2D transformation matrix
 * @param m Matrix to invert
 * @return New matrix that is the inverse of m
 */
t_mat2		mat2_inverted(t_mat2 m);

/**
 * @brief Calculates the determinant of a 2D transformation matrix
 * @param m Matrix to calculate determinant for
 * @return Determinant value (float)
 */
float		mat2_determinant(t_mat2 m);

/**
 * @brief Extracts the origin (translation) from a matrix
 * @return Origin vector of the transformation
 */
t_vec2		mat2_origin(t_mat2 m);

/**
 * @brief Extracts the rotation angle from a matrix
 * @return Rotation angle in radians
 */
float		mat2_rotation(t_mat2 m);

/**
 * @brief Extracts the scale factors from a matrix
 * @return Scale vector (x, y)
 */
t_vec2		mat2_gscale(t_mat2 m);

/**
 * @brief Extracts the skew angle from a matrix
 * @return Skew angle in radians
 */
float		mat2_skew(t_mat2 m);

/**
 * @brief Checks if two matrices are equal
 * @param a First matrix
 * @param b Second matrix
 * @return true if all components are equal, false otherwise
 */
t_bool		mat2_eq(t_mat2 a, t_mat2 b);

/**
 * @brief Multiplies a matrix by another matrix in-place
 * @param a Pointer to matrix to modify (a *= b)
 * @param b Matrix to multiply by
 * @return Modified matrix a
 */
t_mat2		mat2_mul_by(t_mat2 *a, t_mat2 b);

/**
 * @brief Multiplies a matrix by a vector in-place
 * @param a Pointer to matrix to modify
 * @param b Vector to multiply by (applied to all columns)
 * @return Modified matrix a
 */
t_mat2		mat2_mulv_by(t_mat2 *a, t_vec2 b);

/**
 * @brief Multiplies a matrix by a scalar float in-place
 * @param a Pointer to matrix to modify (a *= b)
 * @param b Scalar multiplier
 * @return Modified matrix a
 */
t_mat2		mat2_mulf_by(t_mat2 *a, float b);

/**
 * @brief Multiplies a matrix by a scalar integer in-place
 * @param a Pointer to matrix to modify (a *= b)
 * @param b Scalar multiplier
 * @return Modified matrix a
 */
t_mat2		mat2_muli_by(t_mat2 *a, int b);

/**
 * @brief Multiplies two matrices
 * @param a First matrix
 * @param b Second matrix
 * @return Result of matrix multiplication a * b
 */
t_mat2		mat2_mul(t_mat2 a, t_mat2 b);

/**
 * @brief Multiplies a matrix by a vector
 * @param a Matrix
 * @param b Vector to multiply by
 * @return New matrix with vector applied to all columns
 */
t_mat2		mat2_mulv(t_mat2 a, t_vec2 b);

/**
 * @brief Multiplies a matrix by a scalar float
 * @param a Matrix to multiply
 * @param b Scalar multiplier
 * @return New matrix with all components multiplied by b
 */
t_mat2		mat2_mulf(t_mat2 a, float b);

/**
 * @brief Multiplies a matrix by a scalar integer
 * @param a Matrix to multiply
 * @param b Scalar multiplier
 * @return New matrix with all components multiplied by b
 */
t_mat2		mat2_muli(t_mat2 a, int b);

/**
 * @brief Translate a matrix in global space
 * @param m Matrix to translate
 * @param v Translation vector
 */
void		mat2_translate(t_mat2 *m, t_vec2 v);

/**
 * @brief Translates a matrix in global space
 * @param m Matrix to translate
 * @param v Translation vector
 * @return New matrix with translation applied in world coordinates
 */
t_mat2		mat2_translated(t_mat2 m, t_vec2 v);

/**
 * @brief Translates a matrix in local space
 * @param m Matrix to translate
 * @param v Translation vector in local coordinates
 * @return New matrix with translation applied in local space
 */
t_mat2		mat2_translated_local(t_mat2 m, t_vec2 v);

/**
 * @brief Rotates a matrix in global space
 * @param m Matrix to rotate
 * @param angle Rotation angle in radians
 * @return New matrix with rotation applied in world coordinates
 */
void		mat2_rotate(t_mat2 *m, float angle);

/**
 * @brief Rotates a matrix in global space
 * @param m Matrix to rotate
 * @param angle Rotation angle in radians
 * @return New matrix with rotation applied in world coordinates
 */
t_mat2		mat2_rotated(t_mat2 m, float angle);

/**
 * @brief Rotates a matrix in local space
 * @param m Matrix to rotate
 * @param angle Rotation angle in radians
 * @return New matrix with rotation applied around local origin
 */
t_mat2		mat2_rotated_local(t_mat2 m, float angle);

/**
 * @brief Scale a matrix in global space
 * @param m Matrix to scale
 * @param s Scale factors (x, y)
 */
void		mat2_scale(t_mat2 *m, t_vec2 s);

/**
 * @brief Scale a matrix basis in global space
 * @param m Matrix to scale
 * @param s Scale factors (x, y)
 */
void		mat2_scale_basis(t_mat2 *m, t_vec2 s);

/**
 * @brief Scales a matrix in global space
 * @param m Matrix to scale
 * @param s Scale factors (x, y)
 * @return New matrix with scale applied in world coordinates
 */
t_mat2		mat2_scaled(t_mat2 m, t_vec2 s);

/**
 * @brief Scales a matrix in local space
 * @param m Matrix to scale
 * @param s Scale factors (x, y)
 * @return New matrix with scale applied in local space
 */
t_mat2		mat2_scaled_local(t_mat2 m, t_vec2 s);

/**
 * @brief Computes the dot product of the matrix's X axis with a vector
 * @param m Matrix
 * @param v Vector
 * @return Dot product (float)
*/
float		mat2_tdotx(t_mat2 m, t_vec2 v);

/**
 * @brief Computes the dot product of the matrix's Y axis with a vector
 * @param m Matrix
 * @param v Vector
 * @return Dot product (float)
*/
float		mat2_tdoty(t_mat2 m, t_vec2 v);

/**
 * @brief Applies the transformation of a matrix to a vector
 * @param m Matrix
 * @param v Vector to transform
 * @return New vector transformed by the inverse of matrix m
*/
t_vec2		mat2_xform(t_mat2 m, t_vec2 v);

/**
 * @brief Applies the inverse transformation of a matrix to a vector
 * @param m Matrix
 * @param v Vector to transform
 * @return New vector transformed by the inverse of matrix m
*/
t_vec2		mat2_xform_inv(t_mat2 m, t_vec2 v);

/**
 * @brief Applies the basic transformation (ignoring translation) of
 * 	a matrix to a vector
 * @param m Matrix
 * @param v Vector to transform
 * @return New vector transformed by the linear part of matrix m
*/
t_vec2		mat2_basis_xform(t_mat2 m, t_vec2 v);

/**
 * @brief Applies the inverse of the basic transformation (ignoring translation)
 * 	of a matrix to a vector
 * @param m Matrix
 * @param v Vector to transform
 * @return New vector transformed by the inverse linear part of matrix m
*/
t_vec2		mat2_basis_xform_inv(t_mat2 m, t_vec2 v);

/**
 * @brief Interpolates between two matrices
 * @param a First matrix
 * @param b Second matrix
 * @param t Interpolation factor (0.0 to 1.0)
 * @return New matrix that is the interpolation between a and b
*/
t_mat2		mat2_lerp(t_mat2 a, t_mat2 b, float t);

#endif