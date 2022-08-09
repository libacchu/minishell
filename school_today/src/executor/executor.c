/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:41:49 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/09 17:51:55 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* for testing purposes */
void print_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		ft_printf("%s ", arr[i]);
}

/* duplicates the Standard in/output to restore after execution */
int dup_std_in_out(t_executor *executor)
{
	executor->tmpin = dup(STDIN_FILENO);
	executor->tmpout = dup(STDOUT_FILENO);
	return (0);
}

/* */
int	input_redirect(t_executor *executor)
{
	if (executor->infile)
		executor->fdin = open(executor->infile, O_RDONLY);
	else
		executor->fdin = dup(executor->tmpin);
	return (0);
}

int	exe_cmd(t_minishell *shell)
{
	int	id;

	id = fork();
	if (id == 0)
		exe_lib(shell);
	return (0);
}

/* calls all the necessary functions for execution */
int	execution_handler(t_minishell *shell)
{
	shell->executor->nbr_of_cmds = nbr_of_cmds(shell->tokenlist);
	ft_printf("-----HERE-----\n");
	convert_to_argv(shell);
	// dup_std_in_out(shell->executor);
	// input_redirect(shell->executor);
	// if (is_builtin_cmd(shell->executor->args[0]))
	// {
	// 	exe_builtin(shell, shell->executor->args);
	// }
	// else
	// {
	// 	exe_cmd(shell);
	// }
	return (0);
}

	// int len;
	
	// print_arr(shell->executor->args);
	// len = lex_length(shell->tokenlist);
	// ft_printf("number of command = %d\n", len);

// int	main(int ac, char **av)
// {
// 	char	*cmd;
// 	char	**option;
// 	char	**env;

// 	(void)ac;
// 	cmd = av[1];
// 	option = av;
// 	env = NULL;
// 	exector(cmd, option, env);
// 	return (0);
// }

	// if (ft_strcmp(cmd, "echo"))
	// 	use_builtins(cmd, argv, env);
	// if (execve(cmd, &argv[2], env) == -1)
	// 	perror("Command not executed\n");