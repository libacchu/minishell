/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 09:18:07 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/15 15:20:33 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_redirect_file_in(t_minishell *shell, int nbr)
{
	t_lexlist	*tmp;

	tmp = NULL;
	if (shell->redir_list)
		tmp = shell->redir_list;
	while (tmp)
	{
		if (tmp->tok_cat == CAT_REDIR_L && tmp->field_by_pipe == nbr)
		{
			if (access(tmp->token, F_OK | R_OK) != 0)
			{
				perror(tmp->token);
				return (up_exit(1, shell));
			}
			shell->executor->cmd_nodes[nbr].cat_redir_in = tmp->tok_cat;
			shell->executor->cmd_nodes[nbr].infile = tmp->token;
		}
		else if (tmp->tok_cat == 7 && tmp->field_by_pipe == nbr)
		{
			shell->executor->cmd_nodes[nbr].cat_redir_in = tmp->tok_cat;
			shell->executor->cmd_nodes[nbr].infile = tmp->token;
		}
		tmp = tmp->next;
	}
	return (0);
}

void	open_file_out(int *fdout, char **outfile, t_lexlist	*tmp)
{
	if (*fdout)
		close(*fdout);
	*outfile = tmp->token;
	if (tmp->tok_cat == CAT_REDIR_R)
		*fdout = open(*outfile, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	else if (tmp->tok_cat == CAT_REDIR_RR)
		*fdout = open(*outfile, O_WRONLY | O_CREAT | O_APPEND, 0664);
}

int	check_redirect_file_out(t_minishell *shell, int cmd_nbr)
{
	t_lexlist	*tmp;
	int			*fdout;
	char		**outfile;

	fdout = &shell->executor->cmd_nodes[cmd_nbr].fdout;
	outfile = &shell->executor->cmd_nodes[cmd_nbr].outfile;
	tmp = NULL;
	if (shell->redir_list)
		tmp = shell->redir_list;
	while (tmp)
	{	
		if ((tmp->tok_cat == CAT_REDIR_R || \
			tmp->tok_cat == 9) && tmp->field_by_pipe == cmd_nbr)
		{
			open_file_out(fdout, outfile, tmp);
			if (*fdout == -1)
			{
				perror(*outfile);
				return (up_exit(1, shell));
			}
		}
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}

int	redirection_in(t_executor *exec, int i)
{
	if (exec->cmd_nodes[i].infile)
	{
		if (exec->cmd_nodes[i].cat_redir_in == CAT_REDIR_L)
			exec->cmd_nodes[i].fdin = open(exec->cmd_nodes[i].infile, O_RDONLY);
		else if (exec->cmd_nodes[i].cat_redir_in == CAT_REDIR_LL)
			exec->cmd_nodes[i].fdin = heredoc_input_single(\
				exec->cmd_nodes[i].infile, exec->shell);
		if (exec->cmd_nodes[i].fdin == 1)
			return (1);
	}
	else
	{
		if (i == 0)
			exec->cmd_nodes[i].fdin = STDIN_FILENO;
		else
			exec->cmd_nodes[i].fdin = exec->fdpipe[i - 1][0];
	}
	return (0);
}

int	redirection_out(t_executor *exec, int i)
{
	if (exec->cmd_nodes[i].outfile)
	{
		if (exec->cmd_nodes[i].cat_redir_out == CAT_REDIR_R)
		exec->cmd_nodes[i].fdout = open(exec->cmd_nodes[i].outfile, \
			O_WRONLY | O_CREAT | O_TRUNC, 0777);
		else if (exec->cmd_nodes[i].cat_redir_out == CAT_REDIR_RR)
		exec->cmd_nodes[i].fdout = open(exec->cmd_nodes[i].outfile, \
			O_WRONLY | O_CREAT | O_APPEND, 0777);
	}
	else
	{
		if (i == *(exec->pipe_count))
			exec->cmd_nodes[i].fdout = STDOUT_FILENO;
		else
			exec->cmd_nodes[i].fdout = exec->fdpipe[i][1];
	}
	return (0);
}
