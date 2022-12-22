/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeunsigneddec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:45:16 by mluik             #+#    #+#             */
/*   Updated: 2022/02/14 12:52:46 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	ft_putnbr_unsigned(unsigned long int n, int fd)
{
	if (n >= 10)
	{
		ft_putnbr_unsigned((n / 10), fd);
		ft_putchar_fd((n % 10 + '0'), fd);
	}
	else
		ft_putchar_fd((n + '0'), fd);
}

int	print_unsigned_decimal(unsigned int num)
{
	int				i;

	ft_putnbr_unsigned(num, 1);
	i = 1;
	while (num >= 10)
	{
		i++;
		num = num / 10;
	}
	return (i);
}
