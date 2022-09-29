/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isbuiltin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 21:54:09 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/22 18:34:28 by mluik            ###   ########.fr       */
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
	// if (!ft_strcmp(cmd, "exit"))
	// 	return (TRUE);
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
	// ft_printf("----HERE----\n");
	if (ft_strcmp(args[0], "echo") == 0)
		ft_echo(size_of_arry(args), args);
	if (ft_strcmp(args[0], "pwd") == 0)
		ft_pwd();
	if (ft_strcmp(args[0], "env") == 0)
		ft_env_print(shell->envlist);
	if (ft_strcmp(args[0], "cd") == 0)
		ft_cd(args[1], shell);
	if (ft_strcmp(args[0], "export") == 0)
		ft_export(shell->envlist, args);
	if (ft_strcmp(args[0], "unset") == 0)
		ft_unset(args[1], shell->envlist);
	return (0);
}
