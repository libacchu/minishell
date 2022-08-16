/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:41:49 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/16 08:50:11 by libacchu         ###   ########.fr       */
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

	executor->fdin = dup(executor->tmpin);
	return (0);
}

/* check for input redirection */
int	check_input_redirect(t_executor *executor)
{
	// if (executor->infile)
	// 	executor->fdin = open(executor->infile, O_RDONLY);
	// else
	executor->fdin = dup(executor->tmpin);
	close(executor->fdin);
	return (0);
}

int	redirect_output(t_executor *exec)
{
	// int fdpipe[2];
	if (exec->argv->next == NULL)
	{
		// ft_printf("last\n");
		// if (exec->outfile)
		// 	exec->fdout = open(exec->outfile, O_WRONLY);
		// else
		// dup2(exec->fdout, exec->tmpout);
		exec->fdout = dup(exec->tmpout);
	}
	else
	{
		// ft_printf("pipe\n");
		pipe(exec->fdpipe);
		exec->fdout = exec->fdpipe[1];
		exec->fdin = exec->fdpipe[0];
	}
	dup2(exec->fdout, STDOUT_FILENO);
	close(exec->fdout);
	return (0);
}

int	exe_cmd(t_minishell *shell)
{
	shell->executor->id = fork();
	if (shell->executor->id == 0)
	{
		exe_lib(shell);
	}
	return (0);
}

/* calls all the necessary functions for execution */
int	execution_handler(t_minishell *shell)
{
	t_list *tmp;
	
	shell->executor = ft_calloc(sizeof(t_executor), 1);
	shell->amt_cmds = nbr_of_cmds(shell->tokenlist);
	convert_to_argv(shell);
	dup_std_in_out(shell->executor);
	tmp = shell->executor->argv;
	while (shell->executor->argv)
	{
		check_input_redirect(shell->executor);
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

		if (shell->executor->id != 0)
			waitpid(shell->executor->id, NULL, 0);
		shell->executor->argv = shell->executor->argv->next;
	}
	
	shell->executor->argv = tmp;
	ft_free_executor(shell->executor);
	shell->tokenlist = NULL;
	return (0);
}