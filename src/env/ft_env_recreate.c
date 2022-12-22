/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_recreate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:47:38 by mluik             #+#    #+#             */
/*   Updated: 2022/10/02 20:08:46 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Recreates the env list for the EXPORT builtin
	after it has been reordered alphabetically.
*/
t_envlist	*ft_recreate_env(char **env, t_envlist *list)
{
	int			i;
	char		*var;
	char		*content;

	i = 0;
	list = NULL;
	while (env && env[i] && env[0])
	{
		var = ft_get_variable(env[i]);
		content = ft_get_content(env[i]);
		ft_env_add_back(&list, ft_create_env_node(var, content));
		i++;
	}
	return (list);
}
