/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 09:28:32 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/30 15:34:32 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_create_pipes(t_executor *exec);
int	assign_pipes(t_executor *exec);
int dup_std_in_out(t_executor *executor);

int ft_pipes_handler(t_executor *exec)
{
	dup_std_in_out(exec);
	ft_create_pipes(exec);
	assign_pipes(exec);
	return (0);
}

int	assign_pipes(t_executor *exec)
{
	int	i;

	i = 0;
	while (i < exec->amt_of_cmds)
	{
		if (i == 0)
		{
			// ft_printf("before = %d\n", exec->process[i].fdin);
			// ft_printf("before = %d\n", exec->process[i].fdout);
			// dup2(exec->process[0].fdin, STDIN_FILENO);
			// dup2(exec->process[0].fdout, exec->fdpipe[0][1]);
			ft_printf("--- 1 ---\n");
			exec->process[i].fdin = STDIN_FILENO;
			exec->process[i].fdout = exec->fdpipe[0][1];
			close(exec->fdpipe[0][1]);
			ft_printf("--- 2 ---\n");
			// exec->process[0].fdin = STDIN_FILENO;
			// exec->process[0].fdout = exec->fdpipe[0][1];
			// ft_printf("----after = %d----\n", exec->process[i].fdin);
			// ft_printf("after = %d\n", exec->process[i].fdout);
			// ft_printf("---- 1 ----\n");
		}
		else if (i == (exec->amt_of_cmds - 1))
		{
			// ft_printf("before = %d\n", exec->process[i].fdin);
			// ft_printf("before = %d\n", exec->process[i].fdout);
			ft_printf("--- 3 ---\n");
			exec->process[i].fdin = exec->fdpipe[i - 1][0];
			close(exec->fdpipe[i - 1][0]);
			exec->process[i].fdout = STDOUT_FILENO;
			ft_printf("--- 4 ---\n");
			// dup2(exec->process[i].fdin, exec->fdpipe[i - 1][0]);
			// dup2(exec->process[i].fdout, STDOUT_FILENO);
			// ft_printf("after = %d\n", exec->process[i].fdin);
			// ft_printf("after = %d\n", exec->process[i].fdout);
			// ft_printf("---- 3 ----\n");
		}
		else
		{
			// ft_printf("before = %d\n", exec->process[i].fdin);
			// ft_printf("before = %d\n", exec->process[i].fdout);
			
			exec->process[i].fdin = exec->fdpipe[i - 1][0];
			exec->process[i].fdout = exec->fdpipe[i][1];
			close(exec->fdpipe[i][1]);
			close(exec->fdpipe[i - 1][0]);
			// dup2(, );

			/*ft_printf("after = %d\n", exec->process[i].fdin);
			ft_printf("after = %d\n", exec->process[i].fdout);
			ft_printf("---- 2 ----\n");*/
			
			// exec->process[i].fdin = exec->fdpipe[i - 1][0];
			// exec->process[i].fdout = exec->fdpipe[i][1];
		}
		// ft_printf("fdin[%d] = %d\n", i, exec->fdpipe[i][0]);
		// ft_printf("fdout[%d] = %d\n", i, exec->fdpipe[i][1]);
		i++;
	}
	// exec->fdpipe[i] = ft_calloc(sizeof(int), 2);
	// pipe(exec->fdpipe[i]);
	// exec->process[i].fdin = exec->fdpipe[i - 1][0];
	// exec->process[i].fdout = STDOUT_FILENO;
	return (0);
}

int	ft_create_pipes(t_executor *exec)
{
	int	i;

	exec->fdpipe = ft_calloc(sizeof(int *), (exec->amt_of_cmds - 1));
	if (!exec->fdpipe)
		return (1);
	i = 0;
	while (i < exec->amt_of_cmds - 1)
	{
		exec->fdpipe[i] = ft_calloc(sizeof(int), 2);
		pipe(exec->fdpipe[i]);
		i++;
	}
	return (0);
}

/* duplicates the Standard in/output to restore after execution */
int dup_std_in_out(t_executor *executor)
{
	executor->tmpin = dup(STDIN_FILENO);
	executor->tmpout = dup(STDOUT_FILENO);
	return (0);
}