/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:03:05 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/20 15:37:05 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
** cd — change the working directory
*/
int	ft_cd(char *new_dir, t_minishell *shell)
{
	char	*current_dir;
	char	*old_dir;

	old_dir = getcwd(NULL, PATH_MAX);
	if (old_dir == NULL)
		return (1);
	if (chdir(new_dir) == -1)
	{
		printf("Invalid path\n");
		return (1);
	}
	current_dir = getcwd(NULL, PATH_MAX);
	if (current_dir == NULL)
		return (1);
	else
	{
		ft_unset("OLDPWD", shell->envlist);
		ft_env_add_back((&shell->envlist), ft_env_new_node("OLDPWD", old_dir));
		ft_unset("PWD", shell->envlist);
		ft_env_add_back(&(shell->envlist), ft_env_new_node("PWD", current_dir));
	}
	return (0);
}
