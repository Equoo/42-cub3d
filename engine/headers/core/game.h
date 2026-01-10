
#ifndef GAME_H
# define GAME_H
# include "core/engine.h"

extern const int	g_win_width;
extern const int	g_win_height;
extern const char	*g_win_title;

int	game_initialize(t_engine *engine);
int	game_update(t_engine *engine, time_t frametime);
int	game_tick(t_engine *engine, time_t frametime);

#endif

