/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:52:14 by mluik             #+#    #+#             */
/*   Updated: 2022/08/11 10:36:54 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

void	ft_free_executor(t_executor *exec)
{
	if (exec->cmd_path)
		free(exec->cmd_path);
	if (exec->env)
		ft_free_substring(exec->env);
	if (exec->argv)
		ft_lstclear(&exec->argv, ft_libft_del);
	if (exec->infile)
		free(exec->infile);
	if (exec->outfile)
		free(exec->outfile);
	if (exec)
		free(exec);
}
