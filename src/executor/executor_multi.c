/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_multi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:55:54 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/15 12:59:17 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
** creates all the pipes need for executions
** creates processes for each command
** handles redirections
*/

int	assign_redirect(t_minishell *shell)
{
	int	i;

	i = 0;
	while (i < shell->pipe_counter + 1)
	{
		if (check_redirect_file_in(shell, i))
			return (EXIT_FAILURE);
		if (redirection_in(shell->executor, i))
			return (EXIT_FAILURE);
		if (check_redirect_file_out(shell, i))
			return (EXIT_FAILURE);
		if (redirection_out(shell->executor, i) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (0);
}

int	multi_commands(t_minishell *shell, t_executor *exec)
{
	int	i;

	if (ft_create_pipes(exec) == 1)
		return (EXIT_FAILURE);
	if (assign_redirect(shell))
		return (EXIT_FAILURE);
	i = 0;
	while (i < shell->pipe_counter + 1)
	{
		exec->cmd_nodes[i].fork_id = fork();
		if (exec->cmd_nodes[i].fork_id == 0)
		{
			dup_in_out(shell->executor, i);
			ft_close_all_pipes(exec, shell->pipe_counter);
			execute_command(shell, i);
		}
		i++;
	}
	ft_close_all_pipes(exec, i - 1);
	wait_on_child(exec, i);
	return (0);
}

/* checks if the command is a built-in or non-builtin
	then executes the command */
void	execute_command(t_minishell *shell, int i)
{
	if (is_builtin_cmd(shell->executor->cmd_nodes[i].argv))
	{
		exe_builtin(shell, shell->executor->cmd_nodes[i].argv);
		ft_exit(NULL, shell, 0);
	}
	else
		exe_lib(shell, shell->executor, i);
}

/* uses waitpid() to wait for all child processes to finish execution */
int	wait_on_child(t_executor *exec, int max)
{
	int	i;

	i = 0;
	while (i < max + 1)
	{
		waitpid(exec->cmd_nodes[i].fork_id, &exec->shell->exit_status, 0);
		exec->shell->exit_status = exec->shell->exit_status / 256;
		if (exec->shell->exit_status == 130)
			return (10);
		i++;
	}
	return (0);
}

void	dup_in_out(t_executor *exec, int cmd_nbr)
{
	dup2(exec->cmd_nodes[cmd_nbr].fdin, STDIN_FILENO);
	dup2(exec->cmd_nodes[cmd_nbr].fdout, STDOUT_FILENO);
}
