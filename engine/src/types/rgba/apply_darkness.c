/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_darkness.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 21:44:14 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 03:00:26 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/rgba.h"

t_rgba	apply_darkness(t_rgba color, float darkness)
{
	t_rgba	result;

	result = color;
	result.r *= darkness;
	result.g *= darkness;
	result.b *= darkness;
	return (result);
}
