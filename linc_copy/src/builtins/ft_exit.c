/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:43:01 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/26 09:04:08 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
** ft_exit()
** 		char *mess = a message to be written to output of choice.
**		t_minishell *minishell = struct to be freed before exit.
**		int fd = The file descriptor number.
**		int exnum = exit number.
*/

void	ft_exit(char *mess, t_minishell *minishell)
{
	if (mess)
		ft_putstr_fd(mess, 1);
	// (void) minishell;
	ft_free_minishell(minishell);
	exit(1);
}
