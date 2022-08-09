/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typepointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:45:09 by mluik             #+#    #+#             */
/*   Updated: 2022/02/15 18:30:05 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

#if __unix__

int	print_pointer(void *p)
{
	size_t	len;

	len = (size_t)p;
	if (!p)
		len = print_string("(nil)");
	else
		len = print_string("0x") + print_hexlow(len);
	return (len);
}

#else

int	print_pointer(void *p)
{
	size_t	len;

	len = (size_t)p;
	if (!p)
		len = print_string("0x0");
	else
		len = print_string("0x") + print_hexlow(len);
	return (len);
}

#endif
