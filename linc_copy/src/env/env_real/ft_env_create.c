/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:13:31 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/24 12:09:30 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*ft_get_variable(char *str);
char	*ft_get_content(char *str);

/* ft_env_create take the environment argument 
		given by the main() and convertes it to 
		an envlist
*/
int		ft_env_create(char **env, t_minishell *shell)
{
	int			i;
	char		*var;
	char		*content;

	i = 0;
	while (env && env[i] && env[0])
	{
		var = ft_get_variable(env[i]);
		content = ft_get_content(env[i]);
		ft_env_add_back(&shell->envlist, ft_env_new_node(var, content));
		i++;
	}
	return (0);
}

char	*ft_get_variable(char *str)
{
	char	*var;
	int		len;

	len = 0;
	while (str[len] != '=')
		len++;
	var = ft_substr(str, 0, len);
	return (var);
}

char	*ft_get_content(char *str)
{
	char	*content;
	int		start;
	int		end;

	start = 0;
	while (str[start] != '=')
		start++;
	start++;
	if (str[start] == '"' || str[start] == '\'')
		start++;
	end = start;
	while (str[end] != '\0' || str[end] != '"' || str[end] == '\'')
		end++;
	content = ft_substr(str, start, end);
	return (content);
}
