/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terrain.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:56:50 by dderny            #+#    #+#             */
/*   Updated: 2025/04/27 00:47:10 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERRAIN_H
# define TERRAIN_H
# include "classes/element.h"
# include "ft_vector.h"
# include "vector2d.h"

# define MAP_CHARS "01CEP"
# define MAP_COIN 'C'
# define MAP_PLAYER 'P'
# define MAP_EXIT 'E'
# define MAP_WALL '1'
# define MAP_VOID '0'
# define MAP_MAXSIZE 16384

typedef struct s_terrain
{
	t_element	*base;
	char		*grid;
	int			w;
	int			h;
	int			spawn;
	int			exit;
	t_vec   	coins;
}				t_terrain;

typedef struct s_prob
{
	int			rate;
	t_2vec2i	size;
	char		slice[32];
}				t_prob;

typedef struct s_rule_data
{
	t_transform	*transform;
	int			*used;
}				t_rule_data;

char			getindir(t_terrain *self, t_vec2i pos, int dir);
int				get_facing(t_terrain *self, t_vec2i pos, int dirs[4]);
t_vec2i			getposindir(t_vec2i pos, int dir);

typedef t_bool	(*t_frule)(t_terrain *self, t_vec2i pos, char **slice,
		t_transform *transform);

typedef t_bool	(*t_srule)(t_terrain *self, t_vec2i *pos, char **slice,
		t_rule_data data);

int				get_random(t_prob *table, int size);
t_bool			check_space(t_terrain *self, t_vec2i pos, t_vec2i size,
					int *used);

t_bool			rs_other(t_terrain *self, t_vec2i *pos, char **slice,
					t_rule_data data);
t_bool			rs_corgrass(t_terrain *self, t_vec2i *pos, char **slice,
					t_rule_data data);

t_bool			rule_topgrass(t_terrain *self, t_vec2i pos, char **slice,
					t_transform *transform);
t_bool			rule_corgrass(t_terrain *self, t_vec2i pos, char **slice,
					t_transform *transform);
t_bool			rule_platform(t_terrain *self, t_vec2i pos, char **slice,
					__attribute__((unused)) t_transform *transform);

void			ground_surface(t_terrain *self, t_render *render,
					t_vec2i offset);

void			terrain_load(t_terrain *self, char *path);
int				terrain_findpath(t_terrain *self, int *checkedmap, t_vec2i pos,
					t_vec2i last);
void			terrain_draw(t_element *self, t_render *render);

t_terrain		*ft_terrain(t_scene *scene, char *mappath, char *texpath);

void			terrain_del(t_element **self);

#endif
