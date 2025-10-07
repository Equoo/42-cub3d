/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:50:41 by dderny            #+#    #+#             */
/*   Updated: 2025/04/26 03:35:21 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H
# include "render.h"
# include "vector2d.h"
# include <libft.h>
# include <mlx_int.h>

typedef struct s_2vec2i	t_frame;

typedef struct s_slice
{
	char				*name;
	int					from;
	int					to;
	int					framerate;
}						t_slice;

typedef struct s_texture
{
	char				*path;
	void				*mlx;
	t_img				*img;
	t_frame				*frames;
	t_slice				*slices;
	int					nb_frames;
	int					nb_slices;
	int					width;
	int					height;
}						t_texture;

typedef struct s_anim_sl
{
	char				*name;
	double				cycle;
}						t_anim_sl;

void					texture_draw_slice(t_texture *self, t_img *buffer,
							t_transform data, char *slice);
void					texture_draw_anim(t_texture *self, t_img *buffer,
							t_transform data, t_anim_sl anim_sl);
void					texture_blend_slice(t_texture *self, t_img *buffer,
							t_transform data, char *slice);
void					texture_blend_anim(t_texture *self, t_img *buffer,
							t_transform data, t_anim_sl anim_sl);
t_frame					texture_get_frame(t_texture *self, char *slice);
t_frame					texture_get_cycle_frame(t_texture *self, char *slice,
							double cycle);
int						read_texture_data(t_texture *texture, char *path,
							char *line);

double					texture_slice_time(t_texture *texture, char *slice);

void					texture_del(void *self);
t_texture				*ft_texture(t_render *render, char *path);

#endif
