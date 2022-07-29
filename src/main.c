/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:04:27 by mluik             #+#    #+#             */
/*   Updated: 2022/07/28 11:35:38 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_minishell	minishell;
	char		*command_buf;
	// t_minishell = (t_minishell){}};
	// IMPORT ENV!!! Will stay in the main = bottom of stack; and will be removed when the program is eliminated
	while (1)
	{
		command_buf = readline("minishell> ");
		if (strlen(command_buf) > 0)
			add_history(command_buf);
		if (!strcmp(command_buf, "exit"))
			break ;
		parse(command_buf, &minishell);
	/* 		executor(...); */
	}
	return (0);
}
