/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:38:21 by mluik             #+#    #+#             */
/*   Updated: 2022/10/11 20:28:21 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*	Refreshes data only if error is caught during or
	right after the parsing phase. */
void	refresh_data_parsing(t_minishell *minishell)
{
	minishell->pipe_counter = 0;
	if (minishell->tokenlist)
		minishell->tokenlist = ft_free_lexlist(minishell->tokenlist);
	if (minishell->redir_list)
		minishell->redir_list = ft_free_lexlist(minishell->redir_list);
	minishell->tokenlist = NULL;
	minishell->redir_list = NULL;
}

/*	Sets main struct data to default (0) during
	program runtime so that structs can be used again */
void	refresh_data(t_minishell *minishell)
{
	if (minishell->executor)
		ft_free_executor(minishell->executor);
	minishell->pipe_counter = 0;
	if (minishell->tokenlist)
		minishell->tokenlist = ft_free_lexlist(minishell->tokenlist);
	if (minishell->redir_list)
		minishell->redir_list = ft_free_lexlist(minishell->redir_list);
	minishell->tokenlist = NULL;
	minishell->redir_list = NULL;
}
