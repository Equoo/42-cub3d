/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:59:29 by dderny            #+#    #+#             */
/*   Updated: 2025/04/26 19:52:49 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "classes/element.h"

#include <X11/X.h>
#include <ft_vector.h>
#include <libft.h>

void	element_lst_del(void *self)
{
	t_element	*elem;

	elem = (t_element *)self;
	elem->del((t_element **)&self);
}

void	scene_del(void *self)
{
	t_scene		*scene;

	scene = (t_scene *)self;
	scene->removed = TRUE;
	if (scene->elements)
		ft_lstclear(&scene->elements, &element_lst_del);
	if (scene->name)
		free(scene->name);
	free(scene);
}

t_scene	*ft_scene(void *env, char *name)
{
	t_scene	*scene;

	scene = (t_scene *)ft_calloc(1, sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->env = env;
	scene->name = ft_strdup(name);
	if (!scene->name)
	{
		scene_del(scene);
		return (NULL);
	}
	return (scene);
}

static int	is_front(t_list *elements, t_element *elem)
{
	return (!elements
		|| ((t_element *)elements->content)->zindex > elem->zindex);
}

int	scene_add(t_scene *self, void *element)
{
	t_element	*elem;
	t_list		*node;
	t_list		*tmp;

	elem = cast_element(element);
	if (!elem)
		return (1);
	node = ft_lstnew(elem);
	if (!node)
		elem->del(&elem);
	if (!node)
		return (1);
	if (is_front(self->elements, elem))
		ft_lstadd_front(&self->elements, node);
	else if (self->elements)
	{
		tmp = self->elements;
		while (tmp->next
			&& ((t_element *)tmp->next->content)->zindex <= elem->zindex)
			tmp = tmp->next;
		ft_lstadd_front(&tmp->next, node);
	}
	else
		ft_lstadd_back(&self->elements, node);
	return (0);
}
