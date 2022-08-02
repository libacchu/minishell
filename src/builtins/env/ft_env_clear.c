/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:04:53 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/02 21:18:04 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_free_null(char *variable, char *content)
{
	free(variable);
	variable = NULL;
	free(content);
	content = NULL;
}

void	ft_env_clear(t_envlist *env)
{
	t_envlist	*temp;

	if (!env)
		return ;
	while (env)
	{
		temp = env;
		ft_free_null(env->variable, env->content);
		free(env);
		env = temp->next;
	}
	env = NULL;
}
