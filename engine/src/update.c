
#include <ft_time.h>
#include <sys/types.h>

#include "core/game.h"
#include "core/engine.h"
#include "core/inputs.h"
#include "mlx.h"

static int time_update(t_engine *engine)
{
	static double	lastrealtime = 0;
	static double	elapsed = 0;

	engine->time = curtime_us();
	if (!engine->start_time)
		engine->start_time = engine->time;
	if (!engine->last_frame)
		engine->last_frame = engine->time;
	if (!lastrealtime)
		lastrealtime = engine->time;
	elapsed += engine->time - lastrealtime;
	if (elapsed >= 1.f / ((double)engine->physics_ticks))
	{
		elapsed -= 1.f / ((double)engine->physics_ticks);
		engine->frametime = (engine->time - engine->last_frame);
		if (engine_tick(engine))
			return (1);
		engine->last_frame = engine->time;
	}
	engine->frametime = (engine->time - lastrealtime);
	lastrealtime = engine->time;
	return (0);
}

int	engine_update(t_engine *engine)
{
	if (time_update(engine)
		|| game_update(engine))
	{
		engine_close(engine);
	}


		return (0);
}

int	engine_tick(t_engine *engine)
{
	inputs_update(engine);
	

	t_camera *camera = &engine->camera;
    if (iskeydown(engine, (uint)'w'))
		camera->pos = vec3_add(camera->pos, vec3_mulf(rot_forward(camera->rot), 250 * engine->frametime));
	if (iskeydown(engine, (uint)'a'))
		camera->pos = vec3_add(camera->pos, vec3_mulf(rot_right(camera->rot), -250 * engine->frametime));
	if (iskeydown(engine, (uint)'d'))
		camera->pos = vec3_add(camera->pos, vec3_mulf(rot_right(camera->rot), 250 * engine->frametime));
	if (iskeydown(engine, (uint)'s'))
		camera->pos = vec3_add(camera->pos, vec3_mulf(rot_forward(camera->rot), -250 * engine->frametime));

	if (iskeydown(engine, (uint)'q'))
		camera->rot.z += -70 * engine->frametime;
	if (iskeydown(engine, (uint)'e'))
		camera->rot.z += 70 * engine->frametime;



	//    draw_square(&engine->window.buffer, (t_vec2){0, 400}, (t_vec2){300, 600}, (t_rgba){.rgb=0xff999999});
	//    int i = 0;
	//    int j = 0;
	//    t_vec2 off = (t_vec2){100, 500};
	// while (j < NSECTORS) {
	// 	i = 0;
	// 	t_sector *sec = engine->world->sectors[j];
	// 	while (i < sec->n_points)
	// 	{
	// 		t_face face_a = sec->faces[i];
	// 		t_face face_b = sec->faces[(i + 1) % sec->n_points];
	// 		draw_line(&engine->window.buffer, vec2_add(vec2_divf(face_a.pos, 20), off), vec2_add(vec2_divf(face_b.pos, 20), off), face_a.color);
	// 		i++;
	// 	}
	// 	j++;
	// }
	//

	int main_sector = sector_from_pos(engine->world, (t_vec2){engine->camera.pos.x, engine->camera.pos.y});
	draw_walls(
			&engine->window.buffer,
			*engine->world,
			engine->camera, main_sector);

	window_drawbuffer(&engine->window);

	__builtin_printf("FPS: %f\n", engine->frametime > 0 ? 1 / engine->frametime : 0);



	game_tick(engine);
	return (0);
}

