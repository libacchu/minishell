/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_library.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 22:51:02 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/10 16:31:02 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**get_dir_path(t_envlist *env)
{
	char	*path;
	char	**cmd_paths;

	path = NULL;
	while (env)
	{
		if (strncmp(env->variable, "PATH", 4) == 0)
		{
			path = ft_strdup(env->content);
			break ;
		}
		env = env->next;
	}
	cmd_paths = ft_split(path, ':');
	free(path);
	return (cmd_paths);
}

char	*search_dir_path(char **cmd_paths, char **commands)
{
	int				i;
	DIR				*dir;
	struct dirent	*cmd;
	char			*path;

	i = 0;
	while (cmd_paths[i])
	{	
		dir = opendir(cmd_paths[i]);
		if (dir == NULL)
			return (NULL);
		cmd = readdir(dir);
		while (cmd != NULL)
		{
			if (strcmp(cmd->d_name, commands[0]) == 0)
			{
				path = ft_strjoin(cmd_paths[i], "/");
				path = ft_strjoin(path, commands[0]);
			}
			cmd = readdir(dir);
		}
		closedir(dir);
		i++;
	}
	return (path);
}

int	exe_lib(t_minishell *shell)
{
	char	**cmd_paths;
	char	*cmd;
	
	shell->executor->env = ft_env_to_array(shell->envlist);
	// print_arr(shell->executor->env);
	cmd_paths = get_dir_path(shell->envlist);
	
	cmd = search_dir_path(cmd_paths, shell->executor->argv->content);
	// ft_printf("cmd = %s, content = %p, env = %s\n", cmd, (shell->executor->argv->content), shell->executor->env[0]);
	// execve(cmd, shell->executor->argv->content, shell->executor->env);
	execve(cmd, shell->executor->argv->content, shell->executor->env);
	return (0);
}
