NAME = cub3D
CC = cc

DIR_OBJ = obj/
SRC_DIR = src/
INC_DIR = headers/

CFLAGS = -Wall -Wextra -Werror -MMD -mavx2 -g3
INCLUDES = -I engine/$(INC_DIR) -I game/$(INC_DIR) -I libs/libft/headers -I libs/minilibx-linux
LIBS = -Llibs/libft -lft -Llibs/minilibx-linux -lmlx -L/usr/X11/lib -lXext -lX11 -lm

SRCS =
SRCS_BONUS =
include game_srcs.mk
include engine_srcs.mk
include engine_bonus.mk

ifneq ($(filter bonus,$(MAKECMDGOALS)),)
	SRCS += $(SRCS_BONUS)
endif

OBJS = ${patsubst %.c,$(DIR_OBJ)%.o, $(shell echo $(SRCS) | sed "s|/$(SRC_DIR)|/|g")}
DEPS = ${patsubst %.o,%.d, $(OBJS)}

-include $(DEPS)

# MAKEFLAGS += -j $(nproc)

MODE ?= debug

ifeq ($(filter $(MODE),debug release),)
$(error MODE must be 'debug' or 'release')
endif

ifeq ($(MODE),debug)
	CFLAGS += -O0 -g3 -D DEBUG=1
	DEBUG = 1
	TARGET = debug
endif

ifeq ($(MODE),release)
	CFLAGS += -O3 -flto -D DEBUG=0
	DEBUG = 0
	TARGET = release
endif

.SILENT:

.PHONY: all
all: gen_srcs
all: $(NAME)

test: export CFLAGS += -DUNITTEST=1
test: all

.PHONY: bonus
bonus: export CFLAGS += -DBONUS=1
bonus: all

###########################################################
######################### TOOLS ###########################
###########################################################

define gen_srcs_file # arg1: directory and file name
	$(shell echo "# Auto-generated file, do not edit!" > $(1)_srcs.mk)
	$(shell echo -n "SRCS += " >> $(1)_srcs.mk)
	$(shell find $(1)/src -type f -name "*.c" | sed "s/.*_bonus.c//" | sed '$$ ! s/$$/ \\/' >> $(1)_srcs.mk)
endef

.PHONY: gen_srcs
gen_srcs:
	$(call gen_srcs_file,engine)
	$(call gen_srcs_file,game)

.PHONY: test_parsing
test_parsing: all
	for map in game/maps/parsing/*.cub; do \
		echo "--- $$(basename $$map) ---"; \
		timeout 1 ./$(NAME) $$map 2>&1; ret=$$?; \
		if [ $$ret -eq 0 ] || [ $$ret -eq 124 ]; then echo "[OK]"; else echo "[FAIL]"; fi; \
	done

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
