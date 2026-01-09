
#ifndef GUI_H
# define GUI_H
# include <sys/types.h>
# include "types/vector2.h"

typedef union u_rgba
{
	unsigned int	rgb;
	struct
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	};
	}			t_rgba;

typedef struct s_image
{
	void	*img;
	t_rgba	*data;
	int		size_line;
	int		width;
	int		height;
	int		size;
} t_image;

void draw_pixel(const t_image img,
		const int x, const int y, const t_rgba color);
void draw_line(const t_image img,
		t_vec2 p1, const t_vec2 p2, const t_rgba color);
void draw_square(const t_image img,
		const t_vec2 p1, const t_vec2 p2, const t_rgba color);

#endif
