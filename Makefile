define gen_srcs_file # arg1: directory and file name
	$(shell echo "# Auto-generated file, do not edit!" > $(1)_srcs.mk)
	$(shell echo -n "SRCS = " >> $(1)_srcs.mk)
	$(shell find $(1)/src -type f -name "*.c" | sed 's|$(1)/src/||' | sed '$$ ! s/$$/" \\/' >> $(1)_srcs.mk)
endef

.PHONY: generate_srcs
generate_srcs:
	$(call gen_srcs_file,engine)

NAME = so_long
CC = cc

DIR_OBJ = obj/
SRC_DIR = src/
INC_DIR = headers/

ADDFLAGS =
CFLAGS = -Wall -Wextra -Werror -MMD -mavx2 $(ADDFLAGS) -I $(INC_DIR) -I libft/headers -I minilibx-linux
LIBS = -Llibft -lft -Lminilibx-linux -lmlx -L/usr/X11/lib -lXext -lX11 -lm
SOLONG_SRCS = 

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
