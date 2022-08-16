/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isbuiltin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 21:54:09 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/10 16:23:37 by libacchu         ###   ########.fr       */
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
int	is_builtin_cmd(char *cmd)
{
	// if (!ft_strcmp(cmd, "echo"))
	// 	return (TRUE);
	// if (!ft_strcmp(cmd, "cd"))
	// 	return (TRUE);
	if (!ft_strcmp(cmd, "pwd"))
		return (TRUE);
	if (!ft_strcmp(cmd, "export"))
		return (TRUE);
	if (!ft_strcmp(cmd, "env"))
		return (TRUE);
	// if (!ft_strcmp(cmd, "unset"))
	// 	return (TRUE);
	// if (!ft_strcmp(cmd, "exit"))
	// 	return (TRUE);
	return (FALSE);
}

// int	size_of_arry(char **arr)
// {
// 	int	i;

// 	i = 0;
// 	while (arr[i])
// 		i++;
// 	return (i);
// }

int	exe_builtin(t_minishell *shell, char **args)
{
	(void)shell;
	// if (!ft_strcmp(args[0], "echo"))
	// 	ft_echo(size_of_arry(args), args);
	if (!ft_strcmp(args[0], "pwd"))
		ft_pwd();
	if (!ft_strcmp(args[0], "env"))
		ft_env_print(shell->envlist);
	// if (!ft_strcmp(args[0], "cd"))
	// 	ft_cd(args[1], shell);
	if (!ft_strcmp(args[0], "export"))
		ft_export(shell->envlist, args);
	return (0);
}