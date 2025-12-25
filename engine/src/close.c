

#include "core/engine.h"
#include "core/window.h"

int	engine_close(t_engine *engine)
{
	garbage_collector(engine->garbage);
	window_destruct(&engine->window);

	return (0);
}
