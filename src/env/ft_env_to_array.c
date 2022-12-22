/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 06:57:45 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/13 19:42:06 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* The len = i[0] 
	i = i[1] */
char	**ft_env_to_array(t_envlist *env)
{
	char		**res;
	int			i[2];
	char		*tmp;
	t_envlist	*temp;

	i[0] = ft_env_len(env);
	res = ft_calloc(sizeof(char *), (i[0] + 1));
	if (!res)
		return (NULL);
	i[1] = -1;
	tmp = NULL;
	temp = env;
	while (++(i[1]) < i[0] && temp)
	{
		if (temp->content == NULL)
			res[i[1]] = ft_strdup(temp->variable);
		else
		{
			tmp = ft_strjoin(temp->variable, "=");
			res[i[1]] = ft_strjoin(tmp, temp->content);
			free(tmp);
		}
		temp = temp->next;
	}
	return (res);
}
