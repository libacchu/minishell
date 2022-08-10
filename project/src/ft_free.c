/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:52:14 by mluik             #+#    #+#             */
/*   Updated: 2022/07/22 10:08:43 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_free_substring(char **substring)
{
	int	i;

	i = 0;
	while (substring[i])
	{
		free(substring[i]);
		substring[i] = NULL;
		i++;
	}
	free(substring);
	substring = NULL;
}
