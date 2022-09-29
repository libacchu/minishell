/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:38:21 by mluik             #+#    #+#             */
/*   Updated: 2022/09/23 17:20:48 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*	Sets main struct data to default (0) during
	program runtime so that structs can be used again */
void	refresh_data(t_minishell *minishell)
{
	/* int i;

	i = 0;
	while (i < minishell->pipe_counter + 1)
	{
		minishell->executor->cmd_nodes[i].argv = NULL;
		i++;
	} */
	if (minishell->executor)
		ft_free_executor(minishell->executor);
	minishell->pipe_counter = 0;
	if (minishell->tokenlist)
		ft_free_lexlist(minishell->tokenlist);
	if (minishell->redir_list)
		ft_free_lexlist(minishell->redir_list);
	minishell->tokenlist = NULL;
	minishell->redir_list = NULL;

}
