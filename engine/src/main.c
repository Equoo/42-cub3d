/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:33:22 by dderny            #+#    #+#             */
/*   Updated: 2025/11/02 04:31:23 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/core/engine.h"
#include "libft.h"
#include <math.h>
#include <bench.h>
#include <math_extend.h>

int main(int argc, char *argv[])
{
	t__xgarbage	garbage;
	t_engine	*engine;

	if (_garbage_init(&garbage))
		return (1);
	engine = engine_new(&garbage);
	if (!engine)
		return (1);

	(void)argc;
    (void)argv;
    
	display_trigo_benchmark();
	display_dist_benchmark();
	display_sqrtf_benchmark();
	
    return (0);
}
