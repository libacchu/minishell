/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 06:57:45 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/23 15:20:40 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	**ft_env_to_array(t_envlist *env)
{
	int		len;
	char	**res;
	int		i;
	char	*tmp;

	len = ft_env_len(env);
	res = ft_calloc(sizeof(char *), (len + 1));
	i = 0;
	tmp = NULL;
	while (i < len && env)
	{
		tmp = ft_strjoin(env->variable, "=");
		res[i] = ft_strjoin(tmp, env->content);
		i++;
		env = env->next;
		free(tmp);
	}
	return (res);
}
