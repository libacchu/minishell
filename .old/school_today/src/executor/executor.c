/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:41:49 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/20 13:19:26 by libacchu         ###   ########.fr       */
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
	// if (executor->infile)
	// 	executor->fdin = open(executor->infile, O_RDONLY);
	// else
		executor->fdin = dup(executor->tmpin);
	return (0);
}

int	redirect_output(t_executor *exec)
{
	
	if (exec->argv->next == NULL)
	{
		// ft_printf("outfile = %s\n", exec->outfile);
		// if (exec->outfile)
		// {
		// 	exec->fdout = open(exec->outfile, O_TRUNC | O_RDWR);
		// 	if (exec->fdout == -1)
		// 		exec->fdout = open(exec->outfile, O_TRUNC | O_CREAT);
		// }
		// else
			dup2(exec->fdout, exec->tmpout);
	}
	else
	{
		// ft_printf("pipe\n");
		// int fdpipe[2];
		pipe(exec->fdpipe);
		exec->fdout = exec->fdpipe[1];
		exec->fdin = exec->fdpipe[0];
	}
	
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
	shell->executor = ft_calloc(sizeof(t_executor), 1);
	shell->amt_cmds = nbr_of_cmds(shell->tokenlist);
	convert_to_argv(shell);
	check_redirect_file(shell);
	dup_std_in_out(shell->executor);
	check_input_redirect(shell->executor);
	// tmp = shell->executor->argv;
	// shell->executor->fdpipe = ft_calloc(sizeof(int), 2);
	while (shell->executor->argv)
	{
		// print_arr(shell->executor->argv->content);
		dup2(shell->executor->fdin, STDIN_FILENO);
		close(shell->executor->fdin);
		// usleep(100);
		redirect_output(shell->executor);
		dup2(shell->executor->fdout, STDOUT_FILENO);
		close(shell->executor->fdout);
		if (is_builtin_cmd(shell->executor->argv->content))
		{
			exe_builtin(shell, shell->executor->argv->content);
		}
		else
		{
			exe_cmd(shell);
		}
		// sleep(1);
		// close(shell->executor->fdin);
		// close(shell->executor->fdout);
		dup2(shell->executor->fdin, shell->executor->fdout);
		close(shell->executor->fdin);
		waitpid(shell->executor->id, NULL, 0);
		if (shell->executor->argv)
			shell->executor->argv = shell->executor->argv->next;
	}
	dup2(shell->executor->tmpin, STDIN_FILENO);
	dup2(shell->executor->tmpout, STDOUT_FILENO);
	close(shell->executor->tmpin);
	close(shell->executor->tmpout);
	// if (shell->executor->id != 0)
	// {
		// wait(NULL);
		// shell->executor->argv = tmp;
	// }
	ft_free_executor(shell->executor);
	// free(shell->executor);
	shell->tokenlist = NULL;
	shell->redir_list = NULL;
	return (0);
}