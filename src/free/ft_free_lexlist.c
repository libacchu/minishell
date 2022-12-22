/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lexlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:41:10 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/03 11:15:59 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Frees any t_lexlist structs and it's elements */
t_lexlist	*ft_free_lexlist(t_lexlist *lex)
{
	t_lexlist	*tmp;

	tmp = NULL;
	while (lex != NULL)
	{
		tmp = lex;
		lex = lex->next;
		free(tmp->token);
		free(tmp);
	}
	return (lex);
}
