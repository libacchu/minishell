/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:18:16 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/27 17:06:51 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	ft_pwd(char **env);

int	main(int argc, char **argv, char **env)
{
	int	i;

	i = 0;
	// while (env[i])
	// {
	// 	printf("%s\n", env[i]);
	// 	i++;
	// }
	ft_pwd(env);
	ft_cd(argv[1]);
	(void)argc;
	// (void)argv;
	return (0);
}

int	ft_pwd(char **env)
{
	int		i;
	char	*pwd_info;

	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], "PWD", 3) == 0)
		{
			pwd_info = (strchr(env[i], '/'));
			printf("%s\n", pwd_info);
		}
		i++;
	}
	return (0);
}

int	ft_cd(char *new_dir)
{
	char	*current_dir;

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
		printf("new = %s\n", current_dir);
	free(current_dir);
}
