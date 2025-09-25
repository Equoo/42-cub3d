/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:03:13 by dderny            #+#    #+#             */
/*   Updated: 2025/04/26 01:52:56 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "seed.h"
#include "texture.h"
#include "error.h"
#include "input.h"
#include "render.h"
#include "scene.h"
#include "cub3d.h"
#include <errno.h>
#include <ft_printf.h>
#include <ft_time.h>
#include <ft_vector.h>
#include <libft.h>
#include <mlx.h>

//pacat --rate=8000 --format=u8 --channels=1
//static int fd;
//char line[180];
//if (!fd)
	//fd = open("music.raw", O_RDONLY);
//read(fd, line, 180);
//write(1, line, 180);

int	main(int argc, char **argv)
{
	t_gameenv	env;

	env = (t_gameenv){0};
	if (argc != 2)
	{
		errno = EINVAL;
		return (process_close(&env));
	}
	if (render_init(&env))
		return (process_close(&env));
	errno = 0;
	if (game_init(&env, argv[1]))
		return (process_close(&env));
    
	mlx_hook(env.render.win, ON_DESTROY, 0, &process_close, &env);
	mlx_hook(env.render.win, ON_KEYDOWN, KeyPressMask, &down_key, &env);
	mlx_hook(env.render.win, ON_KEYUP, KeyReleaseMask, &up_key, &env);
	mlx_loop_hook(env.render.mlx, &update, &env);
	mlx_loop(env.render.mlx);
	return (EXIT_SUCCESS);
}

void	printticks(t_gameenv *env)
{
	static double	last = 0;
	static double	middle = 0;
	static int		fps = TICK;
	static int		count = 0;

	middle = middle + env->frametime;
	count++;
	if (env->time - last >= 1)
	{
		middle /= count;
		count = 0;
		fps = 1 / middle;
		env->smooth_fps = fps;
		middle = env->frametime;
		last = env->time;
	}
}

int	update(t_gameenv *env)
{
	static double	lastrealtime = 0;
	static double	elapsed = 0;

	errno = 0;
	env->time = curtime_us();
	if (env->time == -1 && print_error("Time"))
		process_close(env);
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
	if (errno && errno != EAGAIN && print_error("Update"))
		process_close(env);
	return (0);
}

void	tick(t_gameenv *env)
{
	printticks(env);
	*getseed() = ((t_scene *)env->scene)->seed;
	tick_inputs(env);
	tick_game(env);
	tick_render(env, &env->render);
}

int	process_close(t_gameenv *env)
{
	vec_free(env->render.texts);
	ft_lstclear(&env->scenes_lst, &scene_del);
	ft_lstclear(&env->render.textures, &texture_del);
	if (env->render.buffer)
		mlx_destroy_image(env->render.mlx, env->render.buffer);
	if (env->render.win)
		mlx_destroy_window(env->render.mlx, env->render.win);
	if (env->render.mlx)
	{
		mlx_destroy_display(env->render.mlx);
		free(env->render.mlx);
	}
	if (errno != EAGAIN && errno && print_error("Initialization"))
		exit(errno);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
