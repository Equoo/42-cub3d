
#include "types/image.h"
#include <mlx.h>

int image_new(void *mlx, int width, int height, t_image *out)
{
	void	*img;

	img = mlx_new_image(mlx, width, height);
	if (!img)
		return (1);
	*out = image_from_mlx(img);
	return (0);
}
