/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:04:27 by mluik             #+#    #+#             */
/*   Updated: 2022/10/15 11:49:27 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_print_intro(void);

volatile sig_atomic_t	g_shutdown_flag;

int	ft_actions(char *command_buf, t_minishell *minishell)
{
	add_history(command_buf);
	if (parse(command_buf, minishell) <= 2)
		refresh_data_parsing(minishell);
	else
	{
		init_executor_struct(minishell);
		if (ft_api_handler(minishell) == 2)
			refresh_data(minishell);
		else
		{
			execution_handler(minishell);
			refresh_data(minishell);
		}
	}
	return (0);
}

/* Displays the shell prompt. */
char	*ft_display(char *command_buf, t_minishell *minishell)
{
	if (g_shutdown_flag == 1 || g_shutdown_flag == 3)
	{
		if (g_shutdown_flag == 3)
		{
			minishell->exit_status = 130;
			g_shutdown_flag = 1;
		}
		ft_disable_signals();
		command_buf = readline("\033[0;34mminishell > \033[0m");
	}
	if (g_shutdown_flag == 2)
	{
		minishell->exit_status = 130;
		g_shutdown_flag = 1;
	}
	return (command_buf);
}

/* Main function for the minishell.
	Starting point for prompt, lexing, parsing, 
	and executing. */
int	main(int argc, char **argv, char **env)
{
	t_minishell			minishell;
	char				*command_buf;

	command_buf = NULL;
	if (argc != 1 || argv[1])
		return (1);
	ft_print_intro();
	minishell = initialize_minishell_struct();
	ft_env_create(env, &minishell);
	while (1)
	{
		ft_disable_signals();
		command_buf = ft_display(command_buf, &minishell);
		if (command_buf == 0)
		{
			ft_printf("exit\n");
			break ;
		}
		if (ft_strlen(command_buf) > 0)
			ft_actions(command_buf, &minishell);
	}
	if (minishell.envlist)
		minishell.envlist = ft_env_clear(minishell.envlist);
	return (0);
}

void	ft_print_intro(void)
{
	ft_putstr_fd("\033[0;32m", 1);
	ft_printf("\n");
	ft_printf("/* ******************************************************* */\n");
	ft_printf("/*                                                         */\n");
	ft_printf("/*                                     :::      ::::::::   */\n");
	ft_printf("/*  MINISHELL                        :+:      :+:    :+:   */\n");
	ft_printf("/*                                 +:+ +:+         +:+     */\n");
	ft_printf("/*     CREATED BY:               +#+  +:+       +#+        */\n");
	ft_printf("/*            mluik            +#+#+#+#+#+   +#+           */\n");
	ft_printf("/*               &                  #+#    #+#             */\n");
	ft_printf("/*             libacchu            ###   ########.fr       */\n");
	ft_printf("/*                                                         */\n");
	ft_printf("/* ******************************************************* */\n");
	ft_printf("\n");
}
