/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 09:28:32 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/23 13:32:17 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int ft_pipes_handler(t_executor *exec)
{
	ft_create_pipes(exec);
	assign_pipes(exec);
}

int	assign_pipes(t_executor *exec)
{
	int	i;

	i = 0;
	while (i < exec->amt_of_cmds)
	{
		exec->fdpipe[i] = ft_calloc(sizeof(int), 2);
		pipe(exec->fdpipe[i]);
		exec->process[i].fdin = exec->fdpipe[i][0];
		exec->process[i].fdout = exec->fdpipe[i][0];
	}
}

int	ft_create_pipes(t_executor *exec)
{
	exec->fdpipe = ft_calloc(sizeof(int *), (exec->amt_of_cmds - 1));
	if (!exec->fdpipe)
		return (1);
	else
		return (0);
}

/* duplicates the Standard in/output to restore after execution */
int dup_std_in_out(t_executor *executor)
{
	executor->tmpin = dup(STDIN_FILENO);
	executor->tmpout = dup(STDOUT_FILENO);
	return (0);
}