/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lexlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:41:10 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/11 10:53:41 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_free_lexlist(t_lexlist *lex)
{
	t_lexlist *tmp;
	
	while (lex)
	{
		tmp = lex->next;
		// free(lex->token);
		free(lex);
		lex = tmp;
	}
}
