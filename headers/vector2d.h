/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:50:41 by dderny            #+#    #+#             */
/*   Updated: 2025/09/28 21:36:12 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2D_H
# define VECTOR2D_H

# define DIR_BOTTOM 3
# define DIR_LEFT 1
# define DIR_RIGHT 2
# define DIR_TOP 0
# define EPSILON 0.0001

typedef struct s_vec2
{
	float		x;
	float		y;
}				t_vec2;

typedef struct s_2vec2
{
	t_vec2	a;
	t_vec2	b;
}				t_2vec2;

typedef struct s_vec2i
{
	int			x;
	int			y;
}				t_vec2i;

typedef struct s_2vec2i
{
	t_vec2i		a;
	t_vec2i		b;
}				t_2vec2i;

typedef struct s_transform
{
	t_vec2i		pos;
	t_vec2i		scale;
	int			angle;
}				t_transform;

t_vec2		vec2_add(t_vec2 self, t_vec2 other);
t_vec2		vec2_sub(t_vec2 self, t_vec2 other);
t_vec2		vec2_multiply(t_vec2 self, t_vec2 other);
t_vec2		vec2_divide(t_vec2 self, t_vec2 other);
t_vec2		vec2_scale_dived(t_vec2 self, float factor);
t_vec2		vec2_scaled(t_vec2 self, float factor);
void			vec2_scale(t_vec2 *self, float factor);
float			vec2_dot(t_vec2 *self, t_vec2 *other);
float			vec2_cross(t_vec2 *self, t_vec2 *other);
t_vec2		vec2_normalize(t_vec2 self);
t_vec2		vec2_abs(t_vec2 self);
float			vec2_length(t_vec2 self);
t_vec2		vec2_lerp(t_vec2 a, t_vec2 b, float t);
float       vec2_dist(t_vec2 a, t_vec2 b);

void			vec2_del(t_vec2 *self);
t_vec2		*vec2_new(float x, float y);

t_vec2i			vec2i_add(t_vec2i self, t_vec2i other);
t_vec2i			vec2i_sub(t_vec2i self, t_vec2i other);
t_vec2i			vec2i_multiply(t_vec2i self, t_vec2i other);
t_vec2i			vec2i_divide(t_vec2i self, t_vec2i other);
t_vec2i			vec2i_scale_dived(t_vec2i self, int factor);
t_vec2i			vec2i_scaled(t_vec2i self, int factor);
void			vec2i_scale(t_vec2i *self, int factor);
int				vec2i_dot(t_vec2i *self, t_vec2i *other);
t_vec2i			vec2i_normalize(t_vec2i self);
t_vec2i			vec2i_abs(t_vec2i self);
int				vec2i_length(t_vec2i self);

void			vec2i_del(t_vec2i *self);
t_vec2i			*vec2i_new(int x, int y);

t_vec2i			to_vec2i(t_vec2 vec);
t_vec2		to_vec2(t_vec2i vec);

t_transform		t_from_pos(t_vec2i pos);

#endif
