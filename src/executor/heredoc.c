/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:26:18 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/15 13:13:48 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	heredoc_magic(char **string, char **tmp, char **buff, char *delimiter)
{
	if (ft_strcmp(*buff, delimiter) == 0)
	{
		free(*buff);
		return (1);
	}
	tmp[0] = ft_strjoin(*string, *buff);
	tmp[1] = ft_strjoin(tmp[0], "\n");
	free(tmp[0]);
	free(*string);
	free(*buff);
	*string = tmp[1];
	return (0);
}

void	ft_close_pipe(int *doc_pipe)
{
	if (!doc_pipe)
		return ;
	close(doc_pipe[0]);
	close(doc_pipe[1]);
}

void	heredoc_child(int *doc_pipe, char *delimiter, t_minishell *shell)
{
	char	*string;
	char	*tmp[2];
	char	*buff;

	(void)shell;
	string = ft_strdup("");
	while (1)
	{
		buff = readline("> ");
		if (heredoc_magic(&string, tmp, &buff, delimiter))
			break ;
	}
	if ((write(doc_pipe[1], string, ft_strlen(string)) == -1))
		perror("write function failed\n");
	free(string);
}

int	heredoc_input(char *delimiter, t_minishell *shell)
{
	int		doc_pipe;

	doc_pipe = heredoc_input_single(delimiter, shell);
	return (doc_pipe);
}
