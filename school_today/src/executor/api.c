/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   API.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 08:22:02 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/09 17:54:58 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int		lex_length(t_lexlist *tokenlist)
{
	int	count;
	t_lexlist *tmp;

	tmp = tokenlist;
	count = 0;
	while(tmp)
	{
		if(tmp->token == NULL)
			tmp = tmp->next;
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	nbr_of_cmds(t_lexlist *tokenlist)
{
	t_lexlist	*tmp;
	int			count;

	tmp = tokenlist;
	count = 1;
	while (tmp)
	{
		if (tmp->token_category == CAT_PIP)
			count++;
		tmp = tmp->next;
	}
	ft_printf("count = %d\n", count);
	return (count);
}

int nbr_of_cmd_args(t_lexlist *tokenlist)
{
	t_lexlist	*tmp;
	int			count;
	
	tmp = tokenlist;
	count = 0;
	while (tmp)
	{
		if (tmp->token == NULL)
			tmp = tmp->next;
		if (tmp->token_category == CAT_PIP)
			break ;
		tmp = tmp->next;
		count++;
	}
	return (count);
}

int	convert_to_argv(t_minishell *shell)
{
	int			len;
	t_lexlist	*tmp;
	int			i;
	int			j;
	int			argc;
	
	i = 0;
	tmp = shell->tokenlist;
	ft_printf("1\n");
	len = lex_length(shell->tokenlist);
	ft_printf("2\n");
	shell->executor->argv = ft_calloc(sizeof(char **), (len + 1));
	ft_printf("3\n");
	while (tmp && i < shell->executor->nbr_of_cmds)
	{
		j = 0;
		ft_printf("4\n");
		argc = nbr_of_cmd_args(tmp);
		ft_printf("5\n");
		shell->executor->argv[i] = ft_calloc(sizeof(char *), (argc + 1));
		ft_printf("6\n");
		while (j < argc)
		{
			ft_printf("7\n");
			if (tmp->token == NULL)
				tmp = tmp->next;
			if (tmp->token_category == CAT_PIP)
			{
				tmp = tmp->next;
				break ;
			}
			shell->executor->args[i][j] = *ft_strdup(tmp->token);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < shell->executor->nbr_of_cmds)
	{
		print_arr(shell->executor->argv[i]);
		i++;
	}
	return (0);
}

// int	make_cmds_list(t_minishell *shell)
// {
	
// }
