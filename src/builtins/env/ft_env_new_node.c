/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_env_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:46:55 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/02 18:51:36 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_envlist	*ft_env_new_node(char *variable, char *content)
{
	t_envlist	*new_node;
	
	new_node = ft_calloc(sizeof(t_envlist), 1);
	if (!new_node)
		return (NULL);	
	new_node->variable = variable;
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
