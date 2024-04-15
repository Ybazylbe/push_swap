/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybazylbe <ybazylbe@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:34:01 by ybazylbe          #+#    #+#             */
/*   Updated: 2024/02/28 17:57:17 by ybazylbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	find_bigger(long *numbers, int size)
{
	int		index;
	long	bigger;

	bigger = numbers[0];
	index = 0;
	while (index < size)
	{
		if (numbers[index] > bigger)
			bigger = numbers[index];
		index++;
	}
	return (bigger);
}

long	*normalize(long *numbers, int size)
{
	int		i;
	long	*nums;
	int		j;
	int		smaller;
	long	bigger;

	bigger = find_bigger(numbers, size);
	nums = malloc(sizeof(long) * size);
	if (nums == NULL)
		return (free(numbers), NULL);
	i = -1;
	while (i < size - 1)
	{
		smaller = 0;
		j = 0;
		while (j < size)
		{
			if (numbers[j] < numbers[smaller])
				smaller = j;
			j++;
		}
		numbers[smaller] = bigger + 1;
		nums[smaller] = ++i;
	}
	return (free(numbers), nums);
}
