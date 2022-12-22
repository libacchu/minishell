/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:56:30 by mluik             #+#    #+#             */
/*   Updated: 2022/10/15 14:35:11 by libacchu         ###   ########.fr       */
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
# include <signal.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "./gl_var.h"

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

/* Struct for each individual command to be executed. */
typedef struct s_command {
	int		index;
	int		nr_of_strings;
	char	*cmd_path;
	char	*infile;
	int		cat_redir_in;
	char	*outfile;
	int		cat_redir_out;
	char	**argv;
	int		fork_id;
	int		fdin;
	int		fdout;
}	t_command;

/* Struct for executor. Holds nodes for each command. */
typedef struct s_minishell	t_minishell;
typedef struct s_executor {
	t_command	*cmd_nodes;
	char		**env;
	int			tmpin;
	int			tmpout;
	int			*pipe_count;
	int			**fdpipe;
	t_minishell	*shell;
}	t_executor;

/* Struct capable of storing env data as linked list. */
typedef struct s_envlist {
	char					*variable;
	char					*content;
	struct s_envlist		*next;
}	t_envlist;

/* Struct capable of holding all data for cmd's
	and redirections, incl. pipe counts.*/
typedef struct s_lexlist {
	int						tok_cat;
	int						field_by_pipe;
	char					*token;
	struct s_lexlist		*next;
}	t_lexlist;

/* Main struct for the Minishell program structure. */
typedef struct s_minishell {
	t_lexlist				*tokenlist;
	t_lexlist				*redir_list;
	t_envlist				*envlist;
	t_executor				*executor;
	int						pipe_counter;
	int						parent_pid;
	int						exit_status;
	int						rd_chk;
}	t_minishell;

/* env list functions in folder "/env" */
int				ft_checkcontent(char *str);
t_envlist		*ft_recreate_env(char **env, t_envlist *list);
t_lexlist		*ft_findlast_lexlist(t_lexlist *lex);
t_envlist		*ft_findlast_envlist(t_envlist *envlist);
t_envlist		*ft_create_env_node(char *var, char *content);
void			ft_free_null(char *variable, char *content);
void			ft_save_env_ls(char *var, char *content,
					t_minishell *minishell);
char			*ft_get_variable(char *str);
char			*ft_get_content(char *str);
int				ft_env_create(char **env, t_minishell *shell);
void			ft_env_add_back(t_envlist **env, t_envlist *new);
int				ft_env_print(t_envlist *env);
char			**ft_env_to_array(t_envlist *env);
int				ft_env_len(t_envlist *env_struct);
void			ft_env_del_one(t_envlist *env);
t_envlist		*ft_env_clear(t_envlist *env);

/* Scanner functions in /parser/scanners.c AND
	/parser/scanners02.c AND scanner03.c*/
int				ft_unex_tok(int pos, char *string);
char			*ft_exp_exit(t_minishell *minishell);
int				ft_singlecheck_rd(t_minishell *shell);
int				ft_check_justspac_cmd(t_lexlist *tokenlist);
int				ft_singlecheck_cmd(t_lexlist *open_node);
int				ft_scanfor_redir(int start, char *string);
char			*ft_find_two_quotes(char *token);
int				ft_scanforvarsep(int start, char *string);
int				ft_scanandskip(int start, char c, char s, char *string);
int				ft_checkforescape(int start, char *string);
int				ft_scanforchar_extra(int start, char c, char *string);
int				ft_scanforseveralchars(int start, char c, char *string);
int				ft_scanforchar(int start, char c, char *string);
int				ft_scanforlength(int start, int tok_cat, char *string);
int				ft_ispresent(int start, char c, char s, char *string);
int				ft_dealw_scanlen(int start, char *string, int tokenlength);
int				ft_scanforlen_rd(int start, char *string);

/* Lexer & Parser Functions 
	in /parser/parser_err.c*/
int				ft_parser_errorcheck_rd(t_minishell *shell);
int				ft_parser_errorcheck_cmd(t_minishell *shell);

/* Lexer & Parser Functions 
	in /parser/add_data.c*/
int				ft_save_separator(char *c, int start, char *string,
					t_minishell *minishell);
t_lexlist		*ft_findlasttoken(t_lexlist *lexlist);
t_lexlist		*ft_createtoken(int category, char *newtoken, int pipecount);
void			save_redirect_token(int category_new_token, char *newtoken,
					t_minishell *minishell);
void			save_token(int category_new_token, char *newtoken,
					t_minishell *minishell);

/* Lexer & Parser Functions 
	in /parser/ft_initialscan.c*/
int				ft_findcategory(int start, char *string);
int				ft_scanforsep_save(int start, char *string,
					t_minishell *minishell);
int				ft_skipspaces(int start, char *string);
int				ft_initialize_scan(char *string, t_minishell *minishell);
int				ft_save_separator(char *c, int start, char *string,
					t_minishell *minishell);

/* Functions in file errors01.c & errors02.c */
int				ft_edgecase_p(char *string);
int				ft_checkifeligible(char *string);
int				up_exit(int exnum, t_minishell *shell);

/* Lexer & Parser Functions 
	in /parser/parser_scan.c & parser_scan02.c */
t_lexlist		*ft_replace_home(t_lexlist *tok, t_minishell *minishell);
t_lexlist		*ft_dealwith_repl(int start, t_lexlist *tok, int length, \
	t_minishell *minishell);
