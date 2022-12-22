/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:52:21 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/28 14:04:15 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_env_add_back(t_envlist **env, t_envlist *new)
{
	if (!env || !new)
		return ;
	if (*env == NULL)
		*env = new;
	else
		ft_findlast_envlist(*env)->next = new;
}
