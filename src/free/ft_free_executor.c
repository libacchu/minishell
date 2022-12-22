/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_executor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:52:14 by mluik             #+#    #+#             */
/*   Updated: 2022/10/13 12:20:57 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**ft_free_substring(char **substring)
{
	int		i;
	char	**temp;

	i = 0;
	temp = NULL;
	while (substring[i])
	{
		free(substring[i]);
		i++;
	}
	free(substring);
	return (temp);
}

void	ft_free_cmd_nodes(t_command *cmd_nodes, const int amt_of_cmds)
{
	int	i;

	i = 0;
	while (i < amt_of_cmds)
	{
		cmd_nodes[i].index = 0;
		if (cmd_nodes[i].argv)
			ft_free_args(cmd_nodes[i].argv, cmd_nodes[i].nr_of_strings);
		cmd_nodes[i].nr_of_strings = 0;
		if (cmd_nodes[i].cmd_path)
			ft_free_string(cmd_nodes[i].cmd_path);
		i++;
	}
	if (cmd_nodes)
	{
		free(cmd_nodes);
	}
}

void	ft_free_pipes(int **arr, int num_pipes)
{
	int	i;

	i = 0;
	while (i < num_pipes)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_executor(t_executor *exec)
{
	if (exec->cmd_nodes)
		ft_free_cmd_nodes(exec->cmd_nodes, (*exec->pipe_count + 1));
	if (exec->env)
		ft_free_substring(exec->env);
	if (exec->fdpipe)
		ft_free_pipes(exec->fdpipe, *(exec->pipe_count));
	if (exec)
		free(exec);
}

void	ft_libft_del(void *del)
{
	int		i;
	char	**substring;

	substring = (char **)del;
	i = 0;
	while (substring[i])
	{
		free(substring[i]);
		substring[i] = NULL;
		i++;
	}
	free(substring);
	substring = NULL;
}
