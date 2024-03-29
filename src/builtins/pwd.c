/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:53:07 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/20 15:38:00 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
** pwd – return working directory name
**		The pwd utility writes the absolute pathname of
**		the current working directory to the standard output. 
*/
int	ft_pwd(void)
{
	char	*pwd_info;

	pwd_info = getcwd(NULL, PATH_MAX);
	if (pwd_info == NULL)
		return (1);
	else
	{
		ft_putendl_fd(pwd_info, 1);
		free(pwd_info);
		return (0);
	}
}
