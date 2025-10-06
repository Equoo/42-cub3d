/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:46:44 by dderny            #+#    #+#             */
/*   Updated: 2025/05/08 16:47:11 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

size_t	vec_capacity(t_vec vector)
{
	t_vec_header	*header;

	if (!vector)
		return (0);
	header = _vec_header(vector);
	return (header->capacity);
}
