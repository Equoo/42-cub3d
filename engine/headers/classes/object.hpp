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
# include <sys/types.h>
# include <unistd.h>

typedef	void *t_self;

/** INHERIT none **/
typedef struct s_object t_object;
struct s_object
{
	char		**base_classes;
	char		*class_name;
	uint32_t	id;

	void	*(*free)(t_self *self);
	int		(*destruct)(t_self *self);
	char	*(*to_string)(t_self *self);
	int		(*is_class)(t_self *self, char *classn);
};

int				object_construct(t_object *self);
int				object_destruct(t_object *self);
void			*object_free(t_object *self);

char			*object_to_string(t_object *self);
int				object_is_class(t_object *self, char *classn);

#endif
