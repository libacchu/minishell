/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_executor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:52:14 by mluik             #+#    #+#             */
/*   Updated: 2022/08/29 13:56:08 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_substring(char **substring)
{
	int	i;

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

void	ft_libft_del(void *del)
{
	int	i;
	char **substring;
	
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

void	ft_free_string(char *str)
{
	free(str);
	str = NULL;
}

void	ft_free_commands(t_command *process, const int amt_of_cmds)
{
	int i;
	
	i = 0;
	while (i < amt_of_cmds)
	{
		if (process[i].cmd)
			ft_free_substring(process[i].cmd);
		if (process[i].cmd_path)
			ft_free_string(process[i].cmd_path);
		// if (process[i].infile)
		// 	ft_free_substring(process[i].infile);
		// ft_printf("----- D -----\n");
		// if (process[i].outfile)
		// 	ft_free_substring(process[i].outfile);
		// ft_printf("----- E -----\n");
		i++;
	}
}

// void	ft_free_fdpipes(int **fdpipe, const int amt_of_cmds)
// {
// 	int	i;

// 	i = 0;
// 	while (i < amt_of_cmds - 1)
// 	{
		
// 	}	
// }

void	ft_free_executor(t_executor *exec)
{
	if (exec->process)
		ft_free_commands(exec->process, exec->amt_of_cmds);
	if (exec->env)
		ft_free_substring(exec->env);
	if (exec)
		free(exec);
}
