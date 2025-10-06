/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:47:06 by dderny            #+#    #+#             */
/*   Updated: 2025/05/09 01:05:21 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include "libft.h"

t_str	str_new(t_str str)
{
	t_str	new;
	size_t	len;

	len = 0;
	if (str)
		len = ft_strlen(str);
	new = vec_new(len + 1, sizeof(char));
	if (!new)
		return (NULL);
	if (str)
		ft_strlcpy(new, str, len + 1);
	return (new);
}
