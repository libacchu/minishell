/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_minishell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:39:45 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/03 11:51:03 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_free_minishell(t_minishell *shell)
{
	refresh_data(shell);
	if (shell->envlist)
		shell->envlist = ft_env_clear(shell->envlist);
	return (0);
}
