/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:49:43 by mluik             #+#    #+#             */
/*   Updated: 2022/10/15 14:50:52 by mluik            ###   ########.fr       */
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
	minishell.exit_status = 0;
	minishell.executor = NULL;
	minishell.pipe_counter = 0;
	minishell.parent_pid = getpid();
	minishell.pipe_counter = 0;
	minishell.rd_chk = 0;
	g_shutdown_flag = 1;
	return (minishell);
}

/*	fdpipe commented out on 28 09 for during
	the work process on pipes. */
void	init_executor_struct(t_minishell *shell)
{
	shell->executor = ft_calloc(1, sizeof(t_executor));
	shell->executor->cmd_nodes = ft_calloc(shell->pipe_counter + 1, \
			sizeof(t_command));
	shell->executor->env = NULL;
	shell->executor->tmpin = dup(STDIN_FILENO);
	shell->executor->tmpout = dup(STDOUT_FILENO);
	shell->executor->pipe_count = &shell->pipe_counter;
	shell->executor->fdpipe = 0;
	shell->executor->shell = shell;
}

void	init_cmd_nodes_struct(t_command *cmd_nodes, int pipe_counter)
{
	int	i;

	i = 0;
	while (i < (pipe_counter + 1))
	{
		cmd_nodes[i].index = i;
		cmd_nodes[i].nr_of_strings = 0;
		cmd_nodes[i].cmd_path = NULL;
		cmd_nodes[i].infile = NULL;
		cmd_nodes[i].cat_redir_in = 0;
		cmd_nodes[i].outfile = NULL;
		cmd_nodes[i].cat_redir_out = 0;
		cmd_nodes[i].argv = NULL;
		cmd_nodes[i].fork_id = 0;
		cmd_nodes[i].fdin = 0;
		cmd_nodes[i].fdout = 0;
		i++;
	}
}
