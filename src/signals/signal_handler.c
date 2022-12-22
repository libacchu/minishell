/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 07:38:29 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/15 11:51:07 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_ctrl_c_proc(int sig)
{
	if (sig == SIGQUIT)
	{
		ft_putstr_fd("Exited. \n", STDOUT_FILENO);
		g_shutdown_flag = 3;
	}
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		ft_putchar_fd('\n', STDOUT_FILENO);
		g_shutdown_flag = 3;
	}
}

void	handle_ctrl_c(int sig)
{
	(void)sig;
	rl_replace_line("", 0);
	rl_on_new_line();
	ft_putchar_fd('\n', STDOUT_FILENO);
	rl_redisplay();
	g_shutdown_flag = 2;
}

void	ft_handle_signals(t_minishell *shell)
{
	if (getpid() == shell->parent_pid)
	{
		signal(SIGINT, handle_ctrl_c_proc);
		signal(SIGQUIT, handle_ctrl_c_proc);
	}
	else
	{
		signal(SIGINT, handle_ctrl_c);
		signal(SIGQUIT, SIG_IGN);
	}
}

void	ft_disable_signals(void)
{
	signal(SIGINT, handle_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}
