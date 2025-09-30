/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 02:04:17 by dderny            #+#    #+#             */
/*   Updated: 2025/05/24 06:34:14 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTATION_H
# define ROTATION_H
# include "vector3d.h"

typedef t_vec3 t_rot;

t_rot	rotation_create(double x, double y, double z);
t_rot	rotation_add(t_rot a, t_rot b);
t_rot	rotation_sub(t_rot a, t_rot b);
t_rot	rotation_mult(t_rot a, t_rot b);
t_rot	rotation_div(t_rot a, t_rot b);
t_rot	rotation_scale(t_rot a, double b);
t_vec3	rot_up(t_rot r);
t_vec3	rot_right(t_rot r);
t_vec3	rot_forward(t_rot r);

#endif
