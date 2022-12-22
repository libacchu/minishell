/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:18:43 by mluik             #+#    #+#             */
/*   Updated: 2022/10/15 12:19:10 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	up_exit(int exnum, t_minishell *shell)
{
	shell->exit_status = exnum;
	return (exnum);
}
