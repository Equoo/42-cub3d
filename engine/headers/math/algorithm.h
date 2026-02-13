/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_extend.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:29:53 by dderny            #+#    #+#             */
/*   Updated: 2025/10/31 05:27:07 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H
# include "core/world.h"

t_hit dda_trace(t_vec2 pos, t_vec2 dir, t_map grid);

#endif
