/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:56:30 by mluik             #+#    #+#             */
/*   Updated: 2022/09/28 22:58:04 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <dirent.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

/* Categories for the tokens */
# define CAT_DEFAULT			0
# define CAT_DOUBLEQ			1
# define CAT_SINGLEQ			2
# define CAT_SPAC				3
# define CAT_PIP				4
# define CAT_REDIR_L			6 /* infile */
# define CAT_REDIR_LL			7 /* heredoc */
# define CAT_REDIR_R			8 /* outfile - rewrite file */
# define CAT_REDIR_RR			9 /* outfile - append file */

/*
	OLD EXECUTOR STRUCT
typedef struct s_executor {
	char	*cmd_path;
	char	**env;
	t_list	*argv;
	int		tmpin;
	int		tmpout;
	int		fdin;
	int		fdout;
	char	*infile;
	char	*outfile;
	int		fdpipe[2];
	int		id;
	int		background;
}	t_executor;
*/

typedef struct s_command {
	int		index;
	int		fdin;
	int		fdout;
	int		nr_of_strings;
	char	*cmd_path;
	char	**infile;
	char	**outfile;
	char	**argv;
	int		fork_id;
}	t_command;

typedef struct s_executor {
	t_command	*cmd_nodes;
	char		**env;
	int			tmpin;
	int			tmpout;
	int			fdin;
	int			fdout;
	int			*pipe_count;
	int			**fdpipe;
}	t_executor;

typedef struct s_envlist {
	char					*variable;
	char					*content;
	struct s_envlist		*next;
}	t_envlist;

/* Struct capable of holding all data for cmd's
	and redirections, incl. pipe counts.*/
typedef struct s_lexlist {
	int						token_category;
	int						field_by_pipe;
	char					*token;
	struct s_lexlist		*next;
}	t_lexlist;

typedef struct s_minishell {
	t_lexlist				*tokenlist;
	t_lexlist				*redir_list;
	t_envlist				*envlist;
	t_executor				*executor;
	int						pipe_counter;
	char					*exit_status;
}	t_minishell;

/* env list functions */
t_envlist		*ft_findlast_envlist(t_envlist *envlist);
void			ft_free_null(char *variable, char *content);
t_envlist		*ft_create_env_node(char *var, char *content);
void			ft_save_env_ls(char *var, char *content,
					t_minishell *minishell);
char			*ft_get_variable(char *str);
char			*ft_get_content(char *str);
int				ft_env_create(char **env, t_minishell *shell);
void			ft_env_add_back(t_envlist **env, t_envlist *new);

/* Scanner functions */
int				ft_scanforvarsep(int start, char *string);
int				ft_scanandskip(int start, char c, char s, char *string);
int				ft_checkforescape(int start, char *string);
int				ft_scanforchar_extra(int start, char c, char *string);
int				ft_scanforseveralchars(int start, char c, char *string);
int				ft_scanforchar(int start, char c, char *string);
int				ft_scanforlength(int start, int token_category, char *string);
int				ft_ispresent(int start, char c, char s, char *string);
int				ft_scanforlen_rd(int start, char *string);

/* Lexer & Parser Functions */
int				ft_save_separator(char *c, int start, char *string,
					t_minishell *minishell);
t_lexlist		*ft_findlasttoken(t_lexlist *lexlist);
t_lexlist		*ft_createtoken(int category, char *newtoken, int pipecount);
char			*ft_rem_subs_tok(int start, int len, char *string);
char			*ft_add_subs_tok(char *tobeadded, int start, int len,
					char *string);
char			*ft_findvariable_inlist(char *variable, t_minishell *minishell);
char			*ft_switch_var_env(char *token, t_minishell *minishell);
int				ft_save_separator(char *c, int start, char *string,
					t_minishell *minishell);
void			save_redirect_token(int category_new_token, char *newtoken,
					t_minishell *minishell);
void			save_token(int category_new_token, char *newtoken,
					t_minishell *minishell);
char			*ft_cleantoken(char *redirect_token, t_minishell *minishell);
int				ft_check_rd_cat(int start, int token_category, char *string);
int				ft_save_redirect(int start, int token_category,
					char *string, t_minishell *minishell);
int				ft_findcategory(int start, char *string);
int				ft_skipspaces(int start, char *string);
int				ft_scanforsep_save(int start, char *string,
					t_minishell *minishell);
void			ft_checkifeligible(char *string);
int				ft_refine_scan(t_minishell *minishell);
int				ft_initialize_scan(char *string, t_minishell *minishell);
int				parse(char *command_buf, t_minishell *minishell);

/* Builtin commands */
int				is_builtin_cmd(char **command);
int				exe_builtin(t_minishell *shell, char **args);
int				ft_echo(int ac, char **av);
int				ft_export(t_envlist *env, char **cmd_arr);
int				ft_pwd(void);
int				ft_cd(char *new_dir, t_minishell *shell);
int				ft_unset(char *name, t_envlist *env);

/* env commands */
int				ft_env_print(t_envlist *env);
t_envlist		*ft_env_new_node(char *variable, char *content);
char			**ft_env_to_array(t_envlist *env);
int				ft_env_len(t_envlist *env_struct);
void			ft_env_add_back(t_envlist **env, t_envlist *new);
t_envlist		*ft_env_last(t_envlist *env);
void			ft_env_del_one(t_envlist *env);
void			ft_env_clear(t_envlist *env);

/* void		ft_free_substring(char **substring);  */
void			exit_w_error(char *message);

/* API */
int				lex_length(t_lexlist *tokenlist);
// int				convert_to_argv(t_minishell *shell);
int				ft_nbr_of_cmds(t_lexlist *tokenlist);
int				check_redirect_file(t_minishell *shell);

/* Executor commands */
int				execution_handler(t_minishell *shell);
// int				exe_lib(t_minishell *shell);
int				redirect_output(t_executor *exec);

/* Free */
void			ft_free_substring(char **substring);
void			ft_free_executor(t_executor *exec);
void			ft_free_lexlist(t_lexlist *lex);
int				ft_free_minishell(t_minishell *shell);
void			ft_libft_del(void *del);

/* Exit */
void			ft_exit(char *mess, t_minishell *minishell);

/* Testing */
void			print_arr(char **arr);
int				print_t_list(t_list *list);

/*********************	NEW	********************/
int				convert_to_argv(t_minishell *shell, t_executor *exec);
void			exe_lib(t_minishell *shell, t_executor *exec, int i);
char			*get_cmd_path(t_envlist *env, char **cmd);
int				dup_std_in_out(t_executor *executor);

/* FILENAME.c */
int				ft_pipes_handler(t_executor *exec);

/* refresh.c */
void			refresh_data(t_minishell *minishell);

/* api.c */
int				cnt_tkn_by_pipes(t_lexlist *tokens, t_executor *list);
void			ft_api_handler(t_minishell *shell);

/* struct_cmd.c */
t_minishell		initialize_minishell_struct(void);
void			init_executor_struct(t_minishell *shell);
void			init_cmd_nodes_struct(t_command *cmd_nodes, int nbr_of_pipes);

#endif
