/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:45:46 by dderny            #+#    #+#             */
/*   Updated: 2025/10/30 13:09:15 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/mat2.h"

void	mat2_scale_basis(t_mat2 *m, t_vec2 s)
{
	m->col[0] = vec2_mul(m->col[0], s);
	m->col[1] = vec2_mul(m->col[1], s);
}

void	mat2_scale(t_mat2 *m, t_vec2 v)
{
	mat2_scale_basis(m, v);
	m->origin = vec2_mul(m->origin, v);
}

t_mat2	mat2_scaled(t_mat2 m, t_vec2 v)
{
	mat2_scale(&m, v);
	return (m);
}

t_mat2	mat2_scaled_local(t_mat2 m, t_vec2 v)
{
	vec2_mulf_by(&m.col[0], v.x);
	vec2_mulf_by(&m.col[1], v.y);
	return (m);
}
