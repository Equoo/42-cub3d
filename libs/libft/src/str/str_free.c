/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:05:41 by dderny            #+#    #+#             */
/*   Updated: 2025/05/09 01:06:31 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"

void	*str_free(t_str string)
{
	if (string)
	{
		vec_free((t_vec)string);
		string = NULL;
	}
	return (NULL);
}
