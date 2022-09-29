/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_executor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:52:14 by mluik             #+#    #+#             */
/*   Updated: 2022/09/26 12:27:24 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_string(char *str)
{
	// str = NULL;
	free(str);
}

void	ft_free_args(char **substring, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		substring[i] = NULL;
		free(substring[i]);
		i++;
	}
	substring = NULL;
	free(substring);
}

void	ft_free_substring(char **substring)
{
	int	i;

	i = 0;
	while (substring[i])
	{
		substring[i] = NULL;
		free(substring[i]);
		i++;
	}
	substring = NULL;
	free(substring);
}

void	ft_free_cmd_nodes(t_command *cmd_nodes, const int amt_of_cmds)
{
	int	i;

	i = 0;
	while (i < amt_of_cmds)
	{
		cmd_nodes[i].index = 0;
		cmd_nodes[i].fdin = 0;
		cmd_nodes[i].fdout = 0;
		if (cmd_nodes[i].argv)
			ft_free_args(cmd_nodes[i].argv, cmd_nodes[i].nr_of_strings);
		cmd_nodes[i].nr_of_strings = 0;
		if (cmd_nodes[i].cmd_path)
			ft_free_string(cmd_nodes[i].cmd_path);
		if (cmd_nodes[i].infile)
			ft_free_substring(cmd_nodes[i].infile);
		if (cmd_nodes[i].outfile)
			ft_free_substring(cmd_nodes[i].outfile);
		i++;
	}
	if (cmd_nodes)
		free(cmd_nodes);
}

void	ft_free_executor(t_executor *exec)
{
	if (exec->cmd_nodes)
		ft_free_cmd_nodes(exec->cmd_nodes, (*exec->pipe_count + 1));
	if (exec->env)
		ft_free_substring(exec->env);
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
