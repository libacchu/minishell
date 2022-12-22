/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanners03.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:11:41 by mluik             #+#    #+#             */
/*   Updated: 2022/10/12 19:12:59 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* itoa converter for the exit status code. */
char	*ft_exp_exit(t_minishell *minishell)
{
	char	*str;

	str = NULL;
	str = ft_itoa(minishell->exit_status);
	return (str);
}

/* Checks the first node in the tokenlist for ":" and "!" */
int	ft_singlecheck_cmd(t_lexlist *open_node)
{
	if (ft_strcmp(":", open_node->token) == 0 || \
		ft_strcmp("!", open_node->token) == 0)
		return (1);
	else
		return (0);
}

/* Error check for the cmd linked list. 
	Returns a checker value (1) if list 
	consist of only one node. */
int	ft_check_justspac_cmd(t_lexlist *tokenlist)
{
	int	i;
	int	checker;

	checker = 1;
	i = 0;
	if (tokenlist->token)
	{
		while (tokenlist->token[i] != '\0')
		{
			if (tokenlist->token[i] != ' ' \
				|| tokenlist->token[i] != '\t')
				checker = 0;
			i++;
		}
	}
	return (checker);
}

/* Simple scan for redirection separator. */
int	ft_scanfor_redir(int start, char *string)
{
	int	i;

	i = start;
	while (string[i] != '>' && string[i] != '<' && string[i] != '\0')
		i++;
	return (i - start);
}

/* Scans for a character c in string, starting at position i, 
	Count the occurance of c in sequence. 
	Stops counting until finds something else than char c.
 */
int	ft_scanforseveralchars(int start, char c, char *string)
{
	int	i;

	i = start;
	while (string[i] == c)
	{
		i++;
	}
	return (i - start);
}
