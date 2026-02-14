
#include "core/game.h"
#include "core/parse.h"

const int	g_win_width = 1920;
const int	g_win_height = 1080;

const char	*g_win_title = "Cub3d";

int	game_initialize(t_engine *engine)
{
	// (void)engine;
	check_map_validity("exemple.cub", engine->map);
	return (0);
}

int	game_update(t_engine *engine)
{
	(void)engine;
	return (0);
}

int game_tick(t_engine *engine)
{
	(void)engine;
	return (0);
}


