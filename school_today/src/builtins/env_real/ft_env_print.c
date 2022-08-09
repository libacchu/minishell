/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:49:02 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/07 07:51:42 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_env_print(t_envlist *env)
{
	if (!env)
		return (1);
	while (env)
	{
		ft_putstr_fd(env->variable, 1);
		ft_putchar_fd('=', 1);
		ft_putendl_fd(env->content, 1);
		env = env->next;
	}
	return (0);
}
