/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 07:38:29 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/21 22:48:20 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/minishell.h"
#include <signal.h>

/*
** Ctrl + C (SIGINT & SIGTERM)
**		Display a new prompt on a new line.
**
** Ctrl + D (SIGQUIT)
**		Exits the shell.
**
** Ctrl + \ (SIGABRT)
**		Does nothing
*/

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGINT)
	{
		// exit the current process and return the prompt
		ft_putchar_fd('\n', 1);
		ft_replace_line();
		rl_newline();
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
	{
		ft_exit();
	}
	else if (sig == SIGABRT)
	{
		// do nothing
	}
}
