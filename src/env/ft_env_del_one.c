/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_del_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:15:54 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/13 11:25:29 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_null(char *variable, char *content)
{
	if (variable)
		free(variable);
	if (content)
		free(content);
}

void	ft_env_del_one(t_envlist *env)
{
	if (!env)
		return ;
	ft_free_null(env->variable, env->content);
	free(env);
}
