/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:45:01 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/27 15:48:47 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	print_export_env(t_envlist *env)
{
	if (!env)
		return (1);
	while (env != NULL)
	{
		ft_printf("declare -x ");
		ft_putstr_fd(env->variable, 1);
		ft_putchar_fd('=', 1);
		ft_putchar_fd('\"', 1);
		ft_putstr_fd(env->content, 1);
		ft_putchar_fd('\"', 1);
		ft_putchar_fd('\n', 1);
		env = env->next;
	}
	return (0);
}

void	ft_sortlast(t_envlist *lastsort)
{
	t_envlist	*temp_two;
	t_envlist	*open_node;

	open_node = lastsort;
	temp_two = open_node;
	open_node = open_node->next;
	open_node->next = temp_two;
	open_node->next->next = NULL;
}

void	ft_sort_env_single(t_envlist *env)
{
	t_envlist	*temp_two;
	t_envlist	*open_node;

	open_node = env;
	while (open_node)
	{
		if (open_node->next != NULL && \
			ft_strcmp(open_node->variable, open_node->next->variable) > 0)
		{
			temp_two = NULL;
			if (!open_node->next->next)
				ft_sortlast(open_node);
			else
			{
				temp_two = open_node->next->next;
				open_node->next->next = open_node;
				open_node->next = temp_two;
			}
		}
		else
			open_node = open_node->next;
	}
}

/* Prints the env list when using export command
	without any arguments. 
	Alphabetical sorting needs testing, 27.09.2022 */
int	print_env_sorted(t_envlist *env)
{
	int	max_count;

	max_count = ft_env_len(env);
	while ((max_count - 1) > 0)
	{
		ft_sort_env_single(env);
		max_count--;
	}
	print_export_env(env);
	return (0);
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

int	ft_export(t_envlist *env, char **argv)
{
	t_envlist	*new;
	char		*var;
	char		*content;

	if (!argv[1])
		return (print_env_sorted(env));
	else
	{
		var = ft_get_variable(argv[1]);
		content = ft_get_content(argv[1]);
		new = ft_env_new_node(var, content);
		if (!env_namecheck(var))
			ft_env_add_back(&env, new);
	}
	return (0);
}
