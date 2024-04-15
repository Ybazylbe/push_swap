/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybazylbe <ybazylbe@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:34:55 by ybazylbe          #+#    #+#             */
/*   Updated: 2024/02/28 17:34:58 by ybazylbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack **a)
{
	if (((*a)->value > (*a)->next->value)
		&& ((*a)->next->value < (*a)->next->next->value)
		&& (*a)->next->next->value > (*a)->value)
		swap(a, 0, "sa");
	else if (((*a)->value > (*a)->next->value)
		&& ((*a)->next->value < (*a)->next->next->value)
		&& (*a)->next->next->value < (*a)->value)
		rotate(a, NULL, "ra");
	else if ((((*a)->value < (*a)->next->value)
			&& ((*a)->next->value > (*a)->next->next->value)
			&& (*a)->next->next->value > (*a)->value))
	{
		swap(a, 0, "sa");
		rotate(a, NULL, "ra");
	}
	else if ((((*a)->value < (*a)->next->value)
			&& ((*a)->next->value > (*a)->next->next->value)
			&& (*a)->next->next->value < (*a)->value))
		reverse_rotate(a, NULL, "rra");
	else
	{
		swap(a, 0, "sa");
		reverse_rotate(a, NULL, "rra");
	}
}

static void	make_stack_three(t_stack **a, t_stack **b)
{
	int	index;
	int	counter;
	int	size;

	index = 0;
	counter = 0;
	size = stack_len(*a);
	while (index < size)
	{
		if ((*a)->value == 0 && size == 4)
		{
			push(b, a, "pb");
			break ;
		}
		else if (size == 5 && ((*a)->value == 0 || (*a)->value == 1))
		{
			push(b, a, "pb");
			counter++;
		}
		else if (counter == 2)
			break ;
		else
			rotate(a, NULL, "ra");
		index++;
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	make_stack_three(a, b);
	sort_three(a);
	if (stack_len(*b) == 2 && (*b)->value < (*b)->next->value)
		swap(b, 0, "sb");
	push(a, b, "pa");
	while (stack_len(*b))
		push(a, b, "pa");
}
