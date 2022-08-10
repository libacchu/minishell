/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:03:05 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/01 14:07:31 by libacchu         ###   ########.fr       */
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

	(void) shell;
	old_dir = getcwd(NULL, 1);
	if (old_dir == NULL)
	{
		// free(current_dir);
		return (1);
	}
	else
	{
		printf("old = %s\n", old_dir);
		change_env_dir(old_dir, shell, "OLDPWD=");
	}
	if (chdir(new_dir) == -1)
	{
		printf("Invalid path\n");
	}
	current_dir = getcwd(NULL, 1);
	if (current_dir == NULL)
	{
		free(current_dir);
		return (1);
	}
	else
	{
		printf("new = %s\n", current_dir);
		change_env_dir(current_dir, shell, "PWD=");
	}
	free(current_dir);
	free(old_dir);
	return (0);
}

int	change_env_dir(char *dir, t_minishell *shell, char *search)
{
	char	*tmp1;
	t_list	*head;
	t_list	*tmp;

	tmp1 = ft_strjoin(search, dir);
	tmp = ft_lstnew(tmp1);
	head = shell->env;
	ft_printf("search = %s\n",search);
	while (shell->env)
	{
		if (ft_strncmp(shell->env->content, search, ft_strlen(search)) == 0)
		{
			ft_lstadd_back(&shell->env, tmp);
			
			
			
			// ft_printf("cmp %s, %s\n", shell->env->content, search);
			// shell->env->content = tmp;
			// ft_printf("after %s\n", shell->env->content);
			// free(tmp);
			break ;
		}
		shell->env = shell->env->next;
	}
	shell->env = head;
	return (0);
}
