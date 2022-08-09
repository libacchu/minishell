/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 19:19:40 by mluik             #+#    #+#             */
/*   Updated: 2022/08/05 21:11:52 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_cleantoken(char *token, t_minishell *minishell)
{
	int		start;
	int		length;
	char	*variable;
	char	*newtoken;

	start = 0;
	while (token[start] != '\0')
	{
		if (ft_ispresent(start, '$', 39, token) == 1)
		{
			start += ft_scanandskip(start, 36, 39, token);
			length = ft_scanforvarsep(++start, token);
			variable = ft_substr(token, start, length);
			newtoken = ft_findvariable_inlist(variable, minishell);
			if (newtoken != NULL)
				token = ft_add_subs_tok(newtoken, start, length, token);
			if (newtoken == NULL)
				token = ft_rem_subs_tok(start, length, token);
		}
		else if (ft_ispresent(start, '$', 39, token) == 0)
			return (token);
		start++;
	}
	return (token);
}

int	ft_check_rd_cat(int start, int token_category, char *string)
{
	start++;
	if (string[start] == '<')
		token_category = CAT_REDIR_LL;
	else if (string[start] == '>')
		token_category = CAT_REDIR_RR;
	return (token_category);
}

int	ft_save_redirect(int start, int token_category,
		char *string, t_minishell *minishell)
{
	int		i;
	int		strstart;
	char	*tokencopy;

	i = start;
	token_category = ft_check_rd_cat(i, token_category, string);
	if (token_category == CAT_REDIR_LL || token_category == CAT_REDIR_RR)
		i++;
	i++;
	i += ft_skipspaces(i, string);
	strstart = i;
	i += ft_scanforlen_rd(i, string);
	tokencopy = ft_substr(string, strstart, (i - strstart));
	tokencopy = ft_cleantoken(tokencopy, minishell);
	save_redirect_token(token_category, tokencopy, minishell);
	return (i - start);
}
