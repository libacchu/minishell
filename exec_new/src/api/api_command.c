/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:07:17 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/21 21:43:56 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char **make_arg(int argc, t_lexlist	**loop);
t_lexlist	*skip_pipes_space(t_lexlist *loop);
int nbr_of_cmd_args(t_lexlist *tokenlist);

/*
** convert_to_argv()
		creates the char ** variables needed for execution.
*/
int	convert_to_argv(t_minishell *shell, t_executor *exec)
{
	t_lexlist	*loop;
	char		**cmd;
	int			argc;
	int			i;
	
	loop = shell->tokenlist;
	i = 0;
	while (loop && i < exec->amt_of_cmds)
	{
		argc = nbr_of_cmd_args(loop);
		exec->process[i].cmd = make_arg(argc, &loop);
		exec->process[i].index = loop->field_by_pipe;
		i++;
		if (loop)
			loop = loop->next;
	}
	return (0);
}

char **make_arg(int argc, t_lexlist	**loop)
{
	int i;
	char **cmd;
	
	i = 0;
	cmd = ft_calloc(sizeof(char *), argc + 1);
	while (i < argc && (*loop))
	{
		(*loop) = skip_pipes_space((*loop));
		if ((*loop) && (*loop)->token)
		{
			cmd[i] = ft_strdup((*loop)->token);
		}
		if ((*loop))
			(*loop) = (*loop)->next;
		i++;
	}
	return (cmd);
}

/*	Skips all the pipes and spaces while iterating
		through a lexlist struct.
	Returns a pointer to the next node that is not a
		space or pipe.
*/
t_lexlist	*skip_pipes_space(t_lexlist *loop)
{
	while ((loop->token_category == CAT_PIP) || (loop->token_category == CAT_SPAC))
	{
		if (loop->next)
			loop = loop->next;
		else
			break ;
	}
	return (loop);
}

/*	nbr_of_cmd_args() looks between pipes and
		count the number of arguments.
*/
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
		if (tmp && tmp->token_category == CAT_PIP)
			break ;
		if (tmp)
			tmp = tmp->next;
		count++;
	}
	return (count);
}