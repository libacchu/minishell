/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typehexup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:45:03 by mluik             #+#    #+#             */
/*   Updated: 2022/02/14 13:34:19 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

int	print_hexup(size_t n)
{
	int	chars;

	chars = 0;
	if (n > 15)
	{
		chars += print_hexup(n / 16);
		chars += print_hexup(n % 16);
	}
	else if (n < 10)
		chars += print_char('0' + n);
	else
		chars += print_char('A' + (n - 10));
	return (chars);
}
