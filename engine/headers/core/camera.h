/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 03:48:43 by dderny            #+#    #+#             */
/*   Updated: 2026/02/20 21:17:36 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "types/vector3.h"

# define CAMERA_RADIUS 0.2f
# define SPAWN_OFFSET 0.5f
# define ROT_SPEED_MIN 0.5f
# define ROT_SPEED_MAX 8.0f
# define ROT_SPEED_STEP 0.5f

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	rot;
	float	speed;
	float	rot_speed;
	int		fov;
}			t_camera;

#endif
