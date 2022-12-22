/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:33:09 by mluik             #+#    #+#             */
/*   Updated: 2022/10/15 13:31:34 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exit_w_error(char *message)
{
	ft_putstr_fd(message, 1);
	exit(0);
}

/* A variation of the up_exit command, which
	also prints an error message. */
int	up_exit_too(int exnum, t_minishell *shell, int code)
{
	shell->exit_status = exnum;
	if (code == 1)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(": syntax error near unexpected token `", STDERR_FILENO);
		ft_putchar_fd('|', STDERR_FILENO);
		ft_putstr_fd("'\n", STDERR_FILENO);
	}
	return (exnum);
}

int	ft_edgecase_p(char *string)
{
	int	i;

	i = 0;
	if (string[i] == '!' && (string[i + 1] == ' ' \
		|| string[i + 1] == '\n' || string[i + 1] == '\0'))
		return (1);
	else
		return (0);
}

int	ft_entry_quote_err(int charcount, int specialcharcount, char *string)
{
	while (string[charcount] && string[charcount] != '\0')
	{
		if (string[charcount] == '"' || string[charcount] == '\'')
			specialcharcount++;
		if (string[charcount] == '"')
		{
			charcount++;
			while (string[charcount] != '"' && string[charcount] != '\0')
				charcount++;
			if (string[charcount] == '"')
				specialcharcount++;
		}
		if (string[charcount] == '\'')
		{
			charcount++;
			while (string[charcount] != '\'' && string[charcount] != '\0')
				charcount++;
			if (string[charcount] == '\'')
				specialcharcount++;
		}
		if (string[charcount] != '\0')
			charcount++;
	}
	return (specialcharcount);
}

/* 	Checks if the entered string has any not-closed single or double quotes. 
	If it does, string will not be parsed, and an error message will be 
	displayed. */
int	ft_checkifeligible(char *string)
{
	int	charcount;
	int	specialcharcount;

	charcount = 0;
	specialcharcount = 0;
	specialcharcount = ft_entry_quote_err(charcount, specialcharcount, string);
	if ((specialcharcount % 2) == 0)
		return (0);
	else
	{
		ft_printf("Please check your quoutes for closing\n");
		return (1);
	}
}
