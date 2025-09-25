/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:44:26 by dderny            #+#    #+#             */
/*   Updated: 2025/04/26 01:52:36 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_h
# define CUB3D_h

# include "render.h"
# include <libft.h>

# ifndef TICK
#  define TICK 244
# endif

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_gameenv
{
	t_render	render;
	int			smooth_fps;
	double		start_time;
	double		time;
	double		frametime;
	double		last_frame;
	u_int		internal_keys[32];
	u_int		internal_last_keys[32];
	u_int		keys_states[32][2];

	void		*scene;
	t_list		*scenes_lst;
}				t_gameenv;

int				render_init(t_gameenv *env);
int				game_init(t_gameenv *env, char *mappath);
int				update(t_gameenv *env);
void			tick(t_gameenv *env);
void			tick_game(t_gameenv *env);
void			tick_render(t_gameenv *env, t_render *render);

int				process_close(t_gameenv *env);

#endif
