/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:24:40 by dderny            #+#    #+#             */
/*   Updated: 2025/10/29 00:53:51 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <stdint.h>
# include <ft_vector.h>
# include <ft_string.h>
# include <sys/types.h>
# include <unistd.h>

typedef	void *t_self;

/** INHERIT none **/
typedef struct s_object t_object;
struct s_object
{
	t_str		*base_classes;
	t_str		class_name;
	uint32_t	id;

	void	*(*del)(t_self *self);
	int		(*destruct)(t_self *self);
	t_str	(*to_string)(t_self *self);
	int		(*is_class)(t_self *self, t_str class);
};

int				object_construct(t_object *self);
int				object_destruct(t_object *self);
void			*object_del(t_object *self);

t_str			object_to_string(t_object *self);
int				object_is_class(t_object *self, t_str class);

#endif
