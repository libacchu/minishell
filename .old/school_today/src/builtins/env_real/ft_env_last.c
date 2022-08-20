/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:56:31 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/19 14:16:27 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_envlist	*ft_env_last(t_envlist *env)
{
	t_envlist *tmp;
	
	tmp = env;
	while (tmp)
	{
		if (!tmp->next)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}
