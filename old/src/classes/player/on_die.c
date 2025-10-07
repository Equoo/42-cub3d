/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 00:54:58 by dderny            #+#    #+#             */
/*   Updated: 2025/04/27 01:17:52 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/entities/actor.h"
#include "ft_printf.h"
#include "scene.h"
#include "cub3d.h"

void	player_on_die(t_actor *self)
{
	if (self->base->scene->removed)
		return ;
	ft_printf("You died. :\\\n");
	process_close(self->base->scene->env);
}
