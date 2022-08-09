/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:45:06 by mluik             #+#    #+#             */
/*   Updated: 2022/02/14 12:51:37 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

int	print_integer(int number)
{
	int		i;

	ft_putnbr_fd(number, 1);
	i = 1;
	if (number == -2147483648)
		return (11);
	if (number < 0)
	{
		i++;
		number = number * -1;
	}
	while (number >= 10)
	{
		i++;
		number = number / 10;
	}
	return (i);
}
