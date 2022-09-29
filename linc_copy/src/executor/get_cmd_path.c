/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 23:09:08 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/23 15:51:44 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**get_dir_path(t_envlist *env);
char	*search_dir_path(char **cmd_paths, char **commands);

/*
**	get_cmd_path() uses the PATH variable in the env and searches
		the directories separated by ':' for the command.
**	RETURN: if successful, 	get_cmd_path() returns the path to the command's
		directory, if not found it returns NULL. 
*/
char	*get_cmd_path(t_envlist *env, char **cmd)
{
	char	**paths;
	char	*cmd_path;

	paths = get_dir_path(env);
	if (!paths)
		return (NULL);
	cmd_path = search_dir_path(paths, cmd);
	// printf(" path after filter: %s \n", cmd_path);
	if (!cmd_path)
		return (NULL);
	ft_free_substring(paths);
	return (cmd_path);
}

/*
**	get_dir_path() uses env and looks for the PATH variable
*/
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
	if (env == NULL)
		return (NULL);
	cmd_paths = ft_split(path, ':');
	// print_arr(cmd_paths);
	free(path);
	return (cmd_paths);
}

char	*search_dir_path(char **cmd_paths, char **commands)
{
	int				i;
	DIR				*dir;
	struct dirent	*cmd;
	char			*path;
	char			*tmp;

	i = 0;
	path = NULL;
	tmp = NULL;
	while (cmd_paths[i])
	{	
		dir = opendir(cmd_paths[i]);
		if (dir == NULL)
			return (NULL);
		cmd = readdir(dir);
		while (cmd != NULL)
		{
			if (ft_strcmp(cmd->d_name, commands[0]) == 0)
			{
				tmp = ft_strjoin(cmd_paths[i], "/");
				path = ft_strjoin(tmp, commands[0]);
				free(tmp);
				closedir(dir);
				return (path);
			}
			cmd = readdir(dir);
		}
		closedir(dir);
		i++;
	}
	return (path);
}
