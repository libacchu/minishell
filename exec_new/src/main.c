/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:04:27 by mluik             #+#    #+#             */
/*   Updated: 2022/08/29 13:46:51 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void ft_print_intro(void);

/* Main function for the minishell.
	Starting point for prompt, lexing, parsing, 
	and executing. */
int	main(int argc, char **argv, char **env)
{
	t_minishell	minishell;
	char		*command_buf;

	if (argc != 1 || argv[1])
		return (1);
	ft_print_intro();
	minishell = initialize_minishell_struct();
	ft_env_create(env, &minishell);
	while (1)
	{
		command_buf = readline("\033[0;34mminishell > \033[0m");
		if (ft_strlen(command_buf) > 0)
		{
			add_history(command_buf);
		}
		if (!strcmp(command_buf, "exit"))
			ft_exit(NULL, &minishell) ;
		parse(command_buf, &minishell);
		execution_handler(&minishell);
		// free(command_buf);
		// command_buf = NULL;
	}
	return (0);
}

void ft_print_intro(void)
{
	ft_putstr_fd("\033[0;32m", 1);
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
