/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_pipe_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:01:59 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/21 18:39:26 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
**	ft_nbr_of_cmds()
**		counts all the pipes given in the lexlist.
*/
int	ft_nbr_of_cmds(t_lexlist *tokenlist)
{
	t_lexlist	*tmp;
	int			count;

	tmp = tokenlist;
	count = 1;
	while (tmp)
	{
		if (tmp->token_category == CAT_PIP)
			count++;
		tmp = tmp->next;
	}
	return (count);
}