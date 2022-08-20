/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_t_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:29:17 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/20 15:30:14 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*	For testing purposes */
int print_t_list(t_list *list)
{
	t_list *tmp;
	
	tmp = list;
	while (tmp)
	{
		print_arr(tmp->content);
		tmp = tmp->next;
	}
	return (0);
}