/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:53:07 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/29 13:41:19 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
** pwd – return working directory name
**		The pwd utility writes the absolute pathname of
**		the current working directory to the standard output. 
*/

int	ft_pwd(char **env)
{
	int		i;
	char	*pwd_info;

	i = 0;
	while (env[i])
	{
		if (strncmp(env[i][0], "PWD=/", 5) == 0)
		{
			pwd_info = (strchr(env[i], '/'));
			printf("%s\n", pwd_info);
		}
		i++;
	}
	return (0);
}
