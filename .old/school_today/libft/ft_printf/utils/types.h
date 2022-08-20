/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:40:46 by mluik             #+#    #+#             */
/*   Updated: 2022/02/14 12:53:04 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "stdlib.h"
# include "stdarg.h"
# include "stddef.h"
# include "stdio.h"
# include "string.h"
# include "unistd.h"

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *str);
int		print_char(char c);
int		print_hexlow(size_t n);
int		print_hexup(size_t n);
int		print_integer(int n);
int		print_pointer(void *p);
int		print_string(char *string);
int		print_unsigned_decimal(unsigned int n);

#endif
