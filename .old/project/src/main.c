/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:04:27 by mluik             #+#    #+#             */
/*   Updated: 2022/08/06 16:26:25 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void ft_print_into(void)
{
	ft_printf("\n");
	ft_printf("/* ********************************************************************* */\n");
	ft_printf("/*                                                                       */\n");
	ft_printf("/*                                                   :::      ::::::::   */\n");
	ft_printf("/*      MINISHELL                                  :+:      :+:    :+:   */\n");
	ft_printf("/*                                               +:+ +:+         +:+     */\n");
	ft_printf("/*          CREATED BY:                        +#+  +:+       +#+        */\n");
	ft_printf("/*                     mluik                 +#+#+#+#+#+   +#+           */\n");
	ft_printf("/*                          &                     #+#    #+#             */\n");
	ft_printf("/*                           libacchu            ###   ########.fr       */\n");
	ft_printf("/*                                                                       */\n");
	ft_printf("/* ********************************************************************* */\n");
	ft_printf("\n");
}

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
