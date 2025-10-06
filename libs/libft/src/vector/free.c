/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:44:36 by dderny            #+#    #+#             */
/*   Updated: 2025/05/08 16:45:08 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_vector.h"
#include <stdlib.h>

void	*vec_free(t_vec vector)
{
	t_vec_header	*header;

	if (!vector)
		return (NULL);
	header = _vec_header(vector);
	ft_free(header);
	return (NULL);
}
