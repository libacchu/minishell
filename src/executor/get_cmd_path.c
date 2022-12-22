/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 23:09:08 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/14 13:11:54 by libacchu         ###   ########.fr       */
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
	if (!cmd_path)
		return (NULL);
	paths = ft_free_substring(paths);
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
		if (ft_strcmp(env->variable, "PATH") == 0)
		{
			if (env->content)
				path = ft_strdup(env->content);
			else
				path = NULL;
			break ;
		}
		env = env->next;
	}
	if (env == NULL)
		return (NULL);
	cmd_paths = ft_split(path, ':');
	free(path);
	return (cmd_paths);
}

/* 
** search_magic() checks if the command is found.
		if not, it returns NULL.
 */
char	*search_magic(struct dirent **cmd, char *commands, \
	char *cmd_paths, DIR **dir)
{
	char	*tmp;
	char	*path;

	path = NULL;
	tmp = NULL;
	if (ft_strcmp((*cmd)->d_name, commands) == 0)
	{
		tmp = ft_strjoin(cmd_paths, "/");
		path = ft_strjoin(tmp, commands);
		free(tmp);
		closedir(*dir);
		return (path);
	}
	*cmd = readdir(*dir);
	return (NULL);
}

/* 
** search_dir_path() goes into the directories and searches for the command
 */
char	*search_dir_path(char **cmd_paths, char **commands)
{
	int				i;
	DIR				*dir;
	struct dirent	*cmd;
	char			*path;

	i = 0;
	path = NULL;
	while (cmd_paths[i])
	{	
		dir = opendir(cmd_paths[i]);
		if (dir == NULL)
			return (NULL);
		cmd = readdir(dir);
		while (cmd != NULL)
		{
			path = search_magic(&cmd, commands[0], cmd_paths[i], &dir);
			if (path)
				return (path);
		}
		closedir(dir);
		i++;
	}
	return (path);
}
