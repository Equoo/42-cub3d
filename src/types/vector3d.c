/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:00:00 by dderny            #+#    #+#             */
/*   Updated: 2025/04/18 16:33:23 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"
#include <libft.h>
#include <stdlib.h>

void	vec3_del(t_vec3 *vector)
{
	if (vector)
		free(vector);
}

/*
** Create a new vec3
** @param x: the x value
** @param y: the y value
** @return the vec3
*/
t_vec3	*vec3_new(float x, float y)
{
	t_vec3	*vector;

	vector = ft_calloc(1, sizeof(t_vec3));
	if (!vector)
		return (NULL);
	vector->x = x;
	vector->y = y;
	return (vector);
}

void	vec3i_del(t_vec3i *vector)
{
	if (vector)
		free(vector);
}

/*
** Create a new vec3i
** @param x: the x value
** @param y: the y value
** @return the vec3
*/
t_vec3i	*vec3i_new(int x, int y)
{
	t_vec3i	*vector;

	vector = ft_calloc(1, sizeof(t_vec3i));
	if (!vector)
		return (NULL);
	vector->x = x;
	vector->y = y;
	return (vector);
}
