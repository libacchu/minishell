/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:55:54 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/29 02:56:43 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	one_command(t_minishell *shell);
int	exe_cmd(t_minishell *shell);
int	multi_commands(t_minishell *shell, t_executor *exec);

/* Calls all the necessary functions for execution.
	To work, it checks for amount of commands
	and executes chain of functions accordingly. */
int	execution_handler(t_minishell *shell)
{
	if ((shell->pipe_counter + 1) == 1)
		one_command(shell);
	else
		multi_commands(shell, shell->executor);
	return (0);
}

int	one_command(t_minishell *shell)
{
	if (is_builtin_cmd(shell->executor->cmd_nodes->argv))
		exe_builtin(shell, shell->executor->cmd_nodes->argv);
	else
	{
		shell->executor->cmd_nodes[0].fork_id = fork();
		exe_cmd(shell);
	}
	return (0);
}
int	exe_cmd(t_minishell *shell)
{
	if (shell->executor->cmd_nodes[0].fork_id == 0)
		exe_lib(shell, shell->executor, 0);
	if (shell->executor->cmd_nodes[0].fork_id != 0)
		waitpid(shell->executor->cmd_nodes[0].fork_id, NULL, 0);
	return (0);
}

/* Executes library function. 
	1. Converts env lists to array. 
	2. Scans for command path in the PATH variable. 
	3. Executes command.
	4. Exits (child) process with the ft_exit function
	!!! - ft_exit not added as of 23.09. */
void	exe_lib(t_minishell *shell, t_executor *exec, int i)
{
	char	*cmd_path;
	/* char	*array[2] = {"ls", NULL}; */

	shell->executor->env = ft_env_to_array(shell->envlist);
	// print_arr(shell->executor->env);
	cmd_path = get_cmd_path(shell->envlist, exec->cmd_nodes[i].argv);
	// printf("\n path: %s \n", cmd_path);
	if (!cmd_path)
		ft_printf("minishell: %s: No such file or directory\n", \
				exec->cmd_nodes[i].argv[0]);
	// exec->cmd_nodes[i].argv[0] = cmd_path;
	if (execve(cmd_path, exec->cmd_nodes[i].argv, shell->executor->env) == -1)
	{
		printf("failed\n");
		exit(1);
	}
}
/* // 	- create pipes
// 		- save_STDin and STDout
// 		- check for redirections (created after forking ft)
// 		- (^) if yes: open fd (created after forking ft)
// 		- fork()
// 		- check builtins or not */
int	multi_commands(t_minishell *shell, t_executor *exec)
{
	int	i;
	int	j;

/*---------------------------------------------------------------------------------------------------*/
	i = 0;
	exec->fdpipe = ft_calloc(sizeof(int *), shell->pipe_counter);
	if (!exec->fdpipe)
		return (1);
	while (i < shell->pipe_counter)
	{
		exec->fdpipe[i] = ft_calloc(sizeof(int), 2);
		if (pipe(exec->fdpipe[i]) < 0)
		{
			printf("pipe failed!!!\n");
			exit(1);
		}
		i++;
	}
/*---------------------------------------------------------------------------------------------------*/
	i = 0;
	while (i < shell->pipe_counter + 1)
	{
		exec->cmd_nodes[i].fork_id = fork();
		if (exec->cmd_nodes[i].fork_id == 0)
		{
/*---------------------------------------------------------------------------------------------------*/
			/* REDIRECT IN */
			if (exec->cmd_nodes[i].infile)
			{
				/* if CAT_REDIR_L */
				exec->fdin = open(*exec->cmd_nodes[i].infile, O_RDONLY);
				/* else if CAT_REDIR_LL */
					// HEREDOC
			}
			else
			{
				if (i == 0)
					exec->fdin = STDIN_FILENO;
				else if (i == shell->pipe_counter)
					exec->fdin = exec->fdpipe[i - 1][0];
			}
/*---------------------------------------------------------------------------------------------------*/
			/* REDIRECT OUT */
	 		if (exec->cmd_nodes[i].outfile)
			{
				/* if CAT_REDIR_R */
				exec->fdout = open(*exec->cmd_nodes[i].outfile, \
					O_WRONLY | O_CREAT | O_TRUNC);
				/* else if CAT_REDIR_RR */
				exec->fdout = open(*exec->cmd_nodes[i].outfile, \
					O_WRONLY | O_CREAT | O_APPEND);
			}
			else
			{
				if (i == shell->pipe_counter)
					exec->fdout = STDOUT_FILENO;
				else
					exec->fdout = exec->fdpipe[i][1];
			}
/*---------------------------------------------------------------------------------------------------*/
			dup2(exec->fdin, STDIN_FILENO);
			dup2(exec->fdout, STDOUT_FILENO);
/*---------------------------------------------------------------------------------------------------*/
			j = 0;
			while (j < shell->pipe_counter)
			{
				close(exec->fdpipe[j][1]);
				j++;
			}
/*---------------------------------------------------------------------------------------------------*/
			if (is_builtin_cmd(shell->executor->cmd_nodes[i].argv))
			{
				exe_builtin(shell, shell->executor->cmd_nodes[i].argv);
				exit(1);
			}
			// HAVE TO ADD: Safe way to come out of process. 
			else
			{
				exe_lib(shell, shell->executor, i);
			}
		}
/*---------------------------------------------------------------------------------------------------*/
		i++;
	}
/*---------------------------------------------------------------------------------------------------*/
	i = 0;
	while (i < shell->pipe_counter)
	{
		close(exec->fdpipe[i][1]);
		close(exec->fdpipe[i][0]);
		i++;
	}
/*---------------------------------------------------------------------------------------------------*/
	i = 0;
	while (i < shell->pipe_counter + 1)
	{
		waitpid(exec->cmd_nodes[i].fork_id, NULL, 0);
		i++;
	}
	return (0);
}

	// if (i == 0)
	// {
	// 	dup2(exec->fdout, STDOUT_FILENO);
	// }
	// else if (i == shell->pipe_counter)
	// {
	// 	dup2(exec->fdin, STDIN_FILENO);
	// }
	// else
	// {
	// 	dup2(exec->fdin, STDIN_FILENO);
	// 	dup2(exec->fdout, STDOUT_FILENO);
	// }
	// if (i == 0)
	// {
	// 	dup2(exec->fdpipe[i][1], STDOUT_FILENO);
	// }
	// else if (i == shell->pipe_counter)
	// {
	// 	dup2(exec->fdpipe[i - 1][0], STDIN_FILENO);
	// }
	// else
	// {
	// 	dup2(exec->fdpipe[i - 1][0], STDIN_FILENO);
	// 	dup2(exec->fdpipe[i][1], STDOUT_FILENO);
	// }
