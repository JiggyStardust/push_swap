# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/04 10:46:29 by sniemela          #+#    #+#              #
#    Updated: 2024/10/31 10:14:46 by sniemela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Werror -Wextra
CC = gcc

SOURCES =  count_moves.c \
			cheapest_moves.c \
			find_index.c \
			maximum.c \
			minimum.c \
			memory_handling.c \
			moves_a_to_b.c \
			moves_b_to_a.c \
			parse_input.c \
			push_swap.c \
			push_and_pop.c \
			rev_rotate.c \
			rotate.c \
			sorting.c \
			swap.c
		
OBJS = $(SOURCES:.c=.o)

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a 

INCLUDES = -I$(LIBFT_DIR)

CYAN_BOLD := \e[1;96m
HIB_GREEN := \e[1;92m
GREEN_UNDER := \e[4;32m
ANSI_RESET := \033[0m	

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(HIB_GREEN)$(NAME) has been successfully built!$(ANSI_RESET)"

%.o: %.c
	@echo "Compiling included files..."
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(LIBFT):
	@echo "Building libft..."
	make -C $(LIBFT_DIR)

clean:
	@if [ -n "$(shell find . -name '*.o' 2>/dev/null)" ]; then \
		rm -f $(OBJS); \
		echo "$(CYAN_BOLD)Cleaned up object files from $(NAME).$(ANSI_RESET)"; \
	fi
	@if [ -n "$(shell find Libft -name '*.o' 2>/dev/null)" ]; then \
		make -C $(LIBFT_DIR) clean; \
	fi

fclean: clean
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
		echo "$(CYAN_BOLD)Removed $(NAME) and $(NAME) leftover object files.$(ANSI_RESET)"; \
		make -C $(LIBFT_DIR) fclean; \
	fi

re: fclean all
	@echo "$(GREEN_UNDER)Rebuilt everything from scratch$(ANSI_RESET)"

.PHONY: all clean fclean re