/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:01:12 by dderny            #+#    #+#             */
/*   Updated: 2025/05/12 13:03:51 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t__allocs	*__get_ft_allocations(void)
{
	static t__allocs	data = {NULL, 4, 0, 0};

	if (!data.allocations)
		data.allocations = malloc(sizeof(t__alloc) * data.capacity);
	return (&data);
}
