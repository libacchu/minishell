/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:55:54 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/07 13:08:49 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	one_command(t_minishell *shell);
int	exe_cmd(t_minishell *shell);
int	multi_commands(t_minishell *shell, t_executor *exec);

/* calls all the necessary functions for execution */
int	execution_handler(t_minishell *shell)
{
	shell->executor = ft_calloc(sizeof(t_executor), 1);
	ft_api_handler(shell, shell->executor);
	if (shell->executor->amt_of_cmds == 1)
		one_command(shell);
	/* else
		multi_commands(shell, shell->executor); */
	
	// free_stuff
	//ft_free_executor(shell->executor);
	/* shell->executor = NULL;
	shell->tokenlist = NULL;
	shell->redir_list = NULL; */
	return (0);
}

int	one_command(t_minishell *shell)
{
	if (is_builtin_cmd(shell->executor->process->cmd->command))
		exe_builtin(shell, shell->executor->process->cmd->command);
	else
	{
		/* shell->executor->id = fork(); */
		exe_cmd(shell);
	}
	return (0);
}

int	multi_commands(t_minishell *shell, t_executor *exec)
{
	/*
		- create pipes
		- save_STDin and STDout
		- check for redirections
		- (^) if yes: open fd
		- fork()
		- check builtins or not
	*/
	int i;

	ft_pipes_handler(exec);
	i = 0;
	while (i < exec->amt_of_cmds)
	{
		// ft_redirections();
		// STDOUT_FILENO = dup(exec->process[i].fdout);
		// dup2(STDIN_FILENO, exec->process[i].fdin);
		// // close(exec->process[i].fdout);
		// dup2(STDOUT_FILENO, exec->process[i].fdout);
		// close(exec->process[i].fdin);
		
		// close(exec->process[i].fdout);
		
		shell->executor->id = fork();
		if (shell->executor->id == 0)
		{
			dup2(exec->process[i].fdin, STDIN_FILENO);
			dup2(exec->process[i].fdout, STDOUT_FILENO);
			printf("index = %d\n cmd = %s\n\n", exec->process[i].index, \
				exec->process[i].cmd->command[0]);
			if (is_builtin_cmd(shell->executor->process->cmd->command))
				exe_builtin(shell, shell->executor->process->cmd->command);
			else
			{
				exe_lib(shell, shell->executor);
			}
		}
		usleep(1000);
		if (shell->executor->id != 0)
		{
			waitpid(shell->executor->id, NULL, 0);
		}
		dup2(exec->tmpin, STDIN_FILENO);
		dup2(exec->tmpout, STDOUT_FILENO);
		close(exec->tmpin);
		close(exec->tmpout);
		// close(exec->process[i].fdin);
		// close(exec->process[i].fdout);
		// close(exec->process[i].fdin);
		i++;
	}
	return (0);
}

int	exe_cmd(t_minishell *shell)
{
	if (shell->executor->id == 0)
		exe_lib(shell, shell->executor);
	if (shell->executor->id != 0)
		waitpid(shell->executor->id, NULL, 0);
	return (0);
}

void	exe_lib(t_minishell *shell, t_executor *exec)
{
	char	*cmd_path;

	shell->executor->env = ft_env_to_array(shell->envlist);
	// print_arr(shell->executor->env);
	cmd_path = get_cmd_path(shell->envlist, exec->process->cmd->command);
	// printf("\n path: %s \n", cmd_path);
	if (!cmd_path)
		ft_printf("minishell: %s: No such file or directory\n", \
				exec->process->cmd[0]);
	exec->process->cmd->command[0] = ft_strdup(cmd_path);
	if (execve(cmd_path, exec->process->cmd->command, shell->executor->env) == -1)
		exit(1);
}
