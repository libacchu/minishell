/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:33:09 by mluik             #+#    #+#             */
/*   Updated: 2022/08/05 16:36:41 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exit_w_error(char *message)
{
	ft_putstr_fd(message, 1);
	exit(0);
}

/* 	Checks if the entered string has any not-closed single or double strings. 
	If it does, string will not be parsed. will be rewritten later to 
	SAVE EXIT as separate command for EXEC phase; */
void	ft_checkifeligible(char *string)
{
	int	charcount;
	int	specialcharcount;

	charcount = 0;
	specialcharcount = 0;
	while (string[charcount] != '\0')
	{
		if (string[charcount] == '"' || string[charcount] == '\'')
			specialcharcount++;
		charcount++;
	}
	if ((specialcharcount % 2) == 0)
		return ;
	else
		exit_w_error("Wrong input\n");
}
