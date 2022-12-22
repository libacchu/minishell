/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler_02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:25:12 by mluik             #+#    #+#             */
/*   Updated: 2022/10/15 11:56:34 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	heredoc_sig_single(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
}

void	heredoc_sig_hand(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 2);
		exit(130);
	}
	else if (sig == SIGQUIT)
	{
		ft_putstr_fd("\n", 2);
		exit(130);
	}
}

void	heredoc_sig_func(void)
{
	signal(SIGQUIT, heredoc_sig_hand);
	signal(SIGINT, heredoc_sig_hand);
}
