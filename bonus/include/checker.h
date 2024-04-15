/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybazylbe <ybazylbe@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:55:39 by ybazylbe          #+#    #+#             */
/*   Updated: 2024/02/28 17:55:42 by ybazylbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

# define SYNTAX "Error\n"
# define DUPLICATE "Error\n"
# define OVERFLOW "Error\n"

void	push(t_stack **dest, t_stack **source);
void	rotate(t_stack **head, t_stack **temp, char *string);
void	reverse_rotate(t_stack **head, t_stack **temp, char *string);
void	swap(t_stack **head, int flag);

void	free_matrix(char **argv);
void	free_stack(t_stack **stack);
void	error_free(t_stack **a, char **argv, int flag_argc_2, long *numbers);
int		error_syntax(char *str_nbr);
int		error_repetition(long *stack, int size);

t_stack	*find_last_node(t_stack *top);
int		append_node(t_stack **head, int nbr);
int		stack_len(t_stack *stack);
int		stack_sorted(t_stack *stack);

void	handle_actions(char *action, t_stack **a, t_stack **b);
void	stack_init(t_stack **a, char **argv, int argc, int flag_argc_2);

void	check_on_input(t_stack **a, t_stack **b);

#endif