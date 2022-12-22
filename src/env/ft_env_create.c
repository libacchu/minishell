/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:13:31 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/02 23:34:22 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_envlist	*ft_create_env_node(char *var, char *content);
void		ft_save_env_ls(char *var, char *content, t_minishell *minishell);
char		*ft_get_variable(char *str);
char		*ft_get_content(char *str);
t_envlist	*ft_recreate_env(char **env, t_envlist *list);

int	ft_env_create(char **env, t_minishell *minishell)
{
	int			i;
	char		*var;
	char		*content;

	i = 0;
	while (env[i])
	{
		var = ft_get_variable(env[i]);
		content = ft_get_content(env[i]);
		ft_save_env_ls(var, content, minishell);
		i++;
	}
	return (0);
}

t_envlist	*ft_create_env_node(char *var, char *content)
{
	t_envlist	*creatednode;

	creatednode = ft_calloc(1, sizeof(t_envlist));
	if (!creatednode)
		return (NULL);
	creatednode->variable = var;
	if (content != NULL)
		creatednode->content = content;
	if (content == NULL)
		creatednode->content = NULL;
	creatednode->next = NULL;
	return (creatednode);
}

void	ft_save_env_ls(char *var, char *content, t_minishell *minishell)
{
	t_envlist	*last;

	if (!minishell->envlist)
	{
		minishell->envlist = ft_create_env_node(var, content);
		return ;
	}
	last = ft_findlast_envlist(minishell->envlist);
	last->next = ft_create_env_node(var, content);
}

char	*ft_get_variable(char *str)
{
	char	*var;
	int		len;

	len = 0;
	while (str[len] != '=' && str[len] != '\0')
		len++;
	var = ft_substr(str, 0, len);
	return (var);
}

char	*ft_get_content(char *str)
{
	char	*content;
	int		start;
	int		end;
	int		checker;

	checker = 0;
	start = 0;
	checker = ft_checkcontent(str);
	if (checker == 1)
	{
		start = 0;
		while (str[start] != '=')
			start++;
		start++;
		end = start;
		while (str[end] != '\0')
			end++;
		content = ft_substr(str, start, end);
		return (content);
	}
	else
		return (NULL);
}
