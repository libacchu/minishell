/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:45:01 by libacchu          #+#    #+#             */
/*   Updated: 2022/10/13 12:20:18 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_envlist	*ft_recreate_env(char **env, t_envlist *list);

int	print_export_env(t_envlist *env)
{
	if (!env)
		return (1);
	while (env != NULL)
	{
		ft_printf("declare -x ");
		ft_putstr_fd(env->variable, 1);
		if (env->content != NULL)
		{
			ft_putchar_fd('=', 1);
			ft_putchar_fd('\"', 1);
			ft_putstr_fd(env->content, 1);
			ft_putchar_fd('\"', 1);
		}
		ft_putchar_fd('\n', 1);
		env = env->next;
	}
	return (0);
}

/* Sorts an array in alphabetical order. */
char	**ft_sort_envarr(char **array, int count)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (i < (count - 1))
	{
		j = 0;
		while (array[j + 1] != NULL)
		{
			if (ft_strcmp(array[j], array[j + 1]) > 0)
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (array);
}

t_envlist	*ft_sort_env(t_envlist *env, t_minishell *shell)
{
	int			count;
	char		**env_array;
	t_envlist	*temp;

	temp = NULL;
	count = ft_env_len(env);
	env_array = ft_env_to_array(env);
	env_array = ft_sort_envarr(env_array, count);
	temp = ft_recreate_env(env_array, temp);
	env = ft_env_clear(env);
	env_array = ft_free_substring(env_array);
	shell->envlist = temp;
	return (temp);
}

/* Prints the env list when using export command
	without any arguments. */
int	print_env_sorted(t_envlist *env, t_minishell *shell)
{
	env = ft_sort_env(env, shell);
	print_export_env(env);
	return (0);
}

int	ft_export(t_envlist *env, char **argv, t_minishell *shell)
{
	t_envlist	*new;
	char		*var;
	char		*content;

	if (!argv[1])
		return (print_env_sorted(env, shell));
	else
	{
		var = ft_get_variable(argv[1]);
		content = ft_get_content(argv[1]);
		if ((ft_checkexisting_env(env, var) == 0))
		{
			ft_findandreplace_env(env, var, content);
			free(var);
			return (0);
		}
		new = ft_create_env_node(var, content);
		if (!env_namecheck(var))
			ft_env_add_back(&env, new);
	}
	return (0);
}
