/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:13:57 by dderny            #+#    #+#             */
/*   Updated: 2025/04/25 19:38:03 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "texture.h"

t_frame	texture_get_frame(t_texture *self, char *slice)
{
	int		i;
	char	*name;

	i = 0;
	while (i < self->nb_slices)
	{
		name = self->slices[i].name;
		if (!ft_strncmp(name, slice, ft_strlen(name) + ft_strlen(slice)))
			return (self->frames[self->slices[i].from]);
		i++;
	}
	return ((t_frame){(t_vec2i){0, 0}, (t_vec2i){0, 0}});
}

t_frame	texture_get_cycle_frame(t_texture *self, char *slice, double cycle)
{
	int		i;
	int		frame;
	char	*name;

	i = 0;
	while (i < self->nb_slices)
	{
		name = self->slices[i].name;
		if (!name && ++i)
			continue ;
		if (!ft_strncmp(name, slice, ft_strlen(name) + ft_strlen(slice)))
		{
			frame = self->slices[i].from + (int)((double)
					(self->slices[i].to - self->slices[i].from + 1) * cycle);
			if (frame >= self->nb_frames)
				break ;
			if (frame < 0)
				frame = 0;
			return (self->frames[frame]);
		}
		i++;
	}
	return ((t_frame){(t_vec2i){0, 0}, (t_vec2i){0, 0}});
}
