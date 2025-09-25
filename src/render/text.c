/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:36:52 by dderny            #+#    #+#             */
/*   Updated: 2025/04/25 23:15:11 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "texture.h"
#include "vector2d.h"
#include "libft.h"
#include "render.h"
#include <errno.h>
#include <stddef.h>

int	draw_text(t_render *render, char *text, t_vec2 pos, int font_size)
{
	t_rtext		data;

	if (errno)
		return (1);
	data = (t_rtext){0};
	data.text = ft_strdup(text);
	if (!data.text)
		return (1);
	data.pos = to_vec2i(pos);
	data.font_size = font_size;
	if (vec_append(&render->texts, &data))
	{
		free(data.text);
		return (1);
	}
	return (0);
}

void	render_one_text(t_render *render, t_img *buffer, t_rtext *data)
{
	size_t		len;
	char		slice_char[16];
	t_transform	transfo;
	size_t		i;

	if (!data || !data->font_size)
		return ;
	len = ft_itoato(data->font_size, slice_char);
	slice_char[len] = '_';
	i = 0;
	transfo = t_from_pos(data->pos);
	while (data->text[i])
	{
		ft_memcpy(slice_char + len + 1, data->text + i, 1);
		slice_char[len + 2] = 0;
		transfo.pos.x += data->font_size / 2;
		texture_blend_slice(render->font, buffer, transfo, slice_char);
		i++;
	}
}

void	render_texts(t_render *render, t_img *buffer)
{
	t_rtext	*data;
	size_t	i;

	data = (t_rtext *)render->texts;
	i = 0;
	while (i < vec_size(render->texts))
	{
		render_one_text(render, buffer, data + i);
		free(data[i].text);
		i++;
	}
	vec_clear(render->texts);
}

