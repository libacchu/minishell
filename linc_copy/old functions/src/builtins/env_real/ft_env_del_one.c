/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_del_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:15:54 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/02 21:19:04 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_env_del_one(t_envlist *env)
{
	if (!env)
		return ;
	ft_free_null(env->variable, env->content);
	free(env);
}
