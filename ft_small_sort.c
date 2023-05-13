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

void	ft_small_sort(t_stack *stack_a)
{
	int smallest = ft_find_smallest(stack_a->stack, stack_a->size);
	int largest = ft_find_highest(stack_a->stack, stack_a->size);
	// order is [largest, smallest, middle]
	if (stack_a->stack[0] == largest && stack_a->stack[1] == smallest)
		ft_ra(stack_a->stack, stack_a->size);
	// order is [smallest, largest, middle]
	else if (stack_a->stack[0] == smallest && stack_a->stack[1] == largest)
	{
		ft_ra(stack_a->stack, stack_a->size);
		ft_sa(stack_a->stack);
		ft_rra(stack_a->stack, stack_a->size);
	}
	// order is [largest, middle, smallest]
	else if (stack_a->stack[0] == largest && stack_a->stack[1] != smallest)
	{
		ft_sa(stack_a->stack);
		ft_rra(stack_a->stack, stack_a->size);
	}
	// order is [middle, smallest, largest] 
	else if (stack_a->stack[0] != largest && stack_a->stack[1] == smallest)
		ft_sa(stack_a->stack);
	// order is [middle, largest, smallest] 
	else if (stack_a->stack[0] != smallest && stack_a->stack[1] == largest)
		ft_rra(stack_a->stack, stack_a->size);
}

void	ft_medium_sort(t_stack *stack_a, t_stack *stack_b)
{
	int smallest;
	int i;

	i = 0;
	while(i < 2)
	{
		smallest = ft_find_smallest(stack_a->stack, stack_a->size);
		while (stack_a->stack[0] != smallest)
			ft_ra(stack_a->stack, stack_a->size);
		ft_pb(stack_a->stack, &stack_a->size, stack_b->stack, &stack_b->size );
		i++;
	}
	ft_small_sort(stack_a);
	ft_pb(stack_b->stack, &stack_b->size, stack_a->stack, &stack_a->size );
	ft_pb(stack_b->stack, &stack_b->size, stack_a->stack, &stack_a->size );
}
