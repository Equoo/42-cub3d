/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:20:05 by dderny            #+#    #+#             */
/*   Updated: 2025/05/08 17:20:22 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	vec_clear(t_vec vector)
{
	t_vec_header	*header;

	if (!vector)
		return ;
	header = _vec_header(vector);
	header->size = 0;
}
