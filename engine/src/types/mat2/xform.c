/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xform.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:08:06 by dderny            #+#    #+#             */
/*   Updated: 2025/10/30 13:05:59 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <types/mat2.h>

t_vec2	mat2_xform(t_mat2 m, t_vec2 v)
{
	return (vec2_add((t_vec2){
		mat2_tdotx(m, v),
		mat2_tdoty(m, v)
	}, m.origin));
}

t_vec2	mat2_xform_inv(t_mat2 m, t_vec2 v)
{
	t_vec2 inv_v;

	inv_v = vec2_sub(v, m.origin);
	
	return ((t_vec2){
		vec2_dot(m.col[0], inv_v),
		vec2_dot(m.col[1], inv_v)
	});
}

t_vec2	mat2_basis_xform(t_mat2 m, t_vec2 v)
{
	return ((t_vec2){
		mat2_tdotx(m, v),
		mat2_tdoty(m, v)
	});
}

t_vec2	mat2_basis_xform_inv(t_mat2 m, t_vec2 v)
{
	return ((t_vec2){
		vec2_dot(m.col[0], v),
		vec2_dot(m.col[1], v)
	});
}
