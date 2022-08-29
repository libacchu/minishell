/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:55:54 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/23 23:48:13 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int one_command(t_minishell *shell);
int	exe_cmd(t_minishell *shell);

/* calls all the necessary functions for execution */
int	execution_handler(t_minishell *shell)
{
	// ft_printf("----- 1 -----\n");
	shell->executor = ft_calloc(sizeof(t_executor), 1);
	// ft_printf("----- 2 -----\n");
	ft_api_handler(shell, shell->executor);
	// ft_printf("----- 3 -----\n");
	if (shell->executor->amt_of_cmds == 1)
		one_command(shell);
	// else
	// 	multi_commands(shell);
	// free_stuff
	ft_free_executor(shell->executor);
	shell->tokenlist = NULL;
	shell->redir_list = NULL;
	return (0);
}

int one_command(t_minishell *shell)
{
	if (is_builtin_cmd(shell->executor->process->cmd))
		exe_builtin(shell, shell->executor->process->cmd);
	else
		exe_cmd(shell);
	return (0);
}

// int multi_commands(t_minishell *shell, t_executor *exec)
// {
// 	/*
// 		- create pipes
// 		- save_STDin and STDout
// 		- check for redirections
// 		- (^) if yes: open fd
// 		- fork()
// 		- check builtins or not
// 	*/
// 	ft_pipes_handler(exec);
// 	dup_std_in_out(exec);
// 	ft_redirections();
	
// }

int	exe_cmd(t_minishell *shell)
{
	shell->executor->id = fork();
	if (shell->executor->id == 0)
		exe_lib(shell, shell->executor);
	else
		waitpid(shell->executor->id, NULL, 0);
	return (0);
}

int	exe_lib(t_minishell *shell, t_executor *exec)
{
	char	*cmd_path;
	
	shell->executor->env = ft_env_to_array(shell->envlist);
	cmd_path = get_cmd_path(shell->envlist, exec->process->cmd);
	if (!cmd_path)
		ft_printf("minishell: %s: No such file or directory\n", exec->process->cmd[0]);
	execve(cmd_path, exec->process->cmd, shell->executor->env);
	return (0);
}