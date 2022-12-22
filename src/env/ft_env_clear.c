/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:04:53 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/12 19:38:58 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_envlist	*ft_env_clear(t_envlist *env)
{
	t_envlist	*temp;

	if (!env)
		return (NULL);
	temp = NULL;
	while (env != NULL)
	{
		temp = env;
		env = env->next;
		ft_free_null(temp->variable, temp->content);
		free(temp);
	}
	return (env);
}
