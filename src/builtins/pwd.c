/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:53:07 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/31 15:26:03 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
** pwd – return working directory name
**		The pwd utility writes the absolute pathname of
**		the current working directory to the standard output. 
*/

// int	ft_pwd(char **env)
// {
// 	int		i;
// 	char	*pwd_info;

// 	i = 0;
// 	while (env[i])
// 	{
// 		if (strncmp(env[i][0], "PWD=/", 5) == 0)
// 		{
// 			pwd_info = (strchr(env[i], '/'));
// 			printf("%s\n", pwd_info);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int	ft_pwd(void)
{
	char	*pwd_info;

	pwd_info = getcwd(NULL, 1024);
	if (pwd_info == NULL)
		return (1);
	else
	{
		ft_putendl_fd(pwd_info, 1);
		free(pwd_info);
		return (0);
	}
}

// int main()
// {
// 	ft_pwd();
// 	return 0;
// }