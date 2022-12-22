/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 19:19:40 by mluik             #+#    #+#             */
/*   Updated: 2022/10/13 19:51:51 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Error handling for unfit redirection token content. */
int	ft_unex_tok(int pos, char *string)
{
	if (string[pos] == '\n' || string[pos] == '\0')
	{
		ft_printf("minishell: syntax error near unexpected token `newline'\n");
		return (1);
	}
	if ((string[pos] <= '*' && string[pos] >= '!') \
		|| string[pos] == ';' || string[pos] == '|' \
		|| string[pos] == '<' || string[pos] == '>')
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(": syntax error near unexpected token `", STDERR_FILENO);
		ft_putchar_fd(string[pos], STDERR_FILENO);
		if (string[pos] == '<' && string[pos + 1] == '<')
			ft_putchar_fd(string[pos], STDERR_FILENO);
		if (string[pos] == '>' && string[pos + 1] == '>')
			ft_putchar_fd(string[pos], STDERR_FILENO);
		ft_putstr_fd("'\n", STDERR_FILENO);
		return (1);
	}
	else
		return (0);
}

/* Expands variabels in direction tokens with given conditions, 
	including $? */
char	*ft_dealw_rdclean(int start, char *token, t_minishell *minishell)
{
	int		length;
	char	*variable;
	char	*newtoken;

	length = 0;
	start += ft_scanandskip(start, 36, 39, token);
	length = ft_scanforvarsep(++start, token);
	variable = ft_substr(token, start, length);
	if (ft_strcmp(variable, "?") == 0)
		newtoken = ft_exp_exit(minishell);
	else
		newtoken = ft_findvariable_inlist(variable, minishell);
	if (newtoken != NULL)
		token = ft_add_subs_tok(newtoken, start, length, token);
	if (newtoken == NULL)
		token = ft_rem_subs_tok(start, length, token);
	if (newtoken != NULL)
		free(newtoken);
	free(variable);
	return (token);
}

/* Cleans redirection tokens of variables and expands them. */
char	*ft_cleantoken(char *token, t_minishell *minishell)
{
	int		start;

	start = 0;
	while (token[start] != '\0')
	{
		if (ft_ispresent(start, '$', 39, token) == 1)
			ft_dealw_rdclean(start, token, minishell);
		else if (ft_ispresent(start, '$', 39, token) == 0)
			return (token);
		start++;
	}
	return (token);
}

/* Checks for redirection category between < and >>, 
	> and >>. */
int	ft_check_rd_cat(int start, int tok_cat, char *string)
{
	start++;
	if (string[start] == '<')
		tok_cat = CAT_REDIR_LL;
	else if (string[start] == '>')
		tok_cat = CAT_REDIR_RR;
	return (tok_cat);
}

/* Handles the whole parsing process after having scanned 
	a redirect combination (<, <<, >>, >>). */
int	ft_save_redirect(int start, int tok_cat,
		char *string, t_minishell *minishell)
{
	unsigned int		i;
	int					strstart;
	char				*tokencopy;

	i = start;
	tok_cat = ft_check_rd_cat(i, tok_cat, string);
	if (tok_cat == CAT_REDIR_LL || tok_cat == CAT_REDIR_RR)
		i++;
	i++;
	i += ft_skipspaces(i, string);
	strstart = i;
	if (ft_unex_tok(i, string) == 1)
		return (2147483647);
	i += ft_scanforlen_rd(i, string);
	tokencopy = ft_substr(string, strstart, (i - strstart));
	tokencopy = ft_cleantoken(tokencopy, minishell);
	save_redirect_token(tok_cat, tokencopy, minishell);
	return (i - start);
}
