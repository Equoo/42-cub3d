/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera3d.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:24:40 by dderny            #+#    #+#             */
/*   Updated: 2025/11/01 03:31:48 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA3D_H
# define CAMERA3D_H

# include "classes/core/node3d.h"
# include "types/vector2.h"

/** INHERIT node3d **/
typedef struct s_camera3d t_camera3d;
struct s_camera3d
{
	int		current;
	float	far;
	float	fov;
	float	near;
	
	t_vec3		(*project_position)(t_self *self, t_vec2 screenpos, float zdepth);
};

t_camera3d	*camera3d_new();
int			camera3d_construct(t_camera3d *self);
int			camera3d_destruct(t_camera3d *self);

#endif
