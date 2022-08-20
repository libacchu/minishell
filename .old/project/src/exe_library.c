/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_library.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 22:51:02 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/02 20:33:29 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**get_dir_path(t_list *env)
{
	char	*path;
	char	*tmp;
	char	**cmd_paths;

	tmp = 0;
	while (env)
	{
		if (strncmp(env->content, "PATH=/", 6) == 0)
		{
			tmp = ft_strdup(env->content);
			break ;
		}
		env = env->next;
	}
	path = ft_strtrim(tmp, "PATH=");
	cmd_paths = ft_split(path, ':');
	free(tmp);
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

	cmd_paths = get_dir_path(shell->env);
	cmd = search_dir_path(cmd_paths, shell->commands);
	execve(cmd, shell->commands, NULL);
	return (0);
}
