/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lerp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:01:07 by dderny            #+#    #+#             */
/*   Updated: 2025/04/21 15:01:35 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"
#include <libft.h>

t_vec3	vec3_lerp(t_vec3 a, t_vec3 b, float t)
{
	t_vec3	result;

	if (t < 0)
		t = 0;
	else if (t > 1)
		t = 1;
	result.x = ft_lerp(a.x, b.x, t);
	result.y = ft_lerp(a.y, b.y, t);
	result.z = ft_lerp(a.z, b.z, t);
	return (result);
}
