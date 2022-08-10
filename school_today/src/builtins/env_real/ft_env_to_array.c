/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 06:57:45 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/10 16:30:32 by libacchu         ###   ########.fr       */
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
	while (i < len && env)
	{
		tmp = ft_calloc(sizeof(char),
			(ft_strlen(env->variable) + ft_strlen(env->content) + 2));
		tmp = ft_strjoin(env->variable, "=");
		res[i] = ft_strjoin(tmp, env->content);
		free(tmp);
		i++;
		env = env->next;
	}
	return(res);
}
