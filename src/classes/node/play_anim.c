/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:46:21 by dderny            #+#    #+#             */
/*   Updated: 2025/04/25 20:02:58 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/element.h"
#include "texture.h"

void	element_play_anim(t_element *self, char *anim_name)
{
	double	time;

	time = texture_slice_time(self->texture, anim_name);
	self->anim = anim_name;
	self->force_anim_time = self->scene->env->time + time;
	self->last_anim_time = self->scene->env->time;
	self->cycle = 0;
}
