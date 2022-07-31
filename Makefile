# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 22:39:01 by libacchu          #+#    #+#              #
#    Updated: 2022/07/31 21:39:02 by libacchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = ./src
SRC = $(SRC_DIR)/main.c \
		$(SRC_DIR)/ft_free.c \
		$(SRC_DIR)/exector.c \
		$(SRC_DIR)/exe_library.c \
		$(SRC_DIR)/handler.c \
		$(SRC_DIR)/make_cmd.c \
		$(SRC_DIR)/builtins/echo.c \
		$(SRC_DIR)/builtins/pwd.c \
		$(SRC_DIR)/builtins/env.c \
		$(SRC_DIR)/builtins/isbuiltin.c\

OBJS = $(SRC:%.c=%.o)
RM = rm -f

RL_MAC = -I $(HOME)/goinfre/.brew/opt/readline/include/ -L $(HOME)/goinfre/.brew/opt/readline/lib/ -lreadline

$(NAME): $(OBJS)
	make -C ./libft
	make -C ./libft/ft_printf
	make bonus -C ./libft/
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT) $(FT_PRINTF) $(RL_MAC) -o $(NAME)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./libft/ft_printf
FT_PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C ./libft
	make clean -C ./libft/ft_printf

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft
	make fclean -C ./libft/ft_printf

re: fclean all

PHONY: all clean fclean re
