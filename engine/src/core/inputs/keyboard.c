
#include "core/inputs.h"
#include "core/engine.h"

int	inputs_keydown(int key, t_engine *engine)
{
	int	i;
	int	first_zero;

	if (key == XK_Escape)
		engine_close(engine);
	first_zero = -1;
	i = 0;
	while (i < 32)
	{
		if (first_zero == -1 && engine->keys_states[i][0] == 0)
			first_zero = i;
		if (engine->internal_keys[i] == (u_int)key)
			return (0);
		i++;
	}
	if (first_zero != -1)
		engine->internal_keys[first_zero] = key;
	return (0);
}

int	inputs_keyup(int key, t_engine *engine)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (engine->internal_keys[i] == (u_int)key)
		{
			engine->internal_keys[i] = 0;
			return (0);
		}
		i++;
	}
	return (0);
}

