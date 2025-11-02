/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:24:40 by dderny            #+#    #+#             */
/*   Updated: 2025/11/02 04:32:03 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <libft.h>
# include <stdint.h>
# include <ft_vector.h>
# include <sys/types.h>
# include <unistd.h>

typedef	void *t_self;

/** INHERIT none **/
typedef struct s_object t_object;
struct s_object
{
	t__xgarbage	*garbage;
	char		**base_classes;
	char		*class_name;
	uint32_t	id;

	void	*(*free)(t_object *self);
	int		(*_destruct)(t_object *self);
	int		(*_notification)(t_object *self, int type, void *data);
	char	*(*_to_string)(t_object *self);
	int		(*notify)(t_object *self, int type, void *data);
	int		(*is_class)(t_object *self, char *classn);
};

int				object_construct(t_object *self);
int				object_destruct(t_object *self);
void			*object_free(t_object *self);

char			*object_to_string(t_object *self);
int				object_is_class(t_object *self, char *classn);

#endif
