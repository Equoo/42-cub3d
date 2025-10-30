STATE_FILE := .state.tmp
NAME = libft.a
CC = cc
AR = ar -rcs

DIR_OBJ = obj/
SRC_DIR = src/
INC_DIR = headers/

ADDFLAGS = -D DEBUG=0
CFLAGS = -Wall -Wextra -Werror -MMD -mavx2 $(ADDFLAGS) -I $(INC_DIR)
SRCS =	string/ft_split.c\
		string/ft_strchr.c\
		string/ft_strchrpos.c\
		string/ft_strdup.c\
		string/ft_strjoin.c\
		string/ft_strlcat.c\
		string/ft_strlcpy.c\
		string/ft_strlen.c\
		string/ft_strmapi.c\
		string/ft_strcmp.c\
		string/ft_strncmp.c\
		string/ft_strnstr.c\
		string/ft_strrchr.c\
		string/ft_strtrim.c\
		string/ft_substr.c\
		string/ft_stradd.c\
\
		char/ft_isalnum.c\
		char/ft_isalpha.c\
		char/ft_isascii.c\
		char/ft_isdigit.c\
		char/ft_isspace.c\
		char/ft_isprint.c\
		char/ft_tolower.c\
		char/ft_toupper.c\
\
		memory/ft_freearray.c\
		memory/ft_arraylen.c\
		memory/ft_calloc.c\
		memory/ft_bzero.c\
		memory/ft_memcpy.c\
		memory/ft_memchr.c\
		memory/ft_memcmp.c\
		memory/ft_memcpy.c\
		memory/ft_memmove.c\
		memory/ft_memset.c\
		memory/ft_memsetint.c\
		memory/ft_print_memory.c\
\
		vector/append.c\
		vector/insert.c\
		vector/cat.c\
		vector/clear.c\
		vector/copy.c\
		vector/remove.c\
		vector/pop.c\
		vector/size.c\
		vector/new.c\
		vector/header.c\
		vector/free.c\
		vector/capacity.c\
\
		alloc/ft_calloc.c\
		alloc/ft_realloc.c\
		alloc/allocs.c\
		alloc/ft_free.c\
		alloc/ft_alloc.c\
\
		list/ft_lstadd_back.c\
		list/ft_lstadd_front.c\
		list/ft_lstclear.c\
		list/ft_lstdelone.c\
		list/ft_lstrmone.c\
		list/ft_lstiter.c\
		list/ft_lstlast.c\
		list/ft_lstmap.c\
		list/ft_lstnew.c\
		list/ft_lstsize.c\
\
		write/ft_putchar_fd.c\
		write/ft_putendl_fd.c\
		write/ft_putnbr_fd.c\
		write/ft_putstr_fd.c\
\
		mm256/bit.c\
		mm256/math.c\
\
		convert/ft_atoi.c\
		convert/ft_atof.c\
		convert/ft_atoll.c\
		convert/ft_itoa.c\
		convert/ft_itoato.c\
		convert/ft_strtol.c\
		convert/ft_strtoi.c\
\
		printf/converts.c\
		printf/nbrtostr.c\
		printf/utils.c\
		printf/float.c\
		printf/core.c\
		printf/printf.c\
		printf/snprintf.c\
\
		get_next_line/utils.c\
		get_next_line/core.c\
\
		time/ft_uptime.c\
		time/curtime_us.c\
\
		errno/ft_strerror.c\
\
		math/ft_abs.c\
		math/ft_fabs.c\
		math/ft_min.c\
		math/ft_max.c\
		math/ft_max.c\
		math/ft_lerp.c\
		math/ft_clamp.c

DIR_OBJ = obj/
OBJS = ${patsubst %.c,$(DIR_OBJ)%.o, $(SRCS)}

DEPS= ${patsubst %.c,$(DIR_OBJ)%.d, $(SRCS_ALL)}
-include $(DEPS)

# Colors for output
GREEN  := \033[1;32m
BLUE   := \033[1;34m
YELLOW := \033[1;33m
RED    := \033[1;31m
RESET  := \033[0m
ECHO   := /bin/echo

.PHONY: all
all: check_build
	$(MAKE) -j$(shell nproc) --no-print-directory $(NAME)
	@STATE=$$(cat $(STATE_FILE) 2>/dev/null || echo 0); \
	if [ $$STATE -eq 1 ]; then \
		$(ECHO) -e "$(BLUE)[✓] Libft is up to date!$(RESET)"; \
	else \
		$(ECHO) -e "$(GREEN)[✓] Libft build completed!$(RESET)"; \
	fi

# Check if recompilation is needed
.PHONY: check_build
check_build:
	@$(ECHO) "0" > $(STATE_FILE);
	@if [ -z "$(wildcard $(OBJS))" ] || [ Makefile -nt $(NAME) ]; then \
		$(ECHO) -e "$(YELLOW)[Building libft]$(RESET)"; \
		$(ECHO) "0" > $(STATE_FILE); \
	elif ! find $(SRC_DIR) -type f -name '*.c' -newer $(NAME) | grep -q . && \
		! find $(INC_DIR) -type f -name '*.h' -newer $(NAME) | grep -q .; then \
		$(ECHO) "1" > $(STATE_FILE); \
	fi

.PHONY: debug
debug:
	$(MAKE) -j$(shell nproc) --no-print-directory ADDFLAGS="-D DEBUG=1 -g3" $(NAME)

.PHONY: release
release:
	$(MAKE) -j$(shell nproc) --no-print-directory ADDFLAGS="-D DEBUG=0 -O3" $(NAME)

%/:
	mkdir -p $@

$(DIR_OBJ)%.o: $(SRC_DIR)%.c
	@$(ECHO) -e "\t$(YELLOW)Compiling $*.c$(RESET)"
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(DIR_OBJ) $(OBJS) Makefile
	$(AR) $@ $(OBJS)
	ranlib $(NAME)

.PHONY: clean
clean:
	rm -f $(STATE_FILE)
	rm -Rf $(DIR_OBJ)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) all

.DEFAULT_GOAL = all
