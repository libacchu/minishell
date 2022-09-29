/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_minishell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:39:45 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/26 09:04:25 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_free_minishell(t_minishell *shell)
{
	refresh_data(shell);
	if (shell->envlist)
		ft_env_clear(shell->envlist);
	return (0);
}
