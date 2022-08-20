/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:45:01 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/07 07:44:54 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_export(t_envlist *env, char **cmd_arr)
{
	t_envlist	*new;
	char		*var;
	char		*content;
	
	var = ft_get_variable(cmd_arr[1]);
	content = ft_get_content(cmd_arr[1]);
	new = ft_env_new_node(var, content);
	ft_env_add_back(&env, new);
	return (0);
}