char			*ft_rem_subs_tok(int start, int len, char *string);
char			*ft_add_subs_tok(char *tobeadded, int start, int len,
					char *string);
char			*ft_findvariable_inlist(char *variable, t_minishell *minishell);
t_lexlist		*ft_switch_var_env(t_lexlist *tok, t_minishell *minishell);
int				ft_refine_scan(t_minishell *minishell);

/* Lexer & Parser Functions 
	in /parser/redirect.c*/
int				ft_check_rd_cat(int start, int tok_cat, char *string);
char			*ft_cleantoken(char *redirect_token, t_minishell *minishell);
int				ft_save_redirect(int start, int tok_cat,
					char *string, t_minishell *minishell);

/* Lexer & Parser Functions 
	in /parser/struct_cmd.c*/
t_minishell		initialize_minishell_struct(void);
void			init_executor_struct(t_minishell *shell);
void			init_cmd_nodes_struct(t_command *cmd_nodes, int nbr_of_pipes);

/* Lexer & Parser Functions 
	in /parser/parser.c*/
int				parse(char *command_buf, t_minishell *minishell);

/* Functions in file signal_handler.c */
void			heredoc_sig_single(void);
void			heredoc_sig_hand(int sig);
void			heredoc_sig_func(void);
void			handle_ctrl_c_proc(int sig);
void			handle_ctrl_c(int sig);
void			ft_handle_signals(t_minishell *shell);
void			ft_disable_signals(void);

/* Builtin commands in folder "/builtins" */
int				is_builtin_cmd(char **command);
int				exe_builtin(t_minishell *shell, char **args);
int				ft_echo(int ac, char **av);
int				env_namecheck(char *name);
void			ft_findandreplace_env(t_envlist *env, char *var, \
					char *content);
int				ft_varlen(char *var);
int				ft_checkexisting_env(t_envlist *env, char *var);
int				ft_export(t_envlist *env, char **cmd_arr, t_minishell *shell);
int				ft_pwd(void);
int				ft_cd(int ac, char *new_dir, t_minishell *shell);
int				ft_unset(int ac, char *name, t_envlist *env);

/* void		ft_free_substring(char **substring);  */
void			exit_w_error(char *message);

/* error/exit_message */
void			print_command_not_found(char *arg);
void			print_permission_denied(char *arg);
void			print_no_such_file_directory(char *arg);
void			print_syntax_error(char *arg);
void			print_is_directory(char *arg);
int				up_exit_too(int exnum, t_minishell *shell, int code);

/* Api functions in /api/api.c */
void			ft_save_argv(int i, t_lexlist *tokenlist, \
				t_executor *exec_list, int max_cmd);
int				cnt_tkn_by_pipes(int i, t_lexlist *tokens, t_executor *list, \
				t_minishell *shell);
int				ft_api_handler(t_minishell *shell);

/* Executor commands in executor/executor.c */
int				execution_handler(t_minishell *shell);
void			exe_lib(t_minishell *shell, t_executor *exec, int i);
int				redirect_output(t_executor *exec);
int				one_command(t_minishell *shell);
int				one_redirections(t_minishell *shell, int i);

/* Executor commands in executor/executor_multi.c */
int				multi_commands(t_minishell *shell, t_executor *exec);
void			execute_command(t_minishell *shell, int i);
int				wait_on_child(t_executor *exec, int max);

/* Redirections commands in executor/redirections.c */
int				check_redirect_file_out(t_minishell *shell, int cmd_nbr);
int				check_redirect_file_in(t_minishell *shell, int cmd_nbr);
int				redirection_in(t_executor *exec, int i);
int				redirection_out(t_executor *exec, int i);
void			dup_in_out(t_executor *exec, int cmd_nbr);

/* Heredoc commands in executor/heredoc.c & heredoc_one.c*/
void			ft_close_pipe(int *doc_pipe);
int				heredoc_magic(char **string, char **tmp, char **buff, \
					char *delimiter);
int				heredoc_input_single(char *delimiter, t_minishell *shell);
int				heredoc_input(char *delimiter, t_minishell *shell);

/* Free */
char			**ft_free_substring(char **substring);
void			ft_free_string(char *str);
void			ft_free_args(char **substring, int count);
void			ft_free_executor(t_executor *exec);
t_lexlist		*ft_free_lexlist(t_lexlist *lex);
int				ft_free_minishell(t_minishell *shell);
void			ft_libft_del(void *del);

/* Exit */
void			ft_exit(char *mess, t_minishell *minishell, int exnum);
int				ft_exit_cmd(int ac, char **argv, t_minishell *shell);

/*********************	NEW	********************/
int				convert_to_argv(t_minishell *shell, t_executor *exec);
char			*get_cmd_path(t_envlist *env, char **cmd);
int				dup_std_in_out(t_executor *executor);
int				lex_length(t_lexlist *tokenlist);

// int				convert_to_argv(t_minishell *shell);
int				ft_nbr_of_cmds(t_lexlist *tokenlist);
int				check_redirect_file(t_minishell *shell);

/* executor/pipes.c */
int				ft_create_pipes(t_executor *exec);
int				ft_close_pipes_write_end(t_executor *exec);
int				ft_close_all_pipes(t_executor *exec, int max);
int				one_cmd_close(t_minishell *shell);

/* refresh.c */
void			refresh_data_parsing(t_minishell *minishell);
void			refresh_data(t_minishell *minishell);

#endif
