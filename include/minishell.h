/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:56:30 by mluik             #+#    #+#             */
/*   Updated: 2022/07/29 13:31:00 by libacchu         ###   ########.fr       */
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

/* typedef struct s_env {
	//whatever it gets from the parent environment has to be saved here
}	t_env; */

typedef struct s_parselist {
	int						index;
	int						prio_category;
	int						token_category;
	char					*cmd_str;
	struct s_parselist		*next; // original->next; original->next->next;
}	t_parselist;

typedef struct s_finalcmd {
	char			**argv;
	int				redirect_type;
}	t_finalcmd;

typedef struct s_cmd_data
{
	int				data;
}	t_cmd_data;

typedef struct s_minishell {
	struct s_parselist		*substrings;
/* 	s_finalcmd		*finalcmdtable; // == argv */
}	t_minishell;

void		exit_w_error(char *message);
int			ft_scanforfield(char c, char *string);
int			ft_initialscan(char *command_buf, t_minishell *minishell);
void		ft_free_substring(char **substring);
int			parse(char *command_buf, t_minishell *minishell);

/* Builtin commands */
int			ft_echo(int ac, char **av);

#endif
