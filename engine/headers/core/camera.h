/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 03:48:43 by dderny            #+#    #+#             */
/*   Updated: 2026/02/20 07:44:22 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "types/vector3.h"

#define CAMERA_RADIUS 0.2f
#define SPAWN_OFFSET 0.5f

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	rot;
	int		fov;
}			t_camera;

#endif
