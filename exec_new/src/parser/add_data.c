/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:01:33 by mluik             #+#    #+#             */
/*   Updated: 2022/08/05 21:21:51 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Saves the space separator indication in a separate token as '\n' */
int	ft_save_separator(char *c, int start, char *string,
			t_minishell *minishell)
{
	int		tokenlength;
	int		token_category;

	token_category = ft_findcategory(start, string);
	tokenlength = ft_scanforlength(start, token_category, string);
	save_token(token_category, c, minishell);
	return (tokenlength);
}

/* 	Finds and returns the last token in the token list. */
t_lexlist	*ft_findlasttoken(t_lexlist *lexlist)
{
	t_lexlist	*last;

	last = NULL;
	while (lexlist)
	{
		last = lexlist;
		lexlist = lexlist->next;
	}
	return (last);
}

/* 	Createsa new token for the lexlist struct. */
t_lexlist	*ft_createtoken(int category, char *newtoken, int pipecount)
{
	t_lexlist	*createdtoken;

	createdtoken = ft_calloc(1, sizeof(t_lexlist));
	createdtoken->next = NULL;
	createdtoken->token_category = category;
	createdtoken->field_by_pipe = pipecount;
	if ((category == CAT_SPAC) || (category == CAT_PIP))
		createdtoken->token = NULL;
	else
		createdtoken->token = newtoken;
	return (createdtoken);
}

/* 	Saves the redirection token in its designated
	list, which is connected to the minishell struct.
	minishell->redir_list = ft_calloc(1, sizeof(t_lexlist));  */
void	save_redirect_token(int category_new_token, char *newtoken,
			t_minishell *minishell)
{
	t_lexlist	*last;

	if (!minishell->redir_list)
	{
		minishell->redir_list = ft_createtoken(category_new_token,
				newtoken, minishell->pipe_counter);
		return ;
	}
	last = ft_findlasttoken(minishell->redir_list);
	last->next = ft_createtoken(category_new_token, newtoken,
			minishell->pipe_counter);
}

/* 	Saves the token in the lexlist, which is connected 
	to the minishell struct.
	minishell->tokenlist = ft_calloc(1, sizeof(t_lexlist));  */
void	save_token(int category_new_token, char *newtoken,
			t_minishell *minishell)
{
	t_lexlist	*last;

	if (!minishell->tokenlist)
	{
		minishell->tokenlist = ft_createtoken(category_new_token,
				newtoken, minishell->pipe_counter);
		return ;
	}
	last = ft_findlasttoken(minishell->tokenlist);
	last->next = ft_createtoken(category_new_token, newtoken,
			minishell->pipe_counter);
}
