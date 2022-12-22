/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:56:31 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/03 11:00:15 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Finds last element in lexlist */
t_lexlist	*ft_findlast_lexlist(t_lexlist *lex)
{
	t_lexlist	*last;

	last = lex;
	while (last->next != NULL)
	{
		last = last->next;
	}
	return (last);
}

/* Finds last element in env list */
t_envlist	*ft_findlast_envlist(t_envlist *envlist)
{
	t_envlist	*last;

	last = envlist;
	while (last->next != NULL)
	{
		last = last->next;
	}
	return (last);
}
