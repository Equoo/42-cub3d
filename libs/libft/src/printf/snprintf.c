/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:51:10 by dderny            #+#    #+#             */
/*   Updated: 2025/10/30 11:52:23 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

void	shame_vsnprintf(t_pdata data, char *str, size_t i)
{
	ft_strlcpy(str + data.count, data.str, data.strlen + 1);
	data.count += data.strlen;
	free(data.str);
	i = i + data.next;
	data.last = i + 1;
}
