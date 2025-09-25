/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_slice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:36:19 by dderny            #+#    #+#             */
/*   Updated: 2025/04/26 04:04:55 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "vector2d.h"
#include "render.h"

void	texture_draw_slice(t_texture *self, t_img *buffer,
					t_transform data, char *slice)
{
	t_frame		frame;
	t_imgflip	flip;

	if (!slice)
		return ;
	flip = 0;
	if (data.scale.x == -1)
		flip |= FLIP_HORIZ;
	if (data.scale.y == -1)
		flip |= FLIP_VERT;
	frame = texture_get_frame(self, slice);
	if (data.angle != 0 || flip)
		mylx_img_copy((t_copyimg){frame.a, frame.b,
			data.pos, self->img, buffer,
			flip, data.angle});
	else
		mylx_img_fast_copy((t_2vec2i){frame.a,
			(t_vec2i){frame.a.x + frame.b.x, frame.a.y + frame.b.y}},
			data.pos, buffer, self->img);
}

void	texture_draw_anim(t_texture *self, t_img *buffer,
					t_transform data, t_anim_sl anim_sl)
{
	t_frame		frame;
	t_imgflip	flip;

	if (!anim_sl.name)
		return ;
	flip = 0;
	if (data.scale.x == -1)
		flip |= FLIP_HORIZ;
	if (data.scale.y == -1)
		flip |= FLIP_VERT;
	frame = texture_get_cycle_frame(self, anim_sl.name, anim_sl.cycle);
	if (data.angle != 0 || flip)
		mylx_img_copy((t_copyimg){frame.a, frame.b,
			data.pos, self->img, buffer,
			flip, data.angle});
	else
		mylx_img_fast_copy((t_2vec2i){frame.a,
			(t_vec2i){frame.a.x + frame.b.x, frame.a.y + frame.b.y}},
			data.pos, buffer, self->img);
}

void	texture_blend_slice(t_texture *self, t_img *buffer,
					t_transform data, char *slice)
{
	t_frame		frame;
	t_imgflip	flip;

	if (!slice)
		return ;
	flip = 0;
	if (data.scale.x == -1)
		flip |= FLIP_HORIZ;
	if (data.scale.y == -1)
		flip |= FLIP_VERT;
	frame = texture_get_frame(self, slice);
	if (data.angle || flip)
		mylx_img_blend((t_copyimg){frame.a, frame.b,
			data.pos, self->img, buffer,
			flip, data.angle});
	else
		mylx_img_fast_blend((t_2vec2i){frame.a,
			(t_vec2i){frame.a.x + frame.b.x, frame.a.y + frame.b.y}},
			data.pos, buffer, self->img);
}

void	texture_blend_anim(t_texture *self, t_img *buffer,
					t_transform data, t_anim_sl anim_sl)
{
	t_frame		frame;
	t_imgflip	flip;

	if (!anim_sl.name)
		return ;
	flip = 0;
	if (data.scale.x == -1)
		flip |= FLIP_HORIZ;
	if (data.scale.y == -1)
		flip |= FLIP_VERT;
	frame = texture_get_cycle_frame(self, anim_sl.name, anim_sl.cycle);
	if (data.angle != 0 || flip)
		mylx_img_blend((t_copyimg){frame.a, frame.b,
			data.pos, self->img, buffer,
			flip, data.angle});
	else
		mylx_img_fast_blend((t_2vec2i){frame.a,
			(t_vec2i){frame.a.x + frame.b.x, frame.a.y + frame.b.y}},
			data.pos, buffer, self->img);
}
