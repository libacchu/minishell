/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:48:20 by mluik             #+#    #+#             */
/*   Updated: 2022/10/14 18:09:51 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	heredoc_child_one(int *doc_pipe, char *delimiter, t_minishell *shell)
{
	char	*string;
	char	*tmp[2];
	char	*buff;

	heredoc_sig_func();
	string = ft_strdup("");
	while (1)
	{
		buff = readline("> ");
		if (buff == 0)
		{
			ft_putchar_fd('\n', 1);
			break ;
		}
		if (heredoc_magic(&string, tmp, &buff, delimiter))
			break ;
	}
	if ((write(doc_pipe[1], string, ft_strlen(string)) == -1))
		perror("write function failed\n");
	ft_close_pipe(doc_pipe);
	free(string);
	ft_exit(NULL, shell, 0);
}

int	heredoc_input_single(char *delimiter, t_minishell *shell)
{
	int		doc_pipe[2];
	int		fork_id;

	if (pipe(doc_pipe) == -1)
		perror("pipe failed");
	fork_id = fork();
	if (fork_id == 0)
	{
		heredoc_sig_func();
		heredoc_child_one(doc_pipe, delimiter, shell);
	}
	else
	{
		heredoc_sig_single();
		waitpid(fork_id, &shell->exit_status, 0);
		shell->exit_status = shell->exit_status / 256;
		if (shell->exit_status == 130)
			return (1);
	}
	close(doc_pipe[1]);
	ft_handle_signals(shell);
	return (doc_pipe[0]);
}
