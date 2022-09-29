/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:49:43 by mluik             #+#    #+#             */
/*   Updated: 2022/09/28 17:33:52 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Initializes the minishell data struct to NULL. */
t_minishell	initialize_minishell_struct(void)
{
	t_minishell	minishell;

	minishell.tokenlist = NULL;
	minishell.redir_list = NULL;
	minishell.envlist = NULL;
	minishell.pipe_counter = 0;
	minishell.exit_status = NULL;
	minishell.executor = NULL;
	// minishell.tmp_stdin = dup(STDIN_FILENO);
	// minishell.tmp_stdout = dup(STDOUT_FILENO);
	return (minishell);
}

void	init_executor_struct(t_minishell *shell)
{
	shell->executor = ft_calloc(1, sizeof(t_executor));
	shell->executor->cmd_nodes = ft_calloc(shell->pipe_counter + 1, \
			sizeof(t_command));
	shell->executor->env = NULL;
	// shell->executor->tmpin = dup(STDIN_FILENO);
	// shell->executor->tmpout = dup(STDOUT_FILENO);
	shell->executor->tmpin = 0;
	shell->executor->tmpout = 0;
	// shell->executor->fdpipe = NULL;
	// shell->executor->fork_id = 0;
	shell->executor->pipe_count = &shell->pipe_counter;
}

void	init_cmd_nodes_struct(t_command *cmd_nodes, int pipe_counter)
{
	int	i;

	i = 0;
	while (i < (pipe_counter + 1))
	{
		cmd_nodes[i].index = i;
		cmd_nodes[i].cmd_path = NULL;
		// cmd_nodes[i].fdin = dup(STDIN_FILENO);
		// cmd_nodes[i].fdout = dup(STDOUT_FILENO);
		cmd_nodes[i].fdin = 0;
		cmd_nodes[i].fdout = 0;
		cmd_nodes[i].infile = NULL;
		cmd_nodes[i].outfile = NULL;
		cmd_nodes[i].argv = NULL;
		cmd_nodes[i].nr_of_strings = 0;
		i++;
	}
}
