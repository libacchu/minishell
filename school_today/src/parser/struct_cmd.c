/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:49:43 by mluik             #+#    #+#             */
/*   Updated: 2022/08/17 21:14:29 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Initializes the minishell data struct to NULL. */
t_minishell	initialize_minishell_struct(void)
{
	t_minishell	minishell;

	minishell.tokenlist = NULL;
	minishell.redir_list = NULL;
	minishell.envlist = NULL;
	minishell.pipe_counter = 0;
	minishell.exit_status = NULL;
	
	minishell.executor = NULL;
	minishell.line = NULL;
	return (minishell);
}
