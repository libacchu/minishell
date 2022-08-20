/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:33:50 by libacchu          #+#    #+#             */
/*   Updated: 2022/07/13 10:32:36 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The atoi() function converts the initial portion of
		the string pointed to by str to int representation.
*/
int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while (*str <= 32)
		str++;
	if (*str == '-')
	{
		sign = sign * -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}
