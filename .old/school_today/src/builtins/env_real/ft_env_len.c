/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:04:28 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/04 10:17:45 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_env_len(t_envlist *env_struct)
{
	t_envlist	*tmp;
	int			len;

	tmp = env_struct;
	len = 0;
	while (env_struct)
	{
		env_struct = env_struct->next;
		len++;
	}
	env_struct = tmp;
	return (len);
}
