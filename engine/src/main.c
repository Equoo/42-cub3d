/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:33:22 by dderny            #+#    #+#             */
/*   Updated: 2025/11/18 02:20:46 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/core/engine.h"
#include "classes/core/window.h"
#include "libft.h"
#include "ft_printf.h"
#include <math.h>
#include <bench.h>
#include <math_extend.h>

int	engine_initialization(t__xgarbage *garbage, int argc, char *argv[])
{
	t_engine	*engine;
	t_window	*window;
	
	engine = engine_new(garbage);
	if (!engine)
		return (1);
	window = window_new(engine);
	if (!window)
		return (1);

	ft_printf("Main object: %!s\n", engine->_to_string(engine));
	(void)argc;
    (void)argv;

	// mlx_hook(env.render.win, ON_KEYDOWN, KeyPressMask, &down_key, &env);
	// mlx_hook(env.render.win, ON_KEYUP, KeyReleaseMask, &up_key, &env);
	// display_trigo_benchmark();
	// display_dist_benchmark();
	// display_sqrtf_benchmark();

	if (window)
		window->free(window);
	if (engine)
		engine->free(engine);
	return (0);
}

int main(int argc, char *argv[])
{
	t__xgarbage	garbage;

	if (_garbage_init(&garbage))
		return (1);
	if (engine_initialization(&garbage, argc, argv))
	{	
		garbage_collector(&garbage);
		return (1);
	}
	garbage_collector(&garbage);
    return (0);
}
