/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:41:49 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/11 12:06:53 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* for testing purposes */
void print_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		ft_printf("%s \n", arr[i]);
}

/* duplicates the Standard in/output to restore after execution */
int dup_std_in_out(t_executor *executor)
{
	executor->tmpin = dup(STDIN_FILENO);
	executor->tmpout = dup(STDOUT_FILENO);
	return (0);
}

/* check for input redirection */
int	check_input_redirect(t_executor *executor)
{
	if (executor->infile)
		executor->fdin = open(executor->infile, O_RDONLY);
	else
		executor->fdin = dup(executor->tmpin);
	return (0);
}

int	exe_cmd(t_minishell *shell)
{
	int	id;

	id = fork();
	if (id == 0)
	{
		exe_lib(shell);
	}
	else
		waitpid(id, NULL, 0);
	return (0);
}

int	redirect_output(t_executor *exec)
{
	if (exec->argv->next == NULL)
	{
		if (exec->outfile)
			exec->fdout = open(exec->outfile, O_WRONLY);
		else
			exec->fdout = dup(exec->tmpout);
	}
	else
	{
		pipe(exec->fdpipe);
		exec->fdout = exec->fdpipe[1];
		exec->fdin = exec->fdpipe[0];
	}
	dup2(exec->fdout, STDOUT_FILENO);
	close(exec->fdout);
	return (0);
}

/* calls all the necessary functions for execution */
int	execution_handler(t_minishell *shell)
{
	shell->executor = ft_calloc(sizeof(t_executor), 1);
	shell->amt_cmds = nbr_of_cmds(shell->tokenlist);
	convert_to_argv(shell);
	dup_std_in_out(shell->executor);
	check_input_redirect(shell->executor);
	t_list *tmp = shell->executor->argv;
	while (shell->executor->argv)
	{
		redirect_output(shell->executor);
		if (is_builtin_cmd(shell->executor->argv->content))
		{
			exe_builtin(shell, shell->executor->argv->content);
		}
		else
		{
			exe_cmd(shell);
		}
		dup2(shell->executor->tmpin, STDIN_FILENO);
		dup2(shell->executor->tmpout, STDOUT_FILENO);
		close(shell->executor->tmpin);
		close(shell->executor->tmpout);
		shell->executor->argv = shell->executor->argv->next;
	}
	shell->executor->argv = tmp;
	ft_free_executor(shell->executor);
	shell->tokenlist = NULL;
	return (0);
}
