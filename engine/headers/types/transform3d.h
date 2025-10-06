/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform3d.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:30:59 by dderny            #+#    #+#             */
/*   Updated: 2025/10/06 17:27:42 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM3D_H
# define TRANSFORM3D_H

#include "vector3.h"

typedef struct
{
	t_vec3		pos;
	t_vec3		scale;
	t_vec3		rot;
}				t_transform3d;

#endif