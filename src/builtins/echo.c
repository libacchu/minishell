/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:22:25 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/15 12:52:32 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../libft/libft.h"

int	ft_print_arr(int ac, char **arr, int i);
int	scan_option(char **av, int i, int j);
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
	int		j;

	i = 1;
	j = 2;
	nl = '\n';
	if (av[i])
	{
		while (i < ac && !ft_strncmp("-n", av[i], 2) && scan_option(av, i, j))
		{
			nl = '\0';
			i++;
		}
		ft_print_arr(ac, av, i);
	}
	if (nl == '\n')
		ft_putchar_fd(nl, 1);
	return (0);
}

int	scan_option(char **av, int i, int j)
{
	while (av[i][j])
	{
		if (av[i][j] == 'n')
			j++;
		else
			return (0);
	}
	return (1);
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
