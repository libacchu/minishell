/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 09:28:32 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/15 14:21:50 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// fd[0] = read end
// fd[1] = write end

int	ft_create_pipes(t_executor *exec)
{
	int	i;

	i = 0;
	exec->fdpipe = ft_calloc(sizeof(int *), *(exec->pipe_count));
	if (!exec->fdpipe)
		return (EXIT_FAILURE);
	while (i < *(exec->pipe_count))
	{
		exec->fdpipe[i] = ft_calloc(sizeof(int), 2);
		if (pipe(exec->fdpipe[i]) < 0)
		{
			perror("Pipes failed ");
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (0);
}

int	ft_close_all_pipes(t_executor *exec, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		close(exec->fdpipe[i][1]);
		close(exec->fdpipe[i][0]);
		i++;
	}
	return (0);
}

int	one_cmd_close(t_minishell *shell)
{
	close(shell->executor->cmd_nodes[0].fdin);
	close(shell->executor->cmd_nodes[0].fdout);
	dup2(shell->executor->tmpin, STDIN_FILENO);
	dup2(shell->executor->tmpout, STDOUT_FILENO);
	close(shell->executor->tmpin);
	close(shell->executor->tmpout);
	return (0);
}
