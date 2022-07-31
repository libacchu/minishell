/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:40:13 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/31 19:24:30 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_prog_handler(t_minishell *shell, char *command_buf)
{
	shell->commands = ft_make_cmd(command_buf);
	return (0);
}
