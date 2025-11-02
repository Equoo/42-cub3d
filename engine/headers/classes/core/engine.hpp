/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:24:40 by dderny            #+#    #+#             */
/*   Updated: 2025/11/02 04:32:59 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <libft.h>
# include <sys/types.h>
# include "classes/object.h"

typedef struct {
	id_t	id;
	void	*object;
}		t_singleton;

/** INHERIT object **/
typedef struct s_engine t_engine;
struct s_engine
{
	int			max_fps;
	int			physics_ticks;
	void		*singletons;

	int		(*add_singleton)(t_self *self, id_t id, void *singleton);
	void	*(*get_singleton)(t_self *self, id_t id);
};

t_engine		*engine_new(t__xgarbage *garbage);
int			engine_construct(t_engine *self);
int			engine_destruct(t_engine *self);

#endif
