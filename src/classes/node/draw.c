/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:32:57 by dderny            #+#    #+#             */
/*   Updated: 2025/04/26 03:36:56 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/element.h"

void	element_draw(t_element *self, t_render *render)
{
	t_transform3	transform;

	transform = t3_from_pos(vec3_sub(vec3_add(self->pos,
						self->txt_off_pos), self->scene->cam_pos));
    (void)transform;
    (void)render;
    //if (self->anim)
	//	texture_blend_anim(self->texture, render->buffer, transform,
	//		(t_anim_sl){self->anim, self->cycle});
}
