/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_scan02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:50:18 by mluik             #+#    #+#             */
/*   Updated: 2022/10/12 19:15:31 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Switches a '~' string with a string
	to the home directore from the env list. */
t_lexlist	*ft_replace_home(t_lexlist *tok, t_minishell *minishell)
{
	char	*newtoken;

	newtoken = NULL;
	if (ft_strcmp(tok->token, "~") == 0)
	{
		newtoken = ft_findvariable_inlist("HOME", minishell);
		if (newtoken != NULL)
			tok->token = ft_add_subs_tok(newtoken, 1, 1, tok->token);
		if (newtoken != NULL)
			free(newtoken);
	}
	return (tok);
}

/* Handles the switching of variable names to the 
	content from the env list. */
t_lexlist	*ft_dealwith_repl(int start, t_lexlist *tok, int length, \
	t_minishell *minishell)
{
	char	*variable;
	char	*newtoken;

	start += ft_scanforchar_extra(start, '$', tok->token);
	length = ft_scanforvarsep(++start, tok->token);
	variable = ft_substr(tok->token, start, length);
	if (ft_strcmp(variable, "?") == 0)
		newtoken = ft_exp_exit(minishell);
	else
		newtoken = ft_findvariable_inlist(variable, minishell);
	if (newtoken == NULL && tok->tok_cat == CAT_DEFAULT)
		tok->tok_cat = CAT_SPAC;
	if (newtoken == NULL && tok->tok_cat == CAT_DOUBLEQ)
		tok->token = ft_rem_subs_tok(start, length, tok->token);
	if (newtoken != NULL)
		tok->token = ft_add_subs_tok(newtoken, start, length, \
			tok->token);
	if (newtoken != NULL)
		free(newtoken);
	free (variable);
	return (tok);
}
