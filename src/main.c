/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:04:27 by mluik             #+#    #+#             */
/*   Updated: 2022/08/05 13:30:57 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_minishell	minishell;
	char		*command_buf;

	// minishell.envp = env;
	ft_env_create(env, &minishell);
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
