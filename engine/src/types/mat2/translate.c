/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:45:46 by dderny            #+#    #+#             */
/*   Updated: 2025/10/07 16:17:56 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat2.h"

void	mat2_translate(t_mat2 *m, t_vec2 v)
{
	m->origin = vec2_add(m->origin, v);
}

t_mat2	mat2_translated(t_mat2 m, t_vec2 v)
{
	m.origin = vec2_add(m.origin, v);
	return (m);
}

t_mat2	mat2_translated_local(t_mat2 m, t_vec2 v)
{
	m.origin = vec2_add(m.origin, mat2_basis_xform(m, v));
	return (m);
}