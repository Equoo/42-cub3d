/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform2d.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:30:59 by dderny            #+#    #+#             */
/*   Updated: 2025/10/06 17:41:43 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM2D_H
# define TRANSFORM2D_H

#include <ft_bool.h>
#include "vector2.h"

/* 
The Matrix2D type is a 2×3 matrix representing a transformation in 2D space.
It contains three Vector2 values: x, y, and origin.
Together, they can represent translation, rotation, scale, and skew.

The x and y axes form a 2×2 matrix, known as the transform's basis.
The length of each axis (Vector2.length()) influences the transform's scale,
while the direction of all axes influence the rotation. Usually, both axes
are perpendicular to one another. However, when you rotate one axis
individually, the transform becomes skewed. Applying a skewed transform to a
2D sprite will make the sprite appear distorted.
*/
typedef struct
{
	t_vec2		origin;
	t_vec2		x;
	t_vec2		y;
}				t_mat2;

t_mat2		mat2d_from_rp(float rot, t_vec2 pos);
t_mat2		mat2d_from_rssp(float rot, t_vec2 scale, t_vec2 skew, t_vec2 pos);

t_vec2		mat2d_origin();
float		mat2d_rotation();
t_vec2		mat2d_scale();
float		mat2d_skew();

t_bool		mat2d_eq(t_mat2 a, t_mat2 b);

t_mat2		mat2d_mul_by(t_mat2 *a, t_mat2 b);
t_mat2		mat2d_mulv_by(t_mat2 *a, t_vec2 b);
t_mat2		mat2d_mulf_by(t_mat2 *a, float b);
t_mat2		mat2d_muli_by(t_mat2 *a, int b);

t_mat2		mat2d_mul(t_mat2 a, t_mat2 b);
t_mat2		mat2d_mulv(t_mat2 a, t_vec2 b);
t_mat2		mat2d_mulf(t_mat2 a, float b);
t_mat2		mat2d_muli(t_mat2 a, int b);



#endif