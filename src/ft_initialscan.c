/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialscan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:03:18 by mluik             #+#    #+#             */
/*   Updated: 2022/07/22 16:05:25 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*separate_string_bypipe(int i, int strlen, char *string, t_minishell *minishell)
{
	int		j;
	char	*struct_element;

	j = 0;
	struct_element = ft_calloc(sizeof(char *), (i + 1));
	while (j != (i - 1))
	{
		struct_element[j] = string[j];
		j++;
	}
	j++;
	struct_element[j] = '\0';
	addtostruct_category_0(struct_element, minishell);
	string = ft_substr(string, ++j, strlen);
	return (string);
}

void	ft_checkifeligible(char *string)
{
	int	charcount;
	int	specialcharcount;

	charcount = 0;
	specialcharcount = 0;
	while (string[charcount] != '\0')
	{
		if (string[charcount] == '"' || string[charcount] == 39)
			specialcharcount++;
		charcount++;
	}
	if ((specialcharcount % 2) == 0)
		return ;
	else 
		exit_w_error("Wrong input\n"); // -> will be rewritten later to SAVE EXIT as separate command for EXEC phase;
}

int	ft_initialscan(char *string, t_minishell *minishell)
{
	int		i;
	int		strlen;
	char	*copystring;

	i = 0;
	strlen = ft_strlen(string);
	ft_checkifeligible(string);
	while (strlen != 0)
	{
		copystring = ft_strdup(string);
		while (copystring[i] != '\0')
		{
			if (copystring[i] == '"' || copystring[i] == '\'')
			{
				while (copystring[i] != '"' || copystring[i] != '\'')
					i++;
			}
			else if (copystring[i] == '|')
			{
				copystring = separate_string_bypipe(i, strlen, copystring, minishell);
				strlen = ft_strlen(copystring);
				i = -1;
			}
			i++;
		}
		free(copystring);
	}
	return (0);
}
