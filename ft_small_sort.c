/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:10:27 by slombard          #+#    #+#             */
/*   Updated: 2023/05/13 23:10:33 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_find_idx_number_new(t_stack *stack, int number)
{
	int i;

	i = 0;
	while (number != stack->stack[i])
		i++;
	return (i);
}

void ft_small_sort(t_stack *stack_a)
{
	int smallest;
	int largest;

	if ((*stack_a).size == 1)
		return;
	largest = ft_find_highest(stack_a->stack, stack_a->size);
	smallest = ft_find_smallest(stack_a->stack, stack_a->size);
	if (stack_a->stack[0] == largest && stack_a->stack[1] == smallest)
		ft_ra(stack_a->stack, stack_a->size);
	else if (stack_a->stack[0] == smallest && stack_a->stack[1] == largest)
	{
		ft_ra(stack_a->stack, stack_a->size);
		ft_sa(stack_a->stack);
		ft_rra(stack_a->stack, stack_a->size);
	}
	else if (stack_a->stack[0] == largest && stack_a->stack[1] != smallest)
	{
		ft_sa(stack_a->stack);
		ft_rra(stack_a->stack, stack_a->size);
	}
	else if (stack_a->stack[0] != largest && stack_a->stack[1] == smallest)
		ft_sa(stack_a->stack);
	else if (stack_a->stack[0] != smallest && stack_a->stack[1] == largest)
		ft_rra(stack_a->stack, stack_a->size);
}

void ft_medium_sort(t_stack *stack_a, t_stack *stack_b)
{
	int smallest;
	int idx_smallest;

	while (stack_a->size > 3)
	{
		smallest = ft_find_smallest(stack_a->stack, stack_a->size);
		idx_smallest = ft_find_idx_number_new(stack_a, smallest);
		while (stack_a->stack[0] != smallest)
		{
			if (idx_smallest <= stack_a->size / 2)
				ft_ra(stack_a->stack, stack_a->size);
			else if (idx_smallest > stack_a->size / 2)
				ft_rra(stack_a->stack, stack_a->size);
		}
		ft_pb(stack_b->stack, &stack_b->size, stack_a->stack, &stack_a->size);
	}
	ft_small_sort(stack_a);
	while (stack_b->size > 0)
		ft_pa(stack_a->stack, &stack_a->size, stack_b->stack, &stack_b->size);
}
