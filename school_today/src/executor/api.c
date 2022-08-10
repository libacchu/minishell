/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 08:22:02 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/10 16:00:00 by libacchu         ###   ########.fr       */
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
	return (count);
}

int nbr_of_cmd_args(t_lexlist *tokenlist)
{
	t_lexlist	*tmp;
	int			count;
	
	tmp = tokenlist;
	count = 0;
	if (tmp->token_category == CAT_PIP)
		tmp = tmp->next;
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

int print_t_list(t_list *list)
{
	t_list *tmp;
	
	tmp = list;
	while (tmp)
	{
		print_arr(tmp->content);
		tmp = tmp->next;
	}
	return (0);
}

int	convert_to_argv(t_minishell *shell)
{
	t_lexlist	*loop;
	int			argc;
	int			i;
	char		**cmd;
	char		**tmp;

	loop = shell->tokenlist;
	while (loop)
	{
		i = -1;
		argc = nbr_of_cmd_args(loop);
		// ft_printf("argc = %d\n", argc);
		cmd = ft_calloc(sizeof(char *), argc + 1);
		while (++i < argc)
		{
			while ((loop->token_category == CAT_PIP) || (loop->token_category == CAT_SPAC))
				loop = loop->next;
			cmd[i] = ft_strdup(loop->token);
			// ft_printf("loop->token = %s\n", loop->token);
			// ft_printf("cmd[%d] = %s\n", i, cmd[i]);
			loop = loop->next;
		}
		tmp = cmd;
		
		if (!shell->executor->argv)
			shell->executor->argv = ft_lstnew(tmp);
		else
			ft_lstadd_back(&shell->executor->argv, ft_lstnew(tmp));
		// ft_free_substring(cmd);
		if (loop)
			loop = loop->next;
	}
		// ft_printf("----HERE----\n");
	return (0);
}




// int	convert_to_argv(t_minishell *shell)
// {
// 	int			len;
// 	t_lexlist	*tmp;
// 	int			i;
// 	int			j;
// 	int			argc;
	
// 	i = 0;
// 	tmp = shell->tokenlist;
// 	len = lex_length(shell->tokenlist);
// 	shell->executor->argv = ft_calloc(sizeof(char **), (len + 1));
// 	while (tmp && i < shell->executor->nbr_of_cmds)
// 	{
// 		j = 0;
// 		argc = nbr_of_cmd_args(tmp);
// 		shell->executor->argv[i] = ft_calloc(sizeof(char *), (argc + 1));
// 		while (j < argc)
// 		{
// 			if (tmp->token == NULL)
// 				tmp = tmp->next;
// 			if (tmp->token_category == CAT_PIP)
// 			{
// 				tmp = tmp->next;
// 				break ;
// 			}
// 			shell->executor->argv[i][j] = ft_strdup(tmp->token);
// 			// ft_printf("-----HERE-----\n");
// 			j++;
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while (i < shell->executor->nbr_of_cmds)
// 	{
// 		print_arr(shell->executor->argv[i]);
// 		i++;
// 	}
// 	return (0);
// }

// int	make_cmds_list(t_minishell *shell)
// {
	
// }
