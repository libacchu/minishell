/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exector.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:41:49 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/29 14:35:48 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../libft/libft.h"

	// printf("cmd = %s\n", cmd);
	// printf("argv = %s\n", argv[2]);

// int	use_builtins(char *cmd, char **argv, char **env)
// {
	
// 	if (ft_strcmp(cmd, "echo"))
// 		ft_echo()
// }

// int	get_search_path(char *path)
// {
	
// }

// int	search_dir(char *name, char *path)
// {
// 	DIR	dir_path;

// 	dir_path = opendir(path);
// 	if (dir_path == NULL)
// 		return (1);
// }

// int	exector(char *cmd, char **argv, char **env)
// {
// 	// argv[0] ls
// 	// argv[1] -la
// 	if (ft_strcmp(cmd, "echo"))
// 	// 	use_builtins(cmd, argv, env);
// 	if (execve(cmd, &argv[2], env) == -1)
// 		perror("Command not executed\n");
// 	return (0);
// }
void	ft_free_substring(char **substring)
{
	int	i;

	i = 0;
	while (substring[i])
	{
		free(substring[i]);
		substring[i] = NULL;
		i++;
	}
	free(substring);
	substring = NULL;
}


char	**get_dir_path(char **env)
{
	int		i;
	char	*path;
	char	*tmp;
	char	**cmd_paths;

	i = 0;
	tmp = NULL;
	while (env[i])
	{
		if (strncmp(env[i], "PATH=/", 6) == 0)
		{
			tmp = ft_strdup(env[i]);
			break ;
		}
		i++;
	}
	path = ft_strtrim(tmp, "PATH=");
	cmd_paths = ft_split(path, ':');
	free(tmp);
	free(path);
	return (cmd_paths);
}

int	main(int ac, char **av, char **env)
{
	// char	*cmd;
	char	**option;
	int	i;

	(void)ac;
	(void)av;
	option = get_dir_path(env);
	i = 0;
	while (option[i])
	{
		printf("%s\n", option[i]);
		i++;
	}
	ft_free_substring(option);
	// cmd = av[1];
	// exector(cmd, option, env);
	return (0);
}
