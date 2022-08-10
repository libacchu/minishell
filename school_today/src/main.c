/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:04:27 by mluik             #+#    #+#             */
/*   Updated: 2022/08/10 16:13:44 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* 	A checker for the env list: prints out env values as table.
	ft_printenvlist_checker(&minishell);
void	ft_printenvlist_checker(t_minishell *minishell)
{
	t_envlist	*nodeprint;

	nodeprint = minishell->envlist;
	while (nodeprint)
	{
		ft_printf("var:\t %s \t \t content:\t %s \n",
			nodeprint->variable,
			nodeprint->content);
		nodeprint = nodeprint->next;
	}
	minishell->envlist = NULL;
} */

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


/* Main function for the minishell.
	Starting point for prompt, lexing, parsing, 
	and executing. */
int	main(int argc, char **argv, char **env)
{
	t_minishell	minishell;
	char		*command_buf;

	if (argc != 1 || argv[1])
		return (1);
	ft_print_into();
	minishell = initialize_minishell_struct();
	ft_env_create(env, &minishell);
	while (1)
	{
		command_buf = readline("minishell> ");
		if (strlen(command_buf) > 0)
			add_history(command_buf);
		if (!strcmp(command_buf, "exit"))
			break ;
		parse(command_buf, &minishell);
		execution_handler(&minishell);
		
	}
	return (0);
}
