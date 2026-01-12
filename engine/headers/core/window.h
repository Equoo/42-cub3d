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

#ifndef WINDOW_H
# define WINDOW_H

# include <mlx.h>
# include <mlx_int.h>

# include <libft.h>
# include <sys/types.h>

# include "core/draw.h"

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_window
{
	int			width;
	int			height;
	char		*title;
	t_image		buffer;
	void		*engine;
	void		*mlx;
	void		*mlx_win;

	int			(*close)();
	int			(*keyup)();
	int			(*keydown)();
	int			(*mouseup)();
	int			(*mousedown)();
	int			(*mousemove)();
	int			(*update)();
}	t_window;

int	window_create(t_window *out, t_window base, void *engine);
int	window_destruct(t_window *win);
int	window_loop(t_window *self);
int	window_drawbuffer(t_window *self);

#endif
