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

#include "vector2d.h"
#include <libft.h>
#include <stdlib.h>

void	vec2_del(t_vec2 *vector)
{
	if (vector)
		free(vector);
}

/*
** Create a new vec2
** @param x: the x value
** @param y: the y value
** @return the vec2
*/
t_vec2	*vec2_new(float x, float y)
{
	t_vec2	*vector;

	vector = ft_calloc(1, sizeof(t_vec2));
	if (!vector)
		return (NULL);
	vector->x = x;
	vector->y = y;
	return (vector);
}

void	vec2i_del(t_vec2i *vector)
{
	if (vector)
		free(vector);
}

/*
** Create a new vec2i
** @param x: the x value
** @param y: the y value
** @return the vec2
*/
t_vec2i	*vec2i_new(int x, int y)
{
	t_vec2i	*vector;

	vector = ft_calloc(1, sizeof(t_vec2i));
	if (!vector)
		return (NULL);
	vector->x = x;
	vector->y = y;
	return (vector);
}
