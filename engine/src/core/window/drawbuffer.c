
#include "core/window.h"
#include "mlx.h"

int	window_drawbuffer(t_window *self)
{
	mlx_put_image_to_window(self->mlx, self->mlx_win, self->buffer.img, 0, 0);
	return (0);
}

