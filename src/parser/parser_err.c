/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:55:12 by mluik             #+#    #+#             */
/*   Updated: 2022/10/11 21:36:28 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Scans the redirection linked list, generated
	by the parser, for potential errors. */
int	ft_parser_errorcheck_rd(t_minishell *shell)
{
	t_lexlist	*open_node;
	int			checker;

	checker = 0;
	open_node = shell->redir_list;
	while (open_node)
	{
		checker = ft_check_justspac_cmd(open_node);
		open_node = open_node->next;
	}
	if (checker == 1)
		return (1);
	else
		return (0);
}

/* Scans the commands' linked list, generated
	by the parser, for potential errors. */
int	ft_parser_errorcheck_cmd(t_minishell *shell)
{
	t_lexlist	*open_node;
	int			checker;

	checker = 0;
	open_node = shell->tokenlist;
	if (open_node != NULL && ft_singlecheck_cmd(open_node) == 1)
		return (1);
	while (open_node)
	{
		checker = ft_check_justspac_cmd(open_node);
		open_node = open_node->next;
	}
	if (checker == 1)
		return (1);
	else
		return (0);
}
