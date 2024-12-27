/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:38:19 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/26 16:14:34 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*argtostr(int ac, char **av)
{
	char	*str;
	char	*space;
	char	*tmp;
	int		i;

	str = NULL;
	i = 1;
	space = " ";
	if (!av)
		return (NULL);
	while (i < ac)
	{
		if (str == NULL)
			str = ft_strdup(av[i]);
		else
		{
			tmp = ft_strjoin(str, space);
			free(str);
			str = ft_strjoin(tmp, av[i]);
			free(tmp);
		}
		i++;
	}
	return (str);
}

int	argcount(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

char	**splitavs(int ac, char **av)
{
	char	*str;

	if (!av)
		return (NULL);
	str = argtostr(ac, av);
	av = ft_split(str, 32);
	if (!av)
		return (ft_free(av), exit(1), NULL);
	free(str);
	return (av);
}

void	move_min_to_b(t_stack *a, t_stack *b)
{
	int		min;
	t_node	*current;

	min = a->top->value;
	current = a->top;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
		}
		current = current->next;
	}
	while (a->top->value != min)
	{
		ra(a);
	}
	pb(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	move_min_to_b(a, b);
	move_min_to_b(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
	if (a->top->value > a->top->next->value)
	{
		sa(a);
	}
	ra(a);
	if (a->top->value > a->top->next->value)
	{
		sa(a);
	}
	rra(a);
}
