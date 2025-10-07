/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seed.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:03:34 by dderny            #+#    #+#             */
/*   Updated: 2025/04/25 23:02:00 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "seed.h"

int	*getseed(void)
{
	static int	seed = 0;

	return (&seed);
}

int	rand_int(void)
{
	int	*seed;
	int	res;

	seed = getseed();
	*seed = *seed * 1103515245 + 12345;
	res = (*seed / 65536) % 32768;
	if (res < 0)
		res = -res;
	return (res);
}
