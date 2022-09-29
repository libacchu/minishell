/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:22:25 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/06 18:02:42 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../include/minishell.h"
#include "../../libft/libft.h"

int	ft_print_arr(int ac, char **arr, int i);
/*
** echo:
**		– write arguments to the standard output
** -n:
**		Do not print the trailing newline character.
** EXIT STATUS
**    	 The echo utility exits 0 on success, and >0 if an error occurs.
*/

int	ft_echo(int ac, char **av)
{
	int		i;
	char	nl;

	i = 1;
	nl = '\n';
	if (av[i])
	{
		if (!ft_strcmp("-n", av[i]))
		{
			nl = '\0';
			ft_print_arr(ac, av, i + 1);
		}
		else
			ft_print_arr(ac, av, i);
	}
	if (nl == '\n')
		ft_putchar_fd(nl, 1);
	return (0);
}

int	ft_print_arr(int ac, char **arr, int i)
{
	int	j;

	while (i < ac)
	{
		j = 0;
		while (arr[i][j])
		{
			ft_putchar_fd(arr[i][j], 1);
			j++;
		}
		if (arr[i][j] == '\0' && (i + 1) < ac)
			ft_putchar_fd(' ', 1);
		i++;
	}
	return (0);
}
