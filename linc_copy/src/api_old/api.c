/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 08:22:02 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/06 12:41:05 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_api_handler(t_minishell *shell, t_executor *exec)
{
	exec->amt_of_cmds = ft_nbr_of_cmds(shell->tokenlist);
	exec->process = ft_calloc(sizeof(t_command *), exec->amt_of_cmds);
	convert_to_argv(shell, exec);
	return (0);
}

int	lex_length(t_lexlist *tokenlist)
{
	int			count;
	t_lexlist	*tmp;

	tmp = tokenlist;
	count = 0;
	while (tmp)
	{
		if (tmp->token == NULL)
			tmp = tmp->next;
		count++;
		if (tmp)
			tmp = tmp->next;
	}
	return (count);
}
