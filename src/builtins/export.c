/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:45:01 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/02 19:07:37 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*join_var_and_content(t_envlist *env)
{
	char	*str;

	str = ft_strdup(env->variable);
	str = ft_strjoin(str, '=');
	str = ft_strjoin(str, env->content);
	return(str);
}

char	**convert_env_to_arr(t_envlist *env_struct)
{
	int		size_lst;
	char	**env_arr;
	int		i;
	t_envlist	*tmp;

	size_lst = ft_env_len(env_struct);
	env_arr = ft_calloc(sizeof(char *), size_lst + 1);
	while (i < size_lst)
	{
		env_arr[i] = join_var_and_content(env_arr);
		i++;
		env_struct = env_struct->next;	
	}
	env_arr[i] = NULL;
	env_struct = tmp;
	return (env_arr);
}



int	ft_export(t_envlist *env, char **arr)
{
	
}
