/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybazylbe <ybazylbe@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:47:23 by ybazylbe          #+#    #+#             */
/*   Updated: 2024/02/28 17:47:26 by ybazylbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(char *string)
{
	long	number;
	long	index;
	int		sign;

	index = 0;
	while (ft_iswhitespace(string[index]))
		index++;
	sign = 1;
	if (string[index] == '+' || string[index] == '-')
	{
		if (string[index] == '-')
			sign = -1;
		index++;
	}
	number = 0;
	while (ft_isdigit(string[index]))
	{
		number = number * 10 + (string[index] - '0');
		index++;
		if (number > INT_MAX || number < INT_MIN)
			return (2147483648);
	}
	return (number * sign);
}
