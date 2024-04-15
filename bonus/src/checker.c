/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybazylbe <ybazylbe@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:56:14 by ybazylbe          #+#    #+#             */
/*   Updated: 2024/02/28 17:56:16 by ybazylbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static int	arg_counter(char **argv)
{
	int	counter;

	counter = 0;
	while (*argv++)
		counter++;
	return (counter + 1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	size = argc;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (argv == NULL)
			return (1);
		argc = arg_counter(argv);
	}
	else
		argv += 1;
	stack_init(&a, argv, argc, size == 2);
	check_on_input(&a, &b);
	free_stack(&a);
	if (stack_len(b) != 0)
		free_stack(&b);
	return (0);
}
