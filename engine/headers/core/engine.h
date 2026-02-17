/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:24:40 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 04:55:06 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# ifndef DEBUG
#  define DEBUG 0
# endif

# include "core/camera.h"
# include "core/window.h"
# include "core/world.h"
# include <libft.h>
# include <sys/types.h>

typedef struct s_engine	t_engine;
struct					s_engine
{
	int					max_fps;
	int					physics_ticks;

	double				start_time;
	double				last_frame;
	double				time;
	double				frametime;
	double				lastrealtime;

	uint				internal_keys[32];
	uint				internal_last_keys[32];
	uint				keys_states[32][2];

	t_map				*map;
	t_camera			camera;
	t_window			window;
	t__xgarbage			*garbage;
};

int						engine_initialize(t_engine *engine, int argc,
							char *argv[]);
int						engine_update(t_engine *engine);
int						engine_tick(t_engine *engine);
int						engine_close(t_engine *engine);

#endif
