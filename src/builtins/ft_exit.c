/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:43:01 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/15 10:24:15 by libacchu         ###   ########.fr       */
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

void	ft_exit(char *mess, t_minishell *minishell, int exnum)
{
	if (mess)
		ft_putstr_fd(mess, 1);
	ft_free_minishell(minishell);
	exit(exnum);
}

int	is_str_only_num(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (ft_isdigit(str[i]) == 0)
			return (1);
	return (0);
}

int	ft_exit_cmd(int ac, char **argv, t_minishell *shell)
{
	int	exnum;

	exnum = 0;
	if (ac > 1)
	{
		if (is_str_only_num(argv[1]))
		{
			ft_putstr_fd("numeric argument required\n", 2);
			ft_exit(NULL, shell, 2);
		}
		else
			exnum = ft_atoi(argv[1]);
	}
	if (ac > 2)
	{
		ft_putstr_fd("too many arguments\n", 2);
		return (up_exit(1, shell));
	}
	else
		ft_exit(NULL, shell, exnum);
	return (up_exit(2, shell));
}
