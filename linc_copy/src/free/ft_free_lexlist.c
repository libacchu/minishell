/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lexlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:41:10 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/22 14:04:52 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Frees any t_lexlist structs and it's elements */
void	ft_free_lexlist(t_lexlist *lex)
{
	t_lexlist	*tmp;

	tmp = NULL;
	while (lex)
	{
		tmp = lex->next;
		free(lex->token);
		free(lex);
		lex = tmp;
		if (lex == NULL)
			break ;
	}
}
