/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:56:30 by mluik             #+#    #+#             */
/*   Updated: 2022/07/31 19:23:00 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

typedef struct s_minishell
{
	t_list		*env;
	char		**commands;
}	t_minishell;

/* Builtin commands */
int			is_builtin_cmd(char *cmd);
int			ft_echo(int ac, char **av);
int			ft_pwd(void);

/* Program Handler*/
char		**ft_make_cmd(char *command_buf);
int			ft_prog_handler(t_minishell *shell, char *command_buf);
int			env_create_lst(t_minishell *shell, char **env);

/* Execution */
int			execute_cmd(t_minishell *shell, char **args);
int			exe_builtin(t_minishell *shell, char **args);
int			exe_lib(t_minishell *shell);
int			exe_builtin(t_minishell *shell, char **args);

/* Freeing Functions */
void		ft_free_substring(char **substring);

#endif
