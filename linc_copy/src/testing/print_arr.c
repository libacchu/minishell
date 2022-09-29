/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:10:38 by libacchu          #+#    #+#             */
/*   Updated: 2022/08/31 12:25:08 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* for testing purposes */
void print_arr(char **arr)
{
	int	i;

	i = 0;
	// ft_printf("---HEREasdg---\n");
	while (arr[i])
	{
		// ft_printf("---asdfasdf---\n");	
		printf("%s \n", arr[i]);
		i++;
	}
}
