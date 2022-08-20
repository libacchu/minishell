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
	t_envlist *tmp;
	t_envlist *unset;
	
	tmp = env;
	while (env)
	{
		if (name == env->next->variable)
		{
			unset = env->next;
			env->next = env->next->next;
			unset->next = NULL;
			ft_env_del_one(unset);
		}
		env = env->next;
	}
	env = tmp;
	return (0);
}
