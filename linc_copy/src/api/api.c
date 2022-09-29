/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:30:01 by mluik             #+#    #+#             */
/*   Updated: 2022/09/29 01:11:45 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_save_argv(t_lexlist *tokenlist, t_executor *exec_list, int max_cmd)
{
	int			i;
	int			j;
	t_lexlist	*tmp;

	tmp = tokenlist;
	i = 0;
	j = 0;
	while (i <= max_cmd)
	{
		j = exec_list->cmd_nodes[i].nr_of_strings;
		exec_list->cmd_nodes[i].argv = ft_calloc(j + 1, sizeof(char *));
		j = 0;
		while (i == tmp->field_by_pipe)
		{
			if (tmp->token_category == 0 || tmp->token_category == 1 \
				|| tmp->token_category == 2)
			{
				exec_list->cmd_nodes[i].argv[j] = tmp->token;
				// printf("%s\n", exec_list->cmd_nodes[i].argv[j]);
				j++;
			}
			if (tmp->next != NULL)
				tmp = tmp->next;
			else
				break ;
		}
		// print_arr(exec_list->cmd_nodes[i].argv);
		i++;
	}
}

/* Counts number of strings for each pipe
	and saves them as "nr_of_strings" in the
	t_command struct for every command separately.
	
	FOR LATER: Has error code return for syntax error. 
	CHECK before finishing! */
int	cnt_tkn_by_pipes(t_lexlist *tokens, t_executor *list)
{
	int			i;
	int			j;
	t_lexlist	*tmp;

	i = 0;
	j = 0;
	tmp = tokens;
	while (tmp)
	{
		while (i == tmp->field_by_pipe)
		{
			if (tmp->token_category == 0 || tmp->token_category == 1 \
				|| tmp->token_category == 2)
				j++;
			if (tmp->next != NULL)
				tmp = tmp->next;
			else
				break ;
		}
		list->cmd_nodes[i].nr_of_strings = j;
		if (list->cmd_nodes[i].nr_of_strings == 0)
		{
			printf("Syntax error near unexpected token '|'\n");
			return (1);
		}
		// printf("Number of strings for cmd %d : %d\n", i, list->cmd_nodes[i].nr_of_strings);
		j = 0;
		i++;
		if (tmp->next == NULL)
			break ;
	}
	return (0);
}

/* Brdige between parser and executor. 
	Converts the parsed data stored in the tokenlist 
	struct to argv.
	NOT FINISHED YET: 
	In addition, the functions scans the redirections
	list and stores redirection data for each command. */
void	ft_api_handler(t_minishell *shell)
{
	init_cmd_nodes_struct(shell->executor->cmd_nodes, shell->pipe_counter);
	cnt_tkn_by_pipes(shell->tokenlist, shell->executor);
	ft_save_argv(shell->tokenlist, shell->executor, shell->pipe_counter);
}
