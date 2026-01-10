/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:24:40 by dderny            #+#    #+#             */
/*   Updated: 2025/12/01 23:32:21 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <libft.h>
# include <sys/types.h>
# include <time.h>
# include "core/window.h"

typedef struct s_engine t_engine;
struct s_engine
{
	int			max_fps;
	int			physics_ticks;
	time_t		time;
	time_t		deltatime;
	t_window	window;
	t__xgarbage *garbage;
};

int			engine_initialize(t_engine *engine,
						int argc, char *argv[]);
int			engine_update(t_engine *engine);
int			engine_tick(t_engine *engine, time_t frametime);
int			engine_close(t_engine *engine);

#endif
