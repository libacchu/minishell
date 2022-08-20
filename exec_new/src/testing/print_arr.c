/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:10:38 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/20 15:30:05 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* for testing purposes */
void print_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		ft_printf("%s \n", arr[i]);
}
