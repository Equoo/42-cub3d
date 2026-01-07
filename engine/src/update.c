
#include "core/game.h"
#include "core/engine.h"

int	engine_update(t_engine *engine)
{
	game_update(engine, 0);
	return (0);
}
