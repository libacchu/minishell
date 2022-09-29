/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:07:17 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/22 12:27:40 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_lexlist	*make_arg(int argc, t_lexlist *loop, t_command *process);
t_lexlist	*skip_pipes_space(t_lexlist *loop);
int			nbr_args_in_cmd(t_lexlist *tokenlist);

/*
** convert_to_argv()
		creates the char ** variables needed for execution.
*/
int	convert_to_argv(t_minishell *shell, t_executor *exec)
{
	t_lexlist	*loop;
	int			argc;
	int			i;

	loop = shell->tokenlist;
	i = 0;
	while (loop && i < exec->amt_of_cmds)
	{
		argc = nbr_args_in_cmd(loop);
		exec->process[i].index = loop->field_by_pipe;
		loop = make_arg(argc, loop, &exec->process[i]);
		i++;
		if (loop)
			loop = loop->next;
	}
	return (0);
}

char	*ft_strdup_01(const char *s1)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + 1;
	ptr = (char *)ft_calloc(len, sizeof(char));
	i = 0;
	if (ptr)
	{	
		while (i < len - 1)
		{
			ptr[i] = *(char *)(s1 + i);
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	return (NULL);
}

t_lexlist	*make_arg(int argc, t_lexlist *loop, t_command *process)
{
	int	i;

	i = 0;
	process->cmd = ft_calloc(2, sizeof(t_cmd));
	process->cmd->command = ft_calloc((argc + 1), sizeof(char **));
	while (i < argc && loop)
	{
		loop = skip_pipes_space(loop);
		if (loop && loop->token)
		{
			process->cmd->command[i] = loop->token;
		}
		if (loop)
			loop = loop->next;
		i++;
	}
	process->cmd->command[i] = "\0";
	return (loop);
}

/*	Skips all the pipes and spaces while iterating
		through a lexlist struct.
	Returns a pointer to the next node that is not a
		space or pipe.
*/
t_lexlist	*skip_pipes_space(t_lexlist *loop)
{
	while ((loop->token_category == CAT_PIP) || \
		(loop->token_category == CAT_SPAC))
	{
		if (loop->next)
			loop = loop->next;
		else
			break ;
	}
	return (loop);
}

/*	nbr_args_in_cmd() looks between pipes and
		count the number of arguments.
*/
int	nbr_args_in_cmd(t_lexlist *tokenlist)
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
