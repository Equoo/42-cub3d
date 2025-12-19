NAME = cub3d
CC = cc

DIR_OBJ = obj/
SRC_DIR = engine/src/
INC_DIR = engine/headers/

CFLAGS = -Wall -Wextra -Werror -MMD -mavx2 -g3
INCLUDES = -I $(INC_DIR) -I libs/libft/headers -I libs/minilibx-linux
LIBS = -Llibs/libft -lft -Llibs/minilibx-linux -lmlx -L/usr/X11/lib -lXext -lX11 -lm

include engine_srcs.mk
SRCS_BONUS =

OBJS = ${patsubst %.c,$(DIR_OBJ)%.o, $(SRCS)}
DEPS = ${patsubst %.c,$(DIR_OBJ)%.d, $(SRCS)}
-include $(DEPS)

.SILENT:

.PHONY: all
all: export CFLAGS := $(CFLAGS) -D DEBUG=0
all: gen_headers gen_srcs
	$(MAKE) -j $(nproc) --no-print-directory $(NAME)

.PHONY: debug
debug: export CFLAGS := $(CFLAGS) -O0 -g3 -D DEBUG=1
debug: export DEBUG := 1
debug: export TARGET := debug
debug: gen_headers gen_srcs
	$(MAKE) -j $(nproc) --no-print-directory $(NAME)

.PHONY: release
release: export CFLAGS := $(CFLAGS) -O3 -flto -D DEBUG=0
release: export TARGET := release
release: gen_headers gen_srcs
	$(MAKE) -j $(nproc) --no-print-directory $(NAME)

.PHONY: bonus
bonus: export SRCS := $(SRCS) $(SRCS_BONUS)
bonus: gen_headers gen_srcs
	$(MAKE) --no-print-directory

###########################################################
######################### TOOLS ###########################
###########################################################

define gen_srcs_file # arg1: directory and file name
	$(shell echo "# Auto-generated file, do not edit!" > $(1)_srcs.mk)
	$(shell echo -n "SRCS = " >> $(1)_srcs.mk)
	$(shell find $(1)/src -type f -name "*.c" | sed 's|$(1)/src/||' | sed '$$ ! s/$$/ \\/' >> $(1)_srcs.mk)
endef

.PHONY: gen_srcs
gen_srcs:
	$(call gen_srcs_file,engine)
	$(call gen_srcs_file,game)

.PHONY: gen_headers
gen_headers:
	python3 scripts/expand_base_comments.py

.PHONY: cachegrind
cachegrind:
	valgrind --tool=cachegrind ./$(NAME) $(ARGS)

.PHONY: callgrind
callgrind:
	valgrind --tool=callgrind --dump-instr=yes --collect-jumps=yes ./$(NAME) $(ARGS)


%/:
	mkdir -p $@

$(DIR_OBJ)%.o: $(SRC_DIR)%.c
	echo "Compiling $*.c"
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: libft
libft:
	echo "Make libft"
	$(MAKE) -s -j $(nproc) -C ./libs/libft $(TARGET)

.PHONY: mlx
mlx:
	$(MAKE) -s -j $(nproc) -C ./libs/minilibx-linux

$(NAME): mlx libft $(DIR_OBJ) $(OBJS) Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBS)


.PHONY: clean
clean:
	$(MAKE) -j $(nproc) clean --no-print-directory -C ./libs/minilibx-linux
	$(MAKE) -j $(nproc) clean --no-print-directory -C ./libs/libft
	rm -Rf $(DIR_OBJ)

.PHONY: fclean
fclean: clean
	$(MAKE) -j $(nproc) fclean --no-print-directory -C ./libs/libft
	rm -f $(NAME)

.PHONY: re
re:
	$(MAKE) -j $(nproc) --no-print-directory fclean
	$(MAKE) --no-print-directory all

.DEFAULT_GOAL = all
