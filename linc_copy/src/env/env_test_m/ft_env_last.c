/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:56:31 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/05 18:12:48 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_envlist	*ft_findlast_envlist(t_envlist *envlist)
{
	t_envlist	*last;

	last = NULL;
	while (envlist)
	{
		last = envlist;
		envlist = envlist->next;
	}
	return (last);
}
