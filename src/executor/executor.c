/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:55:54 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/15 14:29:16 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Calls all the necessary functions for execution.
	To work, it checks for amount of commands
	and executes chain of functions accordingly. */
int	execution_handler(t_minishell *shell)
{
	if ((shell->pipe_counter + 1) == 1)
	{
		if (one_command(shell))
			return (EXIT_FAILURE);
	}
	else
	{
		ft_handle_signals(shell);
		if (multi_commands(shell, shell->executor))
			return (EXIT_FAILURE);
	}
	return (0);
}

int	one_redirections(t_minishell *shell, int i)
{
	if (check_redirect_file_in(shell, i))
		return (EXIT_FAILURE);
	if (redirection_in(shell->executor, i))
		return (EXIT_FAILURE);
	if (check_redirect_file_out(shell, i))
		return (EXIT_FAILURE);
	if (redirection_out(shell->executor, i) != 0)
		return (EXIT_FAILURE);
	dup_in_out(shell->executor, i);
	return (0);
}

int	one_command(t_minishell *shell)
{
	char	**tmp;

	tmp = shell->executor->cmd_nodes->argv;
	if (one_redirections(shell, 0))
		return (EXIT_FAILURE);
	if (shell->executor->cmd_nodes->nr_of_strings == 0)
		tmp = NULL;
	if (is_builtin_cmd(tmp))
		exe_builtin(shell, tmp);
	else
	{
		shell->executor->cmd_nodes[0].fork_id = fork();
		ft_handle_signals(shell);
		if (shell->executor->cmd_nodes[0].fork_id == 0)
			exe_lib(shell, shell->executor, 0);
		if (shell->executor->cmd_nodes[0].fork_id != 0)
		{
			waitpid(shell->executor->cmd_nodes[0].fork_id, \
				&shell->exit_status, 0);
			shell->exit_status = shell->exit_status / 256;
		}
	}
	one_cmd_close(shell);
	return (0);
}

/* Executes library function. 
	1. Converts env lists to array. 
	2. Scans for command path in the PATH variable. 
	3. Executes command.
	4. Exits (child) process with the ft_exit function
	!!! - ft_exit not added as of 23.09. */
int	ft_file_or_directory(char *cmd)
{
	struct stat	cmd_stat;

	stat(cmd, &cmd_stat);
	return (S_ISREG(cmd_stat.st_mode));
}

void	exe_lib(t_minishell *shell, t_executor *exec, int i)
{
	char	*cmd_path;

	shell->executor->env = ft_env_to_array(shell->envlist);
	if ((!ft_strncmp(exec->cmd_nodes[i].argv[0], ".", 1) || \
		!ft_strncmp(exec->cmd_nodes[i].argv[0], "/", 1)) && \
		access(exec->cmd_nodes[i].argv[0], X_OK) == 0)
	{
		cmd_path = exec->cmd_nodes[i].argv[0];
	}
	else
		cmd_path = get_cmd_path(shell->envlist, exec->cmd_nodes[i].argv);
	if (!cmd_path)
	{
		print_command_not_found(exec->cmd_nodes[i].argv[0]);
		ft_exit(NULL, shell, 127);
	}
	else if (ft_file_or_directory(cmd_path) != 1)
	{
		print_is_directory(cmd_path);
		ft_exit(NULL, shell, 126);
	}
	if (execve(cmd_path, exec->cmd_nodes[i].argv, shell->executor->env) == -1)
		ft_exit(NULL, shell, 126);
}
