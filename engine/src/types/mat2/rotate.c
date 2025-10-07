/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:45:46 by dderny            #+#    #+#             */
/*   Updated: 2025/10/07 16:27:45 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat2.h"

void	mat2_rotate(t_mat2 *m, float angle)
{
	t_mat2	r_mat;
	r_mat = mat2_from_rp(angle, VEC2_ZERO);
	*m = mat2_mul(r_mat, *m));
}

t_mat2	mat2_rotated(t_mat2 m, float angle)
{
	t_mat2	r_mat;
	r_mat = mat2_from_rp(angle, VEC2_ZERO);
	return (mat2_mul(r_mat, m));
}

t_mat2	mat2_rotated_local(t_mat2 m, float angle)
{
	t_mat2	r_mat;
	r_mat = mat2_from_rp(angle, VEC2_ZERO);
	return (mat2_mul(m, r_mat));
}