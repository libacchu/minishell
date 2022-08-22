/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:55:54 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/22 14:50:32 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int one_command(t_minishell *shell);
int	exe_cmd(t_minishell *shell);

/* calls all the necessary functions for execution */
int	execution_handler(t_minishell *shell)
{
	shell->executor = ft_calloc(sizeof(t_executor), 1);
	ft_api_handler(shell, shell->executor);
	if (shell->executor->amt_of_cmds == 1)
		one_command(shell->executor);
	else
		multi_commands(shell->executor);
}

int one_command(t_minishell *shell)
{
	if (is_builtin_cmd(shell->executor->process[0].cmd))
		exe_builtin(shell, shell->executor->process[0].cmd);
	else
		exe_cmd(shell);
}

int multi_commands()
{
	/*
		- create pipes
		- save_STDin and STDout
		- check for redirections
		- (^) if yes: open fd
		- fork()
		- check builtins or not
	*/
	ft_create_pipes(t_executor *exec);
}

int	exe_cmd(t_minishell *shell)
{
	shell->executor->id = fork();
	if (shell->executor->id == 0)
		exe_lib(shell);
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