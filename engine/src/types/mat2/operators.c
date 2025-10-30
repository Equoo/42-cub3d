/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:51:08 by dderny            #+#    #+#             */
/*   Updated: 2025/10/30 12:10:34 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <types/mat2.h>

t_mat2	mat2_mul(t_mat2 a, t_mat2 b)
{
	t_mat2	result;

	result.origin = (t_vec2){
		a.origin.x * b.origin.x + a.origin.y * b.origin.y,
		a.origin.x * b.origin.x + a.origin.y * b.origin.y};
	result.x = (t_vec2){
		a.x.x * b.x.x + a.x.y * b.y.x,
		a.x.x * b.x.y + a.x.y * b.y.y};
	result.y = (t_vec2){
		a.y.x * b.x.x + a.y.y * b.y.x,
		a.y.x * b.x.y + a.y.y * b.y.y};
	return (result);
}

t_mat2	mat2_mulv(t_mat2 a, t_vec2 b)
{
	t_mat2	result;

	result.origin = (t_vec2){
		a.origin.x * b.x + a.origin.y * b.y,
		a.origin.x * b.x + a.origin.y * b.y};
	result.x = (t_vec2){
		a.x.x * b.x + a.x.y * b.y,
		a.x.x * b.x + a.x.y * b.y};
	result.y = (t_vec2){
		a.y.x * b.x + a.y.y * b.y,
		a.y.x * b.x + a.y.y * b.y};
	return (result);
}

t_mat2	mat2_mulf(t_mat2 a, float b)
{
	t_mat2	result;

	result.origin = (t_vec2){a.origin.x * b, a.origin.y * b};
	result.x = (t_vec2){a.x.x * b, a.x.y * b};
	result.y = (t_vec2){a.y.x * b, a.y.y * b};
	return (result);
}

t_mat2	mat2_muli(t_mat2 a, int b)
{
	t_mat2	result;

	result.origin = (t_vec2){a.origin.x * b, a.origin.y * b};
	result.x = (t_vec2){a.x.x * b, a.x.y * b};
	result.y = (t_vec2){a.y.x * b, a.y.y * b};
	return (result);
}