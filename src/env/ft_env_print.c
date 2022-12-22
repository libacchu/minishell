/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:49:02 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/14 18:12:07 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_env_print(t_envlist *env)
{
	if (!env)
		return (1);
	while (env)
	{
		if (env->variable)
			ft_putstr_fd(env->variable, 1);
		if (env->content)
		{
			ft_putchar_fd('=', 1);
			ft_putstr_fd(env->content, 1);
		}
		ft_putchar_fd('\n', 1);
		env = env->next;
	}
	return (0);
}
