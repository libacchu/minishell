/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialscan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:03:18 by mluik             #+#    #+#             */
/*   Updated: 2022/08/05 21:08:53 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* 
	Assigns a category for the lexical analyser function. 	
	Token categories are: 
	CAT_DEFAULT - int value 0 - default category
	CAT_DOUBLEQ - int value 1 - Double quotation string
	CAT_SINGLEQ - int value 2 - Single quotation string
	etc. (See Minishell.h for full list)
 */
int	ft_findcategory(int start, char *string)
{
	int	token_category_choice;

	token_category_choice = CAT_DEFAULT;
	if (string[start] == '"')
		token_category_choice = CAT_DOUBLEQ;
	else if (string[start] == '\'')
		token_category_choice = CAT_SINGLEQ;
	else if (string[start] == '|')
		token_category_choice = CAT_PIP;
	else if (string[start] == ' ')
		token_category_choice = CAT_SPAC;
	else if (string[start] == '<')
		token_category_choice = CAT_REDIR_L;
	else if (string[start] == '>')
		token_category_choice = CAT_REDIR_R;
	return (token_category_choice);
}

/* 	Gives every token a category, finds the length of a token
	 (until a separator is found), 
	and saves that part of the input string as a new token. */
int	ft_scanforsep_save(int start, char *string,
			t_minishell *minishell)
{
	int		tokenlength;
	int		token_category;
	char	*tokencopy;

	token_category = ft_findcategory(start, string);
	if (token_category == CAT_REDIR_L || token_category == CAT_REDIR_R)
	{
		tokenlength = ft_save_redirect(start, token_category, string,
				minishell);
		return (tokenlength);
	}
	tokenlength = ft_scanforlength(start, token_category, string);
	if ((token_category == CAT_DOUBLEQ) || (token_category == CAT_SINGLEQ))
		tokencopy = ft_substr(string, (start + 1), (tokenlength));
	else
		tokencopy = ft_substr(string, start, tokenlength);
	if (token_category == CAT_PIP)
		minishell->pipe_counter++;
	save_token(token_category, tokencopy, minishell);
	if ((token_category == CAT_DOUBLEQ) || (token_category == CAT_SINGLEQ))
		return (tokenlength + 2);
	else
		return (tokenlength);
}

/* 	Scans for spaces and returns the position of first non-space character;
	 */
int	ft_skipspaces(int start, char *string)
{
	int	i;

	i = start;
	while (string[i] == ' ' || string[i] == '\t')
		i++;
	return (i - start);
}

/* 	initializes the scan of the entered string. 
	Minor error handling. 
	Lexical analysis of the string is done, 
	looking for special characters
	that separate fields: spaces, " and '. */
int	ft_initialize_scan(char *string, t_minishell *minishell)
{
	int		i;
	char	*charcopy;

	i = 0;
	ft_checkifeligible(string);
	i += ft_skipspaces(i, string);
	while (string[i] != '\0')
	{
		i += ft_scanforsep_save(i, string, minishell);
		if (string[i] == ' ' || string[i] == '|')
		{
			charcopy = ft_substr(string, i, 1);
			i += ft_save_separator(charcopy, i, string, minishell);
		}
	}
	return (0);
}
