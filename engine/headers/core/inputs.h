
#ifndef INPUTS_H
# define INPUTS_H
# include "core/engine.h"

int	inputs_mousedown(t_engine *engine, int key);
int	inputs_mousemove(t_engine *engine, int x, int y);
int	inputs_mouseup(t_engine *engine, int key);

int	inputs_keydown(t_engine *engine, int key);
int	inputs_keyup(t_engine *engine, int key);

int	iskeydown(t_engine *engine, int key);
int	iskeyup(t_engine *engine, int key);

#endif
