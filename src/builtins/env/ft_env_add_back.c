/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:52:21 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/02 18:56:08 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_env_add_back(t_envlist **env, t_envlist *new)
{
	if (!env || !new)
		return ;
	if (*env == NULL)
		*env = new;
	else
		ft_env_last(*env)->next = new;
}