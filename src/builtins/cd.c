/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:03:05 by libacchu          #+#    #+#             */
/*   Updated: 2022/12/22 20:30:46 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	cd_magic(t_minishell *shell, char *current_dir, char *old_dir)
{
	ft_unset(2, "OLDPWD", shell->envlist);
	ft_env_add_back((&shell->envlist), \
		ft_create_env_node(ft_strdup("OLDPWD"), ft_strdup(old_dir)));
	ft_unset(2, "PWD", shell->envlist);
	ft_env_add_back(&(shell->envlist), \
		ft_create_env_node(ft_strdup("PWD"), ft_strdup(current_dir)));
}

/*
** cd — change the working directory
*/
int	ft_cd(int ac, char *new_dir, t_minishell *shell)
{
	char	*current_dir;
	char	*old_dir;

	if (ac <= 1)
		return (0);
	if (ac > 2)
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return (1);
	}
	old_dir = getcwd(NULL, PATH_MAX);
	if (old_dir == NULL)
		return (1);
	if (chdir(new_dir) == -1)
	{
		print_no_such_file_directory(new_dir);
		return (1);
	}
	current_dir = getcwd(NULL, PATH_MAX);
	if (current_dir == NULL)
		return (1);
	else
		cd_magic(shell, current_dir, old_dir);
	free(current_dir);
	free(old_dir);
	return (0);
}
