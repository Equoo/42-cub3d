
#include "core/window.h"

int	window_loop(t_window *self)
{
	mlx_loop(self->mlx);
	return (0);
}

