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
#include "libft.h"
#include "ft_printf.h"
#include <math.h>
#include <bench.h>
#include <math_extend.h>

int	engine_initialization(t__xgarbage *garbage, int argc, char *argv[])
{
	t_engine	*engine;
	
	engine = engine_new(garbage);
	if (!engine)
		return (1);

	ft_printf("Main object: %!s\n", engine->_to_string(engine));
	(void)argc;
    (void)argv;

	// display_trigo_benchmark();
	// display_dist_benchmark();
	// display_sqrtf_benchmark();

	if (engine)
		engine->free(engine);
	return (0);
}


int	format(char *str, const size_t size, char *format, ...);

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
