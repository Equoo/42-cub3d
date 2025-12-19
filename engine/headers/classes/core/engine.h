/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:24:40 by dderny            #+#    #+#             */
/*   Updated: 2025/12/01 23:32:21 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <libft.h>
# include <sys/types.h>
# include "classes/object.h"

#define ID_MLX 256

typedef struct {
	id_t	id;
	void	*object;
}		t_singleton;

/** INHERIT object **/
typedef struct s_engine t_engine;
struct s_engine
{
	union {
		t_object	object;
		struct {
	t__xgarbage	*garbage;
	char		**base_classes;
	char		*class_name;
	uint32_t	id;

	void	*(*free)(t_engine *self);
	int		(*_destruct)(t_engine *self);
	int		(*_notification)(t_engine *self, int type, void *data);
	char	*(*_to_string)(t_engine *self);
	int		(*notify)(t_engine *self, int type, void *data);
	int		(*is_class)(t_engine *self, char *classn);
		};
	};
	int			max_fps;
	int			physics_ticks;
	void		*mlx;
	t_singleton	*singletons;

	int		(*add_singleton)(t_engine *self, id_t id, void *singleton);
	void	*(*get_singleton)(t_engine *self, id_t id);
};

t_engine	*engine_new(t__xgarbage *garbage);
int			engine_construct(t_engine *self);
int			engine_destruct(t_engine *self);

int			engine_add_singleton(t_engine *self, id_t id, void *singleton);
void		*engine_get_singleton(t_engine *self, id_t id);

#endif
