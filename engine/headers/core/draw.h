
#ifndef GUI_H
# define GUI_H
# include <sys/types.h>
# include "types/image.h"
# include "types/vector2.h"

void draw_pixel(const t_image *img,
		const int x, const int y, const t_rgba color);
void draw_line(const t_image *img,
		t_vec2 p1, const t_vec2 p2, const t_rgba color);
void draw_square(const t_image *img,
		const t_vec2 p1, const t_vec2 p2, const t_rgba color);

#endif
