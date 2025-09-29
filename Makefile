NAME = so_long
CC = cc

DIR_OBJ = obj/
SRC_DIR = src/
INC_DIR = headers/

ADDFLAGS =
CFLAGS = -Wall -Wextra -Werror -MMD -mavx2 $(ADDFLAGS) -I $(INC_DIR) -I libft/headers -I minilibx-linux
LIBS = -Llibft -lft -Lminilibx-linux -lmlx -L/usr/X11/lib -lXext -lX11 -lm
SOLONG_SRCS =   vector2d/add.c\
				vector2d/dot.c\
				vector2d/cross.c\
				vector2d/scale.c\
				vector2d/sub.c\
				vector2d/length.c\
				vector2d/normalize.c\
				vector2d/multiply.c\
				vector2d/divide.c\
				vector2d/scaled.c\
				vector2d/scale_divided.c\
				vector2d/convert.c\
				vector2d/abs.c\
				vector2d/transform.c\
				vector2d/lerp.c\
				vector2d/dist.c\
				vector2d.c\
				vector3d/add.c\
				vector3d/dot.c\
				vector3d/scale.c\
				vector3d/sub.c\
				vector3d/length.c\
				vector3d/normalize.c\
				vector3d/multiply.c\
				vector3d/divide.c\
				vector3d/scaled.c\
				vector3d/scale_divided.c\
				vector3d/convert.c\
				vector3d/abs.c\
				vector3d/transform.c\
				vector3d/lerp.c\
				vector3d.c\
				texture/data.c\
				texture/draw_slice.c\
				texture/get_frame.c\
				texture/texture_slice_time.c\
				texture.c\
				classes/element/play_anim.c\
				classes/element/draw.c\
				classes/element.c\
				classes/terrain/grid_utils.c\
				classes/terrain/wall_rules.c\
				classes/terrain/surface_others.c\
				classes/terrain/surface_corgrass.c\
				classes/terrain/surface_rules_utils.c\
				classes/terrain/load.c\
				classes/terrain/findpath.c\
				classes/terrain.c\
				collisions/aabb.c\
				scene.c\
            	render/pixel.c\
            	render/copy.c\
            	render/fast_copy.c\
            	render/blend.c\
            	render/text.c\
            	render/fast_blend.c\
            	render/img.c\
            	render/colors.c\
            	render/m256_colors.c\
				inputs/update.c\
				inputs/isdown.c\
				inputs/ispressed.c\
				inputs/isreleased.c\
            	error.c\
            	seed.c\
            	tick_game.c\
            	game.c\
            	render.c\
            	main.c\

#classes/actor/draw.c\
#				classes/actor/move.c\
#				classes/actor/update.c\
#				classes/actor.c\
#				collisions/sweep_aabb.c\
#				classes/entity/physic.c\
#				classes/entity.c\
#				classes/player/anim_coroutine.c\
#				classes/player/update.c\
#				classes/player/on_die.c\
#				classes/player/attack.c\
#				classes/player.c\			collisions/world_sweep_aabb.c\

				OBJS = ${patsubst %.c,$(DIR_OBJ)%.o, $(SOLONG_SRCS)}

DEPS= ${patsubst %.c,$(DIR_OBJ)%.d, $(SOLONG_SRCS)}
-include $(DEPS)

.SILENT:

.PHONY: all
all:
	$(MAKE) -j $(nproc) --no-print-directory LIBFTTARGET="all" ADDFLAGS="-O3" SOLONG_SRCS="$(SOLONG_SRCS)" $(NAME)

.PHONY: debug
debug:
	$(MAKE) -j $(nproc) --no-print-directory LIBFTTARGET="debug" ADDFLAGS="-O0 -g3 -D DEBUG=1" SOLONG_SRCS="$(SOLONG_SRCS)" $(NAME)

.PHONY: release
release:
	$(MAKE) -j $(nproc) --no-print-directory LIBFTTARGET="release" ADDFLAGS="-O3 -D DEBUG=0 -flto" SOLONG_SRCS="$(SOLONG_SRCS)" $(NAME)


.PHONY: bonus
bonus:
	$(MAKE) --no-print-directory ADDFLAGS="-O3" SOLONG_SRCS="$(SRCS_BONUS)"

.PHONY: cachegrind
cachegrind:
	valgrind --tool=cachegrind ./$(NAME) $(MAP)

.PHONY: callgrind
callgrind:
	valgrind --tool=callgrind --dump-instr=yes --collect-jumps=yes ./$(NAME) $(MAP)

.PHONY: supressor
supressor:
	/bin/echo -e "\
	{\n\
		ignore_libmlx_error\n\
		Memcheck:Param\n\
		writev(vector[0])\n\
		fun:__internal_syscall_cancel\n\
		fun:__syscall_cancel\n\
		fun:writev\n\
		fun:UnknownInlinedFun\n\
		fun:_xcb_conn_wait.part.0\n\
		fun:UnknownInlinedFun\n\
		fun:_xcb_out_send\n\
		fun:UnknownInlinedFun\n\
		fun:xcb_writev\n\
		fun:_XSend\n\
		fun:_XReadEvents\n\
		fun:XWindowEvent\n\
		fun:mlx_int_wait_first_expose\n\
		fun:mlx_new_window\n\
	},\n\
	{\n\
		ignore_libmlx_leaks\n\
		Memcheck:Leak\n\
		...\n\
		obj:/libmlx.a.\n\
	}\
	" > mlx.supp

%/:
	mkdir -p $@

$(DIR_OBJ)%.o: $(SRC_DIR)%.c
	echo "Compiling $*.c"
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

LIBFTTARGET = all
.PHONY: libft
libft:
	echo "Make libft"
	$(MAKE) -s -j $(nproc) -C ./libft $(LIBFTTARGET)

.PHONY: mlx
mlx:
	$(MAKE) -s -j $(nproc) -C ./minilibx-linux

$(NAME): mlx libft $(DIR_OBJ) $(OBJS) Makefile
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

.PHONY: clean
clean:
	$(MAKE) -j $(nproc) clean --no-print-directory -C ./minilibx-linux
	$(MAKE) -j $(nproc) clean --no-print-directory -C ./libft
	rm -Rf $(DIR_OBJ)

.PHONY: fclean
fclean: clean
	$(MAKE) -j $(nproc) fclean --no-print-directory -C ./libft
	rm -f $(NAME)

.PHONY: re
re:
	$(MAKE) -j $(nproc) --no-print-directory fclean
	$(MAKE) --no-print-directory all

.DEFAULT_GOAL = all
