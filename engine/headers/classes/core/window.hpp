/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:24:40 by dderny            #+#    #+#             */
/*   Updated: 2025/11/01 02:24:38 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <mlx.h>
# include <mlx_int.h>

# include "classes/core/viewport.h"
# include "classes/core/engine.h"
# include "types/vector2.h"

/** INHERIT viewport **/
typedef struct s_window t_window;
struct s_window
{
	void	*mlx;
	void	*mlx_win;
	t_vec2	size;
	t_vec2	pos;

	int		(*resize)(t_self *self, t_vec2 new_size);
};

t_window		*window_new(t_engine *engine);
int			window_construct(t_window *self, t_engine *engine);
int			window_destruct(t_window *self);

#endif
