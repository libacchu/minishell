/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:36:48 by mluik             #+#    #+#             */
/*   Updated: 2022/02/11 16:48:40 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
