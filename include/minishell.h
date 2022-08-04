/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:56:30 by mluik             #+#    #+#             */
/*   Updated: 2022/08/04 13:54:30 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <dirent.h>
# include <stddef.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

typedef struct s_envlist
{
	char				*variable;
	char				*content;
	struct s_envlist	*next;
}	t_envlist;

typedef struct s_minishell
{
	t_envlist	*env;
	char		**commands;
}	t_minishell;

/* Env functions */
t_envlist	*ft_env_new_node(char *variable, char *content);
void		ft_env_add_back(t_envlist **env, t_envlist *new);
t_envlist	*ft_env_last(t_envlist **env);
int			ft_env_len(t_envlist *env_struct);
void		ft_env_clear(t_envlist *env);
void		ft_free_null(char *variable, char *content);
int			ft_env_create(char **env, t_minishell *shell);
void		ft_env_del_one(t_envlist *env);
int			ft_env_print(t_envlist *env);


/* Builtin commands */
int			is_builtin_cmd(char *cmd);
int			ft_echo(int ac, char **av);
int			ft_pwd(void);
int			ft_env(t_list *env);
int			ft_cd(char *new_dir, t_minishell *shell);

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
