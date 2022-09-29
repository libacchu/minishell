# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 22:39:01 by libacchu          #+#    #+#              #
#    Updated: 2022/09/26 09:06:58 by libacchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -Og

SRC_DIR = ./src
SRC = $(SRC_DIR)/main.c \
		$(SRC_DIR)/parser/parser.c \
		$(SRC_DIR)/parser/ft_initialscan.c \
		$(SRC_DIR)/parser/add_data.c \
		$(SRC_DIR)/parser/parser_scan.c \
		$(SRC_DIR)/parser/redirect.c \
		$(SRC_DIR)/parser/scanners.c \
		$(SRC_DIR)/parser/scanners02.c \
		$(SRC_DIR)/parser/struct_cmd.c \
		$(SRC_DIR)/builtins/isbuiltin.c \
		$(SRC_DIR)/builtins/echo.c \
		$(SRC_DIR)/builtins/export.c \
		$(SRC_DIR)/builtins/pwd.c \
		$(SRC_DIR)/builtins/cd.c \
		$(SRC_DIR)/builtins/ft_exit.c \
		$(SRC_DIR)/builtins/unset.c \
		$(SRC_DIR)/env/env_test_m/ft_env_last.c \
		$(SRC_DIR)/env/env_real/ft_env_last.c \
		$(SRC_DIR)/env/env_test_m/ft_env_create.c \
		$(SRC_DIR)/env/env_real/ft_env_print.c \
		$(SRC_DIR)/env/env_real/ft_env_new_node.c \
		$(SRC_DIR)/env/env_real/ft_env_to_array.c \
		$(SRC_DIR)/env/env_real/ft_env_len.c \
		$(SRC_DIR)/env/env_real/ft_env_add_back.c \
		$(SRC_DIR)/env/env_real/ft_env_del_one.c \
		$(SRC_DIR)/env/env_real/ft_env_clear.c \
		$(SRC_DIR)/api/api.c \
		$(SRC_DIR)/executor/executor.c \
		$(SRC_DIR)/executor/get_cmd_path.c \
		$(SRC_DIR)/executor/pipes.c \
		$(SRC_DIR)/errors/errors01.c \
		$(SRC_DIR)/free/ft_free_executor.c \
		$(SRC_DIR)/free/ft_free_lexlist.c \
		$(SRC_DIR)/free/ft_free_minishell.c \
		$(SRC_DIR)/free/refresh.c \
		$(SRC_DIR)/testing/print_arr.c \
		$(SRC_DIR)/testing/print_t_list.c \

OBJS = $(SRC:%.c=%.o)
RM = rm -f

RL_MAC = -I $(HOME)/goinfre/.brew/opt/readline/include/ -L $(HOME)/goinfre/.brew/opt/readline/lib/ -lreadline

$(NAME): $(OBJS)
	make -C ./libft
	make bonus -C ./libft
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
