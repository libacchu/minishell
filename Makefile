# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 22:39:01 by libacchu          #+#    #+#              #
#    Updated: 2022/07/25 10:25:14 by libacchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = ./src
SRC = $(SRC_DIR)/main.c \
		$(SRC_DIR)/parser.c \
		$(SRC_DIR)/ft_free.c \
		$(SRC_DIR)/ft_initialscan.c \
		$(SRC_DIR)/errors01.c \
		$(SRC_DIR)/exector.c \
		$(SRC_DIR)/builtins/echo.c \

OBJS = $(SRC:%.c=%.o)
RM = rm -f

RL_MAC = -I $(HOME)/goinfre/.brew/opt/readline/include/ -L $(HOME)/goinfre/.brew/opt/readline/lib/ -lreadline

$(NAME): $(OBJS)
	make -C ./libft
	make -C ./libft/ft_printf
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
