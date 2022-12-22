/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:15:19 by mluik             #+#    #+#             */
/*   Updated: 2022/10/13 20:34:17 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*  Calls the analytical lexer and
	parser functions, to be used on the input
	string; creates the final command table.
	 */
int	parse(char *command_buf, t_minishell *minishell)
{
	int	err_check;

	err_check = 0;
	err_check = ft_initialize_scan(command_buf, minishell);
	if (err_check == 2147483647)
		return (up_exit(2, minishell));
	if (err_check == 2147483646)
		return (up_exit(1, minishell));
	if (err_check == 2147483645)
		return (up_exit(0, minishell));
	ft_refine_scan(minishell);
	if (ft_parser_errorcheck_cmd(minishell) == 1 || \
			ft_parser_errorcheck_rd(minishell) == 1)
		return (1);
	return (3);
}
