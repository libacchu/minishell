/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:33:13 by mluik             #+#    #+#             */
/*   Updated: 2022/07/20 12:44:41 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (*(str + i))
	{
		if (*(str + i) && *(str + (i + 1)) != c && (str + (i + 1)))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	int		end;
	char	**string;

	if (!s)
		return (NULL);
	i = 0;
	start = 0;
	string = ft_calloc(ft_count((char *)s, c) + 1, sizeof(char *));
	if (!string)
		return (NULL);
	while (*(s + start))
	{
		while (*(s + start) == c && *(s + start))
			start++;
		end = start;
		while (*(s + end) != c && *(s + end))
			end++;
		if (*(s + start))
			string[i] = ft_substr(s, start, end - start);
		i++;
		start = end;
	}
	return (string);
}
