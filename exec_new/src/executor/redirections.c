/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 09:18:07 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/23 22:33:30 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"



int	check_for_valid_redirect(const char *redirect, int category)
{
	if (category == CAT_REDIR_L)
	{
		if (access(redirect, F_OK | R_OK | X_OK) != NULL)
			return (1);
	}
	if (category == CAT_REDIR_R || category == CAT_REDIR_RR)
	{
		if (access(redirect, F_OK | W_OK | X_OK) != NULL)
			return (1)
	}
	return (0)
}

int	check_redirect_file(t_minishell *shell)
{
	t_lexlist	*tmp;

	tmp = NULL;
	if (shell->redir_list)
		tmp = shell->redir_list;
	while (tmp)
	{
		if (tmp->token_category == CAT_REDIR_L)
			shell->executor->infile = ft_strdup(tmp->token);
		if (tmp->token_category == CAT_REDIR_R)
			shell->executor->outfile = ft_strdup(tmp->token);
		tmp = tmp->next;
	}
	return (0);
}
