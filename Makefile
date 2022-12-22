# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 22:39:01 by libacchu          #+#    #+#              #
#    Updated: 2022/10/15 15:47:10 by mluik            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Wall -Werror -Wextra -lreadline

SRC_DIR = ./src
SRC = $(SRC_DIR)/main.c \
		$(SRC_DIR)/parser/parser.c \
		$(SRC_DIR)/parser/ft_initialscan.c \
		$(SRC_DIR)/parser/add_data.c \
		$(SRC_DIR)/parser/parser_scan.c \
		$(SRC_DIR)/parser/parser_scan02.c \
		$(SRC_DIR)/parser/parser_err.c \
		$(SRC_DIR)/parser/redirect.c \
		$(SRC_DIR)/parser/scanners.c \
		$(SRC_DIR)/parser/scanners02.c \
		$(SRC_DIR)/parser/scanners03.c \
		$(SRC_DIR)/parser/struct_cmd.c \
		$(SRC_DIR)/signals/signal_handler.c \
		$(SRC_DIR)/signals/signal_handler_02.c \
		$(SRC_DIR)/builtins/isbuiltin.c \
		$(SRC_DIR)/builtins/echo.c \
		$(SRC_DIR)/builtins/export.c \
		$(SRC_DIR)/builtins/export_utils.c \
		$(SRC_DIR)/builtins/pwd.c \
		$(SRC_DIR)/builtins/cd.c \
		$(SRC_DIR)/builtins/ft_exit.c \
		$(SRC_DIR)/builtins/unset.c \
		$(SRC_DIR)/env/ft_env_last.c \
		$(SRC_DIR)/env/ft_env_recreate.c \
		$(SRC_DIR)/env/ft_env_create.c \
		$(SRC_DIR)/env/ft_env_print.c \
		$(SRC_DIR)/env/ft_env_to_array.c \
		$(SRC_DIR)/env/ft_env_len.c \
		$(SRC_DIR)/env/ft_env_add_back.c \
		$(SRC_DIR)/env/ft_env_del_one.c \
		$(SRC_DIR)/env/ft_env_clear.c \
		$(SRC_DIR)/api/api.c \
		$(SRC_DIR)/executor/executor.c \
		$(SRC_DIR)/executor/executor_multi.c \
		$(SRC_DIR)/executor/get_cmd_path.c \
		$(SRC_DIR)/executor/pipes.c \
		$(SRC_DIR)/executor/redirections.c \
		$(SRC_DIR)/executor/heredoc.c \
		$(SRC_DIR)/executor/heredoc_one.c \
		$(SRC_DIR)/errors/errors01.c \
		$(SRC_DIR)/errors/errors02.c \
		$(SRC_DIR)/errors/exit_message.c \
		$(SRC_DIR)/free/ft_free_executor.c \
		$(SRC_DIR)/free/ft_free_exec_02.c \
		$(SRC_DIR)/free/ft_free_lexlist.c \
		$(SRC_DIR)/free/ft_free_minishell.c \
		$(SRC_DIR)/free/refresh.c \

OBJS = $(SRC:%.c=%.o)
RM = rm -f

$(NAME): $(OBJS)
	make -C ./libft
	make bonus -C ./libft
	make -C ./libft/ft_printf
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

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
