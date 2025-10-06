/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:41:00 by dderny            #+#    #+#             */
/*   Updated: 2025/04/02 20:51:14 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;
	t_list	*last;

	new = NULL;
	last = NULL;
	first = NULL;
	while (lst)
	{
		new = ft_calloc(1, sizeof(t_list));
		if (!new)
			break ;
		if (!first)
			first = new;
		if (last)
			last->next = new;
		new->content = f(lst->content);
		last = new;
		lst = lst->next;
	}
	if (lst)
		ft_lstclear(&first, del);
	return (first);
}
