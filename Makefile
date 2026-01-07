NAME = cub3d
CC = cc

DIR_OBJ = obj/
SRC_DIR = src/
INC_DIR = headers/

CFLAGS = -Wall -Wextra -Werror -MMD -mavx2 -g3
INCLUDES = -I engine/$(INC_DIR) -I game/$(INC_DIR) -I libs/libft/headers -I libs/minilibx-linux
LIBS = -Llibs/libft -lft -Llibs/minilibx-linux -lmlx -L/usr/X11/lib -lXext -lX11 -lm

SRCS =
include game_srcs.mk
include engine_srcs.mk
SRCS_BONUS =

OBJS = ${patsubst %.c,$(DIR_OBJ)%.o, $(shell echo $(SRCS) | sed "s|/$(SRC_DIR)|/|g")}
DEPS = ${patsubst %.o,%.d, $(OBJS)}
-include $(DEPS)

MAKEOVERRIDES += -j $(nproc)

.SILENT:

.PHONY: all
all: export CFLAGS += -D DEBUG=0
all: export DEBUG = 0
all: gen_srcs
all: $(NAME)

.PHONY: debug
debug: export CFLAGS += -O0 -g3 -D DEBUG=1
debug: export DEBUG = 1
debug: export TARGET = debug
debug: gen_srcs
debug: $(NAME)

.PHONY: release
release: export CFLAGS += -O3 -flto -D DEBUG=0
release: export DEBUG = 0
release: export TARGET = release
release: gen_srcs
release: $(NAME)

.PHONY: bonus
bonus: export SRCS := $(SRCS) $(SRCS_BONUS)
bonus: gen_srcs
bonus: all

###########################################################
######################### TOOLS ###########################
###########################################################

define gen_srcs_file # arg1: directory and file name
	$(shell echo "# Auto-generated file, do not edit!" > $(1)_srcs.mk)
	$(shell echo -n "SRCS += " >> $(1)_srcs.mk)
	$(shell find $(1)/src -type f -name "*.c" | sed '$$ ! s/$$/ \\/' >> $(1)_srcs.mk)
endef

.PHONY: gen_srcs
gen_srcs:
	$(call gen_srcs_file,engine)
	$(call gen_srcs_file,game)

.PHONY: cachegrind
cachegrind:
	valgrind --tool=cachegrind ./$(NAME) $(ARGS)

.PHONY: callgrind
callgrind:
	valgrind --tool=callgrind --dump-instr=yes --collect-jumps=yes ./$(NAME) $(ARGS)

########################## RULES ###########################

%/:
	mkdir -p $@

$(DIR_OBJ)engine/%.o: engine/$(SRC_DIR)%.c
	echo "Compiling engine $*.c"
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(DIR_OBJ)game/%.o: game/$(SRC_DIR)%.c
	echo "Compiling game $*.c"
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
re: fclean
re: all

.DEFAULT_GOAL = all
