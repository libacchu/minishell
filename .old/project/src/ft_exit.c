/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:43:01 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/22 10:57:38 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
** ft_exit()
** 		char *mess = a message to be written to output of choice.
**		t_minishell *minishell = struct to be freed before exit.
**		int fd = The file descriptor number.
**		int exnum = exit number.
*/

void	ft_exit(char *mess, t_minishell *minishell, int fd, int exnum)
{
	if (mess)
		ft_putstr_fd(mess, fd);
	ft_free_mini(minishell);
	exit(exnum);
}
