/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   API.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 08:22:02 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/08 09:21:39 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int		lex_length(t_lexlist *tokenlist)
{
	int	count;
	t_lexlist *tmp;

	tmp = tokenlist;
	count = 0;
	while(tmp)
	{
		if(tmp->token == NULL)
			tmp = tmp->next;
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	convert_to_argv(t_minishell *shell)
{
	int			len;
	t_lexlist	*tmp;
	int			i;
	
	i = -1;
	tmp = shell->tokenlist;
	len = lex_length(shell->tokenlist);
	shell->executor->args = ft_calloc(sizeof(char), (len + 1));
	while (tmp)
	{
		if (tmp->token == NULL)
			tmp = tmp->next;
		shell->executor->args[++i] = ft_strdup(tmp->token);
		tmp = tmp->next;
	}
	return (0);
}
