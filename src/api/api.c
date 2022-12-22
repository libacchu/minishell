/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:30:01 by mluik             #+#    #+#             */
/*   Updated: 2022/10/13 20:06:23 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_save_argv(int i, t_lexlist *tokenlist, \
		t_executor *exec_list, int max_cmd)
{
	int			j;
	t_lexlist	*tmp;

	tmp = tokenlist;
	j = 0;
	while (i <= max_cmd && tmp)
	{
		j = exec_list->cmd_nodes[i].nr_of_strings;
		exec_list->cmd_nodes[i].argv = ft_calloc(j + 1, sizeof(char *));
		j = 0;
		while (i == tmp->field_by_pipe)
		{
			if (tmp->tok_cat == 0 || tmp->tok_cat == 1 \
				|| tmp->tok_cat == 2)
			{
				exec_list->cmd_nodes[i].argv[j] = ft_strdup(tmp->token);
				j++;
			}
			if (tmp->next != NULL)
				tmp = tmp->next;
			else
				break ;
		}
		i++;
	}
}

/* Counts number of strings for each pipe
	and saves them as "nr_of_strings" in the
	t_command struct for every command separately. */
int	cnt_tkn_by_pipes(int i, t_lexlist *tokens, t_executor *list, \
	t_minishell *shell)
{
	int			j;
	t_lexlist	*tmp;

	j = 0;
	tmp = tokens;
	while (tmp)
	{
		while (i == tmp->field_by_pipe)
		{
			if (tmp->tok_cat == 0 || tmp->tok_cat == 1 || tmp->tok_cat == 2)
				j++;
			if (tmp->next != NULL)
				tmp = tmp->next;
			else
				break ;
		}
		list->cmd_nodes[i].nr_of_strings = j;
		if (list->cmd_nodes[i].nr_of_strings == 0 && shell->rd_chk == 0)
			return (up_exit_too(2, shell, 1));
		j = 0;
		i++;
		if (tmp->next == NULL)
			break ;
	}
	return (0);
}

/* Bridge between parser and executor. 
	Converts the parsed data stored in the tokenlist 
	struct to argv. */
int	ft_api_handler(t_minishell *shell)
{
	int	i;

	i = 0;
	init_cmd_nodes_struct(shell->executor->cmd_nodes, shell->pipe_counter);
	i = cnt_tkn_by_pipes(i, shell->tokenlist, shell->executor, shell);
	ft_save_argv(i, shell->tokenlist, shell->executor, shell->pipe_counter);
	return (i);
}
