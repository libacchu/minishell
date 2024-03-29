/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:32:52 by libacchu          #+#    #+#             */
/*   Updated: 2022/09/24 14:06:06 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
The strcmp() and strncmp() functions lexicographically compare
		the null-terminated strings s1 and s2.
    	The strncmp() function compares not more than n characters.
		Because strncmp() is designed for comparing strings rather
		than binary data, characters that appear after a `\0' character
		are not compared.
strncmp() functions return an integer greater than, equal to,
		or less than 0, according as the string s1 is greater than,
		equal to, or less than the string s2.
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((int)s1[i] - (int)s2[i]);
		i++;
	}
	return (0);
}
