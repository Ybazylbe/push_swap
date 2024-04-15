/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybazylbe <ybazylbe@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:55:47 by ybazylbe          #+#    #+#             */
/*   Updated: 2024/02/28 17:55:49 by ybazylbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	push(t_stack **dest, t_stack **source)
{
	t_stack	*new_node;

	if (*source == NULL)
		return ;
	new_node = *source;
	*source = (*source)->next;
	if (*source)
		(*source)->prev = NULL;
	if (*dest == NULL)
	{
		*dest = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *dest;
		new_node->next->prev = new_node;
		*dest = new_node;
	}
}

void	rotate(t_stack **head, t_stack **temp, char *string)
{
	t_stack	*last_node;
	int		size;

	size = stack_len(*head);
	if (head == NULL || *head == NULL || size == 1)
		return ;
	last_node = find_last_node(*head);
	last_node->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
	if (!ft_strncmp(string, "rr", 2))
		rotate(temp, NULL, "false");
}

void	reverse_rotate(t_stack **head, t_stack **temp, char *string)
{
	t_stack	*last;
	int		size;

	size = stack_len(*head);
	if (head == NULL || *head == NULL || size == 1)
		return ;
	last = find_last_node(*head);
	last->prev->next = NULL;
	last->next = *head;
	last->prev = NULL;
	*head = last;
	last->next->prev = last;
	if (!ft_strncmp(string, "rrr", 3))
		reverse_rotate(temp, NULL, "false");
}

void	swap(t_stack **head, int flag)
{
	int	size;
	int	temp;
	int	state;

	state = 1;
	size = stack_len(*head);
	if (head == NULL || *head == NULL || size == 1)
		return ;
	if (flag)
		state = (*head)->value > (*head)->next->value;
	if (state)
	{
		temp = (*head)->value;
		(*head)->value = (*head)->next->value;
		(*head)->next->value = temp;
	}
}
