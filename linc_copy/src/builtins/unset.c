/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:37:48 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/20 16:21:47 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_unset(char *name, t_envlist *env)
{
	t_envlist	*del_node;
	t_envlist	*holder;

	holder = env;
	del_node = NULL;
	if (ft_strcmp(name, env->variable) == 0)
	{
		env = env->next;
		ft_env_del_one(holder);
		return (0);
	}
	while (env && env->next)
	{
		if (ft_strcmp(name, env->next->variable) == 0)
		{
			del_node = env->next;
			if (env->next->next)
				env->next = env->next->next;
			else
				env->next = NULL;
			del_node->next = NULL;
			ft_env_del_one(del_node);
			break ;
		}
		if (env->next)
			env = env->next;
	}
	env = holder;
	return (0);
}
