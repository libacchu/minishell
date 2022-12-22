/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 18:11:50 by mluik             #+#    #+#             */
/*   Updated: 2022/10/02 22:37:53 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_checkcontent(char *str)
{
	int	checker;
	int	start;

	start = 0;
	checker = 0;
	while (str[start] != '\0')
	{
		if (str[start] == '=')
		checker = 1;
		start++;
	}
	return (checker);
}

int	env_namecheck(char *name)
{
	if (ft_isdigit(name[0]))
	{
		printf("export: \'%s': not a valid identifier\n", name);
		return (-1);
	}
	else
		return (0);
}

void	ft_findandreplace_env(t_envlist *env, char *var, char *content)
{
	t_envlist	*temp;
	char		*temp_str;

	temp = env;
	temp_str = NULL;
	while (temp)
	{
		if (ft_strcmp(temp->variable, var) == 0)
		{
			temp_str = temp->content;
			temp->content = content;
			free (temp_str);
		}
		temp = temp->next;
	}
}

int	ft_checkexisting_env(t_envlist *env, char *var)
{
	int			checker;
	t_envlist	*temp;

	checker = 1;
	temp = env;
	while (temp)
	{
		checker = ft_strcmp(temp->variable, var);
		if (checker == 0)
			return (0);
		temp = temp->next;
	}
	return (checker);
}

int	ft_varlen(char *var)
{
	int	len;

	len = 0;
	while (var[len] != '\0')
		len++;
	return (len);
}
