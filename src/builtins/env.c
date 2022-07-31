/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:43:39 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/31 21:42:52 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	print_lst(t_list *lst)
{
	if (!lst)
		return (1);
	while (lst)
	{
		ft_putendl_fd(lst->content, 1);
		lst = lst->next;
	}
	return (0);
}

int	env_create_lst(t_minishell *shell, char **env)
{
	int		i;
	t_list	*tmp;

	shell->env = ft_lstnew(env[0]);
	i = 1;
	while (env && env[i])
	{
		tmp = ft_lstnew(env[i]);
		ft_lstadd_back(&shell->env, tmp);
		i++;
	}
	return (0);
}

int	ft_env(t_list *env)
{
	print_lst(env);
	return (0);
}

// int main(int ac, char **av, char **env)
// {
// 	t_minishell	shell;
// 	env_create_lst(&shell, env);
// 	ft_env(shell.env);
// 	(void)ac;
// 	(void)av;
// 	return (0);
// }
