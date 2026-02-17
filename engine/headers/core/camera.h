/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 03:48:43 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 03:48:43 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "types/vector3.h"

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	rot;
	int		fov;
}			t_camera;

#endif
