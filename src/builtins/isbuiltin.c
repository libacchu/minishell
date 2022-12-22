/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isbuiltin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 21:54:09 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/14 19:08:41 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#define TRUE 1
#define FALSE 0

/*
**	is_builtin_cmd() - checks if the command is builting command
						required by the subject.
**	RETURN=	a boolean value.
			TRUE (1) if the command is required
			FALSE (0) if the command is not required
*/
int	is_builtin_cmd(char **cmd)
{
	if (cmd == NULL)
		return (2);
	if (ft_strcmp(cmd[0], "echo") == 0)
		return (TRUE);
	if (ft_strcmp(cmd[0], "cd") == 0)
		return (TRUE);
	if (ft_strcmp(cmd[0], "pwd") == 0)
		return (TRUE);
	if (ft_strcmp(cmd[0], "export") == 0)
		return (TRUE);
	if (ft_strcmp(cmd[0], "env") == 0)
		return (TRUE);
	if (!ft_strcmp(cmd[0], "unset"))
		return (TRUE);
	if (!ft_strcmp(cmd[0], "exit"))
		return (TRUE);
	return (FALSE);
}

int	size_of_arry(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	exe_builtin(t_minishell *shell, char **args)
{
	int	flag;

	flag = 0;
	ft_handle_signals(shell);
	if (args == NULL)
		return (up_exit(0, shell));
	if (ft_strcmp(args[0], "echo") == 0)
		flag = ft_echo(size_of_arry(args), args);
	if (ft_strcmp(args[0], "pwd") == 0)
		flag = ft_pwd();
	if (ft_strcmp(args[0], "env") == 0)
		flag = ft_env_print(shell->envlist);
	if (ft_strcmp(args[0], "cd") == 0)
		flag = ft_cd(size_of_arry(args), args[1], shell);
	if (ft_strcmp(args[0], "export") == 0)
		flag = ft_export(shell->envlist, args, shell);
	if (ft_strcmp(args[0], "unset") == 0)
		flag = ft_unset(size_of_arry(args), args[1], shell->envlist);
	if (ft_strcmp(args[0], "exit") == 0)
		flag = ft_exit_cmd(size_of_arry(args), args, shell);
	return (up_exit(flag, shell));
}
