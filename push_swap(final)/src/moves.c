/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:34:56 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/19 16:10:42 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (!b)
		return ;
	if (b->top && b->top->next)
	{
		first = b->top;
		second = b->top->next;
		first->next = second->next;
		second->next = first;
		b->top = second;
		write(1, "sb\n", 3);
	}
}

void	rrb(t_stack *b)
{
	t_node	*prev;
	t_node	*current;

	if (!b)
		return ;
	if (b->top && b->top->next)
	{
		prev = NULL;
		current = b->top;
		while (current->next)
		{
			prev = current;
			current = current->next;
		}
		current->next = b->top;
		b->top = current;
		prev->next = NULL;
		write(1, "rrb\n", 4);
	}
}

void	ss(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	sa(a);
	sb(b);
	printf("ss\n");
}

void	rr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	ra(a);
	rb(b);
	printf("rr\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	rra(a);
	rrb(b);
	printf("rrr\n");
}
