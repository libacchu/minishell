/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:37:48 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/14 00:19:20 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_envlist	*ft_checkfornext_us(t_envlist *del_node, t_envlist *env)
{
	del_node = env->next;
	if (env->next->next)
		env->next = env->next->next;
	else
		env->next = NULL;
	del_node->next = NULL;
	ft_env_del_one(del_node);
	return (env);
}

t_envlist	*ft_checkforone_us(t_envlist *env, t_envlist *holder)
{
	env = env->next;
	ft_env_del_one(holder);
	return (env);
}

int	ft_unset(int ac, char *name, t_envlist *env)
{
	t_envlist	*del_node;
	t_envlist	*holder;

	if (ac == 1)
		return (0);
	holder = env;
	del_node = NULL;
	if (ft_strcmp(name, env->variable) == 0)
	{
		env = ft_checkforone_us(env, holder);
		return (0);
	}
	while (env && env->next)
	{
		if (ft_strcmp(name, env->next->variable) == 0)
		{
			env = ft_checkfornext_us(del_node, env);
			break ;
		}
		if (env->next)
			env = env->next;
	}
	env = holder;
	return (0);
}
