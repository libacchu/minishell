/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_scan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:52:35 by mluik             #+#    #+#             */
/*   Updated: 2022/10/14 12:36:00 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_rem_subs_tok(int start, int len, char *string)
{
	char	*firstpart;
	char	*lastpart;
	char	*temp;

	temp = string;
	firstpart = ft_substr(string, 0, --start);
	lastpart = ft_substr(string, (start + (len + 1)), strlen(string));
	string = ft_strjoin(firstpart, lastpart);
	free(firstpart);
	free(lastpart);
	free(temp);
	return (string);
}

char	*ft_add_subs_tok(char *tobeadded, int start, int len, char *string)
{
	char	*firstpart;
	char	*lastpart;
	char	*temp;
	char	*temp2;

	temp = string;
	firstpart = ft_substr(string, 0, --start);
	lastpart = ft_substr(string, (start + (len + 1)), strlen(string));
	string = ft_strjoin(firstpart, tobeadded);
	temp2 = string;
	string = ft_strjoin(string, lastpart);
	free(firstpart);
	free(lastpart);
	free(temp);
	free(temp2);
	return (string);
}

char	*ft_findvariable_inlist(char *variable, t_minishell *minishell)
{
	char		*comparison;
	t_envlist	*open_node;

	open_node = minishell->envlist;
	while (open_node)
	{
		if (ft_strcmp(variable, open_node->variable) == 0)
		{
			if (open_node->content)
				comparison = ft_strdup(open_node->content);
			else
				comparison = NULL;
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
	placeholder value. */
t_lexlist	*ft_switch_var_env(t_lexlist *tok, t_minishell *minishell)
{
	int		start;
	int		length;

	length = 0;
	start = 0;
	while (tok->token && tok->token[start] != '\0')
	{
		if (ft_ispresent(start, '$', 39, tok->token) == 1)
			ft_dealwith_repl(start, tok, length, minishell);
		else if (ft_ispresent(start, '$', 39, tok->token) == 0)
			return (tok);
		start++;
	}
	return (tok);
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
		if (open_node->tok_cat == CAT_DEFAULT
			|| open_node->tok_cat == CAT_DOUBLEQ)
		{
			open_node->token = \
				ft_find_two_quotes(open_node->token);
			open_node = \
				ft_switch_var_env(open_node, minishell);
		}
		if (open_node->tok_cat == CAT_DEFAULT)
			open_node = ft_replace_home(open_node, minishell);
		open_node = open_node->next;
	}
	return (0);
}
