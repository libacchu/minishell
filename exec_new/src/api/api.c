/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 08:22:02 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/21 21:55:12 by libacchu         ###   ########.fr       */
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
		if (tmp)
			tmp = tmp->next;
	}
	return (count);
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

/*	Skips all the pipes and spaces while iterating
		through a lexlist struct.
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
			// ft_printf("cmd[%d] = %s\n", i, cmd[i]);
		}
		if ((*loop))
			(*loop) = (*loop)->next;
		i++;
	}
	// print_arr(cmd);
	return (cmd);
}

int	convert_to_argv(t_minishell *shell)
{
	t_lexlist	*loop;
	int			argc;
	char		**cmd;

	loop = shell->tokenlist;
	while (loop)
	{
		argc = nbr_of_cmd_args(loop);
		cmd = make_arg(argc, &loop);
		ft_lstadd_back(&shell->executor->argv, ft_lstnew(cmd));
		if (loop)
			loop = loop->next;
	}
	return (0);
}

int	check_redirect_file(t_minishell *shell)
{
	t_lexlist	*tmp;

	tmp = NULL;
	if (shell->redir_list)
		tmp = shell->redir_list;
	while (tmp)
	{
		if (tmp->token_category == CAT_REDIR_L)
			shell->executor->infile = ft_strdup(tmp->token);
		if (tmp->token_category == CAT_REDIR_R)
			shell->executor->outfile = ft_strdup(tmp->token);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_api_handler(t_minishell *shell, t_executor *exec)
{
	exec->amt_of_cmds = ft_nbr_of_cmds(shell->tokenlist);
	exec->process = ft_calloc(sizeof(t_command), exec->amt_of_cmds);
	convert_to_argv(shell, exec);
	return (0);
}
