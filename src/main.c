/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:04:27 by mluik             #+#    #+#             */
/*   Updated: 2022/07/31 20:20:28 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_minishell	minishell;
	char		*command_buf;

	env_create_lst(&minishell, env);
	while (1)
	{
		command_buf = readline("minishell> ");
		if (strlen(command_buf) > 0)
			add_history(command_buf);
		if (!strcmp(command_buf, "exit"))
			break ;
		ft_prog_handler(&minishell, command_buf);
		execute_cmd(&minishell, minishell.commands);
	}
	(void)argc;
	(void)argv;
	return (0);
}
