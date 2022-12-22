/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_exec_02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:38:50 by mluik             #+#    #+#             */
/*   Updated: 2022/10/12 19:39:30 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_string(char *str)
{
	str = NULL;
	free(str);
}

void	ft_free_args(char **substring, int count)
{
	int	i;

	i = 0;
	while (i <= count)
	{
		free(substring[i]);
		i++;
	}
	free(substring);
}
