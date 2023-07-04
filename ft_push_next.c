/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:39:32 by slombard          #+#    #+#             */
/*   Updated: 2023/06/18 12:39:35 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define RR 1
#define RRR 2
#define RA_RRB 3
#define RB_RRA 4

void	ft_push_next(t_stack *stack_a, t_stack *stack_b, t_next next)
{
	int	next_smallest;

	next_smallest = ft_find_next_smallest(next.value,
			stack_b->stack, stack_b->size);
	if (next.rotation == RR)
		ft_push_next_rr(stack_a, stack_b, next, next_smallest);
	if (next.rotation == RRR)
		ft_push_next_rrr(stack_a, stack_b, next, next_smallest);
	if (next.rotation == RA_RRB)
		ft_push_next_ra_rrb(stack_a, stack_b, next, next_smallest);
	if (next.rotation == RB_RRA)
		ft_push_next_rb_rra(stack_a, stack_b, next, next_smallest);
}

void	ft_push_next_rr(t_stack *stack_a, t_stack *stack_b,
					t_next next, int next_smallest)
{
	while (stack_a->stack[0] != next.value
		|| stack_b->stack[0] != next_smallest)
	{
		if (stack_a->stack[0] != next.value
			&& stack_b->stack[0] != next_smallest)
			ft_rr(stack_a->stack, stack_a->size, stack_b->stack, stack_b->size);
		else if (stack_a->stack[0] != next.value)
			ft_ra(stack_a->stack, stack_a->size);
		else
			ft_rb(stack_b->stack, stack_b->size);
	}
	ft_pb(stack_b->stack, &stack_b->size, stack_a->stack, &stack_a->size);
}

void	ft_push_next_rrr(t_stack *stack_a, t_stack *stack_b,
					t_next next, int next_smallest)
{
	while (stack_a->stack[0] != next.value
		|| stack_b->stack[0] != next_smallest)
	{
		if (stack_a->stack[0] != next.value
			&& stack_b->stack[0] != next_smallest)
			ft_rrr(stack_a->stack, stack_a->size,
				stack_b->stack, stack_b->size);
		else if (stack_a->stack[0] != next.value)
			ft_rra(stack_a->stack, stack_a->size);
		else
			ft_rrb(stack_b->stack, stack_b->size);
	}
	ft_pb(stack_b->stack, &stack_b->size, stack_a->stack, &stack_a->size);
}

void	ft_push_next_ra_rrb(t_stack *stack_a, t_stack *stack_b,
						t_next next, int next_smallest)
{
	while (stack_a->stack[0] != next.value)
		ft_ra(stack_a->stack, stack_a->size);
	while (stack_b->stack[0] != next_smallest)
		ft_rrb(stack_b->stack, stack_b->size);
	ft_pb(stack_b->stack, &stack_b->size, stack_a->stack, &stack_a->size);
}

void	ft_push_next_rb_rra(t_stack *stack_a, t_stack *stack_b,
		t_next next, int next_smallest)
{
	while (stack_a->stack[0] != next.value)
		ft_rra(stack_a->stack, stack_a->size);
	while (stack_b->stack[0] != next_smallest)
		ft_rb(stack_b->stack, stack_b->size);
	ft_pb(stack_b->stack, &stack_b->size, stack_a->stack, &stack_a->size);
}
