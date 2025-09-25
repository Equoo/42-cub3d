/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:50:41 by dderny            #+#    #+#             */
/*   Updated: 2025/04/26 01:46:03 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3D_H
# define VECTOR3D_H

# define EPSILON 0.0001

typedef struct s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

typedef struct s_2vec3
{
	t_vec3	a;
	t_vec3	b;
}				t_2vec3;

typedef struct s_vec3i
{
	int			x;
	int			y;
	int			z;
}				t_vec3i;

typedef struct s_2vec3i
{
	t_vec3i		a;
	t_vec3i		b;
}				t_2vec3i;

typedef struct s_transform3
{
	t_vec3		pos;
	t_vec3		scale;
	t_vec3		rot;
}				t_transform3;

t_vec3		vec3_add(t_vec3 self, t_vec3 other);
t_vec3		vec3_sub(t_vec3 self, t_vec3 other);
t_vec3		vec3_multiply(t_vec3 self, t_vec3 other);
t_vec3		vec3_divide(t_vec3 self, t_vec3 other);
t_vec3		vec3_scale_dived(t_vec3 self, float factor);
t_vec3		vec3_scaled(t_vec3 self, float factor);
void			vec3_scale(t_vec3 *self, float factor);
float			vec3_dot(t_vec3 *self, t_vec3 *other);
t_vec3		vec3_normalize(t_vec3 self);
t_vec3		vec3_abs(t_vec3 self);
float			vec3_length(t_vec3 self);
t_vec3		vec3_lerp(t_vec3 a, t_vec3 b, float t);

void			vec3_del(t_vec3 *self);
t_vec3		*vec3_new(float x, float y);

t_vec3i			vec3i_add(t_vec3i self, t_vec3i other);
t_vec3i			vec3i_sub(t_vec3i self, t_vec3i other);
t_vec3i			vec3i_multiply(t_vec3i self, t_vec3i other);
t_vec3i			vec3i_divide(t_vec3i self, t_vec3i other);
t_vec3i			vec3i_scale_dived(t_vec3i self, int factor);
t_vec3i			vec3i_scaled(t_vec3i self, int factor);
void			vec3i_scale(t_vec3i *self, int factor);
int				vec3i_dot(t_vec3i *self, t_vec3i *other);
t_vec3i			vec3i_normalize(t_vec3i self);
t_vec3i			vec3i_abs(t_vec3i self);
int				vec3i_length(t_vec3i self);

void			vec3i_del(t_vec3i *self);
t_vec3i			*vec3i_new(int x, int y);

t_vec3i			to_vec3i(t_vec3 vec);
t_vec3		    to_vec3(t_vec3i vec);

t_transform3		t3_from_pos(t_vec3 pos);

#endif
