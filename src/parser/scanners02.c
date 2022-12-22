/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanners02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:50:46 by mluik             #+#    #+#             */
/*   Updated: 2022/10/14 22:46:56 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Scans a string for two double quotes and removes them. */
char	*ft_find_two_quotes(char *token)
{
	int	first;
	int	second;

	first = 0;
	second = 0;
	while (token[first] != '"' && token[first] != '\0')
		first++;
	if (first != 0 && token[first - 1] == '=')
	{
		second = first + 1;
		while (token[second] != '"' && token[second] != '\0')
			second++;
		if (token[first] != '\0' && token[second] != '\0')
		{
			token = ft_rem_subs_tok(++first, 0, token);
			token = ft_rem_subs_tok(second, 0, token);
		}
	}
	return (token);
}

/* Scans for the character c in a given string, 
	starting from the start position (int start), 
	skipping all fields between two characters
	marked as s (for skip). 
	Example: Scan for $, skip fields between
	single quotes (s = '\''). 
	Returns a boolean value 1 for true, 
	and 0 for false - in case c is found
	or not. */
int	ft_ispresent(int start, char c, char s, char *string)
{
	int	i;

	i = 0;
	i = start;
	while (string[i] != '\0')
	{
		if (string[i] == s)
		{
			i++;
			i += ft_scanforchar(i, s, string);
			i++;
		}
		if (string[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/* Scans for the character c in a given string, 
	starting from the start position (int start), 
	skipping all fields between two characters
	marked as s (for skip). 
	Example: Scan for $, skip field between
	single quotes (s = '\''). 
	Returns number of characters counted
	from starting position to found char.*/
int	ft_scanandskip(int start, char c, char s, char *string)
{
	int	i;

	i = start;
	while (string)
	{
		if (string[i] == s)
		{
			i++;
			i += ft_scanforchar(i, s, string);
		}
		if (string[i] == c)
			return (i - start);
		i++;
	}
	return (i - start);
}

/* Scans for the length of the redirection token, 
	taking in consideration " and ' as possible
	parts of the token." */
int	ft_scanforlen_rd(int start, char *string)
{
	int	i;

	i = start;
	while (string[i] != 32 && string[i] != 60
		&& string[i] != 62 && string[i] != 124
		&& string[i] != '\0')
	{
		if (string[i] == 34)
		{
			i++;
			i += ft_scanforchar(i, 34, string);
		}
		if (string[i] == 39)
		{
			i++;
			i += ft_scanforchar(i, 39, string);
		}
		i++;
	}
	return (i - start);
}

/* 	Scans for a separator after a variable ($) sign.
	Separators can be: space, ", ' , = and \ .*/
int	ft_scanforvarsep(int start, char *string)
{
	int	i;

	i = start;
	i++;
	while ((string[i] != '\0') && (string[i] != 32
			&& string[i] != 34 && string[i] != 39
			&& string[i] != 92 && string[i] != 61
			&& string[i] != 63))
	{
		i++;
	}
	return (i - start);
}
