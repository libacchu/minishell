/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typehexlow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:44:59 by mluik             #+#    #+#             */
/*   Updated: 2022/02/14 13:34:21 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

int	print_hexlow(size_t n)
{
	int	chars;

	chars = 0;
	if (n > 15)
	{
		chars += print_hexlow(n / 16);
		chars += print_hexlow(n % 16);
	}
	else if (n < 10)
		chars += print_char('0' + n);
	else
		chars += print_char('a' + (n - 10));
	return (chars);
}
