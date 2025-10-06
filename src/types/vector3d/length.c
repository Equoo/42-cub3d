/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:43:36 by dderny            #+#    #+#             */
/*   Updated: 2025/04/18 16:33:23 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"
#include <math.h>

/*
** Length of a 2D float vector
** @param self: the vector
** @return the length
*/
float	vec3_length(t_vec3 self)
{
	return (sqrtf(self.x * self.x + self.y * self.y + self.z * self.z));
}

/*
** Length of a 2D int vector
** @param self: the vector
** @return the length
*/
int	vec3i_length(t_vec3i self)
{
	return (sqrtf(self.x * self.x + self.y * self.y + self.z * self.z));
}
