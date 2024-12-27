/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:46:33 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/26 16:12:34 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int		count;
	t_node	*current;

	count = 0;
	current = stack->top;
	while (current)
	{
		current = current->next;
		count++;
	}
	return (count);
}

// void	print_stacks(t_stack *a, t_stack *b)
// {
// 	t_node	*current;
// 	int		len;
// 	t_node	*curr;

// 	current = a->top;
// 	if (!a->top)
// 		write(1, "stack doesnt exist here\n", 25);
// 	write(1, "Sorted Stack a:\n", 16);
// 	while (current)
// 	{
// 		len = printf("%d ", current->value);
// 		current = current->next;
// 	}
// 	curr = b->top;
// }

void	free_stack(t_stack *a)
{
	t_node	*temp;

	while (a->top)
	{
		temp = a->top;
		a->top = a->top->next;
		free(temp);
	}
}

void	choose_sort(t_stack *a, t_stack *b)
{
	int	size;

	size = stack_size(a);
	if (is_sorted(a))
		return ;
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 5)
		sort_five(a, b);
	else if (size > 3)
		bit_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;

	if (argc < 2 || (argc == 2 && !argv[1]))
		return (0);
	argv = splitavs(argc, argv);
	argc = argcount(argv);
	if (argc == 1 && (!argnum(*argv) || !inrange(argv)))
		return (ft_free(argv), write(1, "Error\n", 7), exit(1), 1);
	if (!check(argv) || !inrange(argv))
		return (ft_free(argv), write(1, "Error\n", 7), exit(1), 1);
	a.top = NULL;
	b.top = NULL;
	i = argc;
	while (--i >= 0)
		push(&a, ft_atoi(argv[i]));
	assign_final_positions(&a);
	ft_free(argv);
	choose_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
