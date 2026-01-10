
#include <ft_time.h>

#include "core/game.h"
#include "core/engine.h"

int	engine_update(t_engine *engine)
{
	static double	lastrealtime = 0;
	static double	elapsed = 0;

	engine->time = curtime_us();
	if (!env->start_time)
		env->start_time = env->time;
	if (!env->last_frame)
		env->last_frame = env->time;
	if (!lastrealtime)
		lastrealtime = env->time;
	elapsed += env->time - lastrealtime;
	if (elapsed >= 1.f / ((double)TICK))
	{
		elapsed -= 1.f / ((double)TICK);
		env->frametime = (env->time - env->last_frame);
		tick(env);
		env->last_frame = env->time;
	}
	lastrealtime = env->time;


	game_update(engine, 0);
	return (0);
}

int	engine_tick(t_engine *engine, time_t frametime)
{
	(void)frametime;
	(void)engine;
	return (0);
}

