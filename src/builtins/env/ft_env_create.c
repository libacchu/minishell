/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:13:31 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/02 21:03:06 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*ft_get_variable()
{
	
}

char	*ft_get_content()
{
	
}

void	ft_free_and_destroy(char *var, char *content, t_envlist *tmp)
{
	free(var);
	free(content);
	
}

int		ft_env_create(char **env, t_minishell *shell)
{
	int 		i;
	char		*var;
	char		*content;
	t_envlist	*tmp;

	var = ft_get_variable(env[0]);
	content = ft_get_content(env[0]);
	shell->env = ft_env_new_node(var, content);
	i = 1;
	while (env[i])
	{
		var = ft_get_variable(env[i]);
		content = ft_get_content(env[i]);
		tmp = ft_env_new_node(var, content);
		ft_env_add_back(&shell->env, tmp);
		ft_free_and_destroy(var, content, tmp);
		i++;
	}
	return (0)
}
