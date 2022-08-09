/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:56:31 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/05 17:06:51 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_envlist	*ft_env_last(t_envlist **env)
{
	t_envlist *tmp;
	
	tmp = *env;
	while (tmp && tmp->next)
	{
		printf("--last-\n");
		// if (!tmp->next)
		// 	return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}
