/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 09:18:07 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/22 15:46:57 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"



int	check_for_valid _redirect(const char *redirect, int category)
{
	if (category == CAT_REDIR_L)
	{
		if (access(redirect, F_OK | R_OK | X_OK) != NULL)
			return (1);
	}
	if (category == CAT_REDIR_R || category == CAT_REDIR_RR)
	{
		if (access(redirect, F_OK | W_OK | X_OK) != NULL)
			return (1)
	}
	return (0)
}
