/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:03:05 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/16 14:35:06 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	change_env_dir(char *dir, t_minishell *shell, char *search);

/*
** cd — change the working directory
*/

int	ft_cd(char *new_dir, t_minishell *shell)
{
	char	*current_dir;
	char	*old_dir;
	
	// printf("new_dir = %s\n", new_dir);
	// ft_printf("----ft_cd----\n");
	old_dir = getcwd(NULL, 1);
	if (old_dir == NULL)
		return (1);
	else
	{
		// printf("old = %s\n", old_dir);
		change_env_dir(old_dir, shell, "OLDPWD");
	}
	if (chdir(new_dir) == -1)
		printf("Invalid path\n");
	current_dir = getcwd(NULL, 1);
	if (current_dir == NULL)
	{
		return (1);
	}
	else
	{
		// printf("current dir = %s\n", current_dir);
		change_env_dir(current_dir, shell, "PWD");
	}
	free(current_dir);
	free(old_dir);
	return (0);
}

int	change_env_dir(char *dir, t_minishell *shell, char *search)
{
	// char		*tmp1;
	// t_envlist	*head;
	t_envlist	*tmp;

	tmp = ft_env_new_node(search, dir);
	// ft_printf("tmp var = %s\n", tmp->variable);
	// ft_printf("tmp con = %s\n", tmp->content);
	ft_env_add_back(&shell->envlist, tmp);
	// head = shell->envlist;
	// while (shell->envlist)
	// {
	// 	if (ft_strncmp(shell->envlist->variable, search, ft_strlen(search)) == 0)
	// 	{
	// 		break ;
	// 	}
	// 	shell->envlist = shell->envlist->next;
	// }
	// shell->envlist = head;
	return (0);
}
