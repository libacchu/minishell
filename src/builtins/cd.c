/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:03:05 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/29 13:26:19 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
** cd — change the working directory
*/

int	ft_cd(char *new_dir)
{
	char	*current_dir;

	current_dir = getcwd(NULL, 1);
	if (current_dir == NULL)
	{
		free(current_dir);
		return (1);
	}
	else
		printf("current = %s\n\n", current_dir);
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
	return (0);
}
