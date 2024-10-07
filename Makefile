# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/04 10:46:29 by sniemela          #+#    #+#              #
#    Updated: 2024/10/07 14:00:36 by sniemela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Werror -Wextra
CC = gcc

SOURCES = push_swap.c \
			push_and_pop.c \
			rev_rotate.c \
			rotate.c \
			sort_big.c \
			sort_small.c \
			swap.c
		
OBJS = $(SOURCES:.c=.o)

LIBFT_DIR = ../Libft
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
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	@echo "$(CYAN_BOLD)Cleaned up object files from pipex and libft.$(ANSI_RESET)"

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	@echo "$(CYAN_BOLD)Removed $(NAME) and libft.a$(ANSI_RESET)"

re: fclean all
	@echo "$(GREEN_UNDER)Rebuilt everything from scratch$(ANSI_RESET)"

.PHONY: all clean fclean re