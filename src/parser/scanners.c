/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:13:37 by mluik             #+#    #+#             */
/*   Updated: 2022/10/15 13:21:40 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* 	Checks for the escape character infront
	of special characters, ie \ ', \ ", etc */
int	ft_checkforescape(int start, char *string)
{
	int	i;

	i = start - 1;
	if (string[i] == 92)
		return (1);
	else
		return (0);
}

/* 	Scans for a character c in a string, starting at the position i,
	ending at first occurance of c OR at end of string
	AND at the occurence of '\'' or '\"'.
	Area between ' and ' is skipped. 
	*/
int	ft_scanforchar_extra(int start, char c, char *string)
{
	int	i;

	i = start;
	while ((string[i] != '\0') && (string[i] != c))
	{
		if (string[i] == 39)
		{
			i += ft_checkforescape(i, string);
			i++;
			i += ft_scanforchar(i, 39, string);
		}
		else
			i++;
	}
	return (i - start);
}

/* 	Scans for a character c in a string, starting at the position i,
	ending at first occurance of c OR at end of string. 
	Keep in mind! - For the categories SINGLEQ and DOUBLEQ, 
	function already skips the quotation characters.*/
int	ft_scanforchar(int start, char c, char *string)
{
	int	i;

	i = start;
	while ((string[i] != '\0') && (string[i] != c))
	{
		i++;
	}
	return (i - start);
}

/* Additional conditions to refine the
	"ft_scanforlength" process during parsing. (ft follows) */
int	ft_dealw_scanlen(int start, char *string, int tokenlength)
{
	int		cmp_len;

	cmp_len = 0;
	tokenlength = ft_scanforchar(start, 32, string);
	if (tokenlength >= (ft_scanforchar(start, '"', string)))
		tokenlength = ft_scanforchar(start, '"', string);
	if (tokenlength >= (ft_scanforchar(start, '\'', string)))
		tokenlength = ft_scanforchar(start, '\'', string);
	cmp_len = ft_scanforchar(start, '=', string);
	if (cmp_len < tokenlength && cmp_len >= 0 && \
		string[start + cmp_len + 1] == '"')
		tokenlength = cmp_len;
	if (string[start + tokenlength] == '=' && \
		string[start + tokenlength + 1] == '"')
	{
		tokenlength = tokenlength + 2;
		tokenlength += ft_scanforchar((tokenlength + start), '"', string);
		tokenlength++;
	}
	if (tokenlength > ft_scanfor_redir(start, string) && \
		cmp_len > ft_scanfor_redir(start, string))
		return (ft_scanfor_redir(start, string));
	return (tokenlength);
}

/* 	Scans for and returns length of a token in the lexing
	phase.
	Does not scan for $ (= $ are skipped inside ""). 
	Skips one starting character for double and single
	quotes, but not for string after a space. */
int	ft_scanforlength(int start, int tok_cat, char *string)
{
	int		tokenlength;
	char	c;

	tokenlength = 1;
	c = 32;
	if (tok_cat == CAT_DEFAULT)
		tokenlength = ft_dealw_scanlen(start, string, tokenlength);
	else if (tok_cat == CAT_SPAC)
		tokenlength = ft_scanforseveralchars(start, c, string);
	else if (tok_cat == CAT_DOUBLEQ)
	{
		c = 34;
		tokenlength = ft_scanforchar(++start, c, string);
	}
	else if (tok_cat == CAT_SINGLEQ)
	{
		c = 39;
		tokenlength = ft_scanforchar(++start, c, string);
	}
	else if (tok_cat == CAT_PIP)
		tokenlength = 1;
	return (tokenlength);
}
