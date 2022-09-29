/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_scan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:52:35 by mluik             #+#    #+#             */
/*   Updated: 2022/08/05 20:21:46 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_rem_subs_tok(int start, int len, char *string)
{
	char	*firstpart;
	char	*lastpart;

	firstpart = ft_substr(string, 0, --start);
	lastpart = ft_substr(string, (start + (len + 1)), strlen(string));
	string = ft_strjoin(firstpart, lastpart);
	return (string);
}

char	*ft_add_subs_tok(char *tobeadded, int start, int len, char *string)
{
	char	*firstpart;
	char	*lastpart;

	firstpart = ft_substr(string, 0, --start);
	lastpart = ft_substr(string, (start + (len + 1)), strlen(string));
	string = ft_strjoin(firstpart, tobeadded);
	string = ft_strjoin(string, lastpart);
	return (string);
}

char	*ft_findvariable_inlist(char *variable, t_minishell *minishell)
{
	char		*comparison;
	t_envlist	*open_node;

	open_node = minishell->envlist;
	while (open_node)
	{
		if (strcmp(variable, open_node->variable) == 0)
		{
			comparison = ft_strdup(open_node->content);
			return (comparison);
		}
		else
		{
			comparison = NULL;
			open_node = open_node->next;
		}
	}
	return (comparison);
}

/* Switches a $VAR string with its contents
	from the env list. 
	Also checks for $? - and replaces with
	placeholder value (has to be changed; state
	03.08.2022)
	
		if (token[++start] == 63)
		{
			length = 1;
		}
		
		*/
char	*ft_switch_var_env(char *token, t_minishell *minishell)
{
	int		start;
	int		length;
	char	*variable;
	char	*newtoken;

	length = 0;
	start = 0;
	while (token[start] != '\0')
	{
		if (ft_ispresent(start, '$', 39, token) == 1)
		{
			start += ft_scanforchar_extra(start, '$', token);
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

/* Further scans through the lexlist 
	to find environmental variables and deal
	with them. 
	Resets the pipe_counter for next parsing
	cycle.*/
int	ft_refine_scan(t_minishell *minishell)
{
	t_lexlist	*open_node;

	open_node = minishell->tokenlist;
	while (open_node)
	{
		if (open_node->token_category == CAT_DEFAULT
			|| open_node->token_category == CAT_DOUBLEQ)
			open_node->token =
				ft_switch_var_env(open_node->token, minishell);
		open_node = open_node->next;
	}
	minishell->pipe_counter = 0;
	return (0);
}
