/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:13:37 by mluik             #+#    #+#             */
/*   Updated: 2022/08/05 16:49:23 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

/* 	Scans for and returns length of a token in the lexing
	phase.
	Does not scan for $ (= $ are skipped inside ""). 
	Skips one starting character for double and single
	quotes, but not for string after a space. */
int	ft_scanforlength(int start, int token_category, char *string)
{
	int		tokenlength;
	char	c;

	tokenlength = 0;
	c = 32;
	if (token_category == CAT_DEFAULT)
		tokenlength = ft_scanforchar(start, c, string);
	else if (token_category == CAT_SPAC)
		tokenlength = ft_scanforseveralchars(start, c, string);
	else if (token_category == CAT_DOUBLEQ)
	{
		c = 34;
		tokenlength = ft_scanforchar(++start, c, string);
	}
	else if (token_category == CAT_SINGLEQ)
	{
		c = 39;
		tokenlength = ft_scanforchar(++start, c, string);
	}
	else if (token_category == CAT_PIP)
		tokenlength = 1;
	return (tokenlength);
}
