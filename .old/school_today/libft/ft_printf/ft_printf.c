/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:29:36 by mluik             #+#    #+#             */
/*   Updated: 2022/02/14 13:11:26 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_eval_variable(const char *input, int len, va_list args)
{
	if (*input == 'c')
		len = print_char(va_arg(args, int));
	else if (*input == 'x')
		len = print_hexlow(va_arg(args, unsigned int));
	else if (*input == 'X')
		len = print_hexup(va_arg(args, unsigned int));
	else if (*input == 's')
		len = print_string(va_arg(args, char *));
	else if (*input == 'i' || *input == 'd')
		len = print_integer(va_arg(args, int));
	else if (*input == 'p')
		len = print_pointer(va_arg(args, void *));
	else if (*input == 'u')
		len = print_unsigned_decimal(va_arg(args, unsigned int));
	else if (*input == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, format);
	if (!*format)
		return (0);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			len += write(1, &*format, 1);
		}
		if (*format == '%')
		{
			format++;
			len += ft_eval_variable(format, len, args);
		}
		format++;
	}
	va_end(args);
	return (len);
}
