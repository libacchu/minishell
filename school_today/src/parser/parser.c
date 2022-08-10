/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:15:19 by mluik             #+#    #+#             */
/*   Updated: 2022/08/10 15:46:30 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* 	A checker for the lexer: prints out lexed values as table. */
void	ft_printlexlist_checker(t_minishell *minishell)
{
	t_lexlist	*nodeprint;
	t_lexlist	*print_redir;

	nodeprint = minishell->tokenlist;
	print_redir = minishell->redir_list;
	while (nodeprint)
	{
		ft_printf("\n");
		ft_printf("token:\t %s \t \t category: %i \t pipe_index: %i\n",
			nodeprint->token, nodeprint->token_category,
			nodeprint->field_by_pipe);
		nodeprint = nodeprint->next;
	}
	// minishell->tokenlist = NULL;
	while (print_redir)
	{
		ft_printf("\n");
		ft_printf("redirect token:\t %s \t \t category:\t %i pipe_index: %i \n",
			print_redir->token, print_redir->token_category,
			print_redir->field_by_pipe);
		print_redir = print_redir->next;
	}
	ft_printf("\n");
	ft_printf("pipe_counter =\t%d\n", minishell->pipe_counter);
	ft_printf("exit_status =\t%s\n", minishell->exit_status);
	minishell->redir_list = NULL;
}

/*  Calls the analytical lexer and
	parser functions, to be used on the input
	string; creates the final command table.
	 */
int	parse(char *command_buf, t_minishell *minishell)
{
	ft_initialize_scan(command_buf, minishell);
	ft_refine_scan(minishell);
	// ft_printlexlist_checker(minishell);
	return (0);
}
