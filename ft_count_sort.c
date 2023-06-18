/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:12:05 by slombard          #+#    #+#             */
/*   Updated: 2023/06/18 12:20:52 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define RR 1
#define RRR 2
#define RA_RRB 3
#define RB_RRA 4

void	ft_count_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_next	next;

	while (stack_a->size > 0)
	{
		next = ft_find_next(*stack_a, *stack_b);
		ft_push_next(stack_a, stack_b, next);
	}
	next = ft_find_next(*stack_a, *stack_b);
	ft_push_next(stack_a, stack_b, next);
	while (stack_b->size > 0)
		ft_pa(stack_a->stack, &stack_a->size, stack_b->stack, &stack_b->size);
}

t_next	ft_find_next(t_stack stack_a, t_stack stack_b)
{
	int				i;
	t_next			ret;
	t_next_score	best;
	t_next_score	tmp;

	best = ft_find_score(stack_a, stack_b, stack_a.stack[0]);
	i = 0;
	while (i < stack_a.size)
	{
		tmp = ft_find_score(stack_a, stack_b, stack_a.stack[i]);
		if (tmp.score < best.score)
			best = tmp;
		i++;
	}
	ret.value = best.value;
	ret.rotation = best.rotation;
	return (ret);
}

t_next_score	ft_build_ret(t_scores_combined tsc, int to_be_scored)
{
	t_next_score	min;

	min.value = to_be_scored;
	min.rotation = RR;
	min.score = tsc.rr;
	if (tsc.rrr < min.score)
	{
		min.rotation = RRR;
		min.score = tsc.rrr;
	}
	if (tsc.ra_rrb < min.score)
	{
		min.rotation = RA_RRB;
		min.score = tsc.ra_rrb;
	}
	if (tsc.rb_rra < min.score)
	{
		min.rotation = RB_RRA;
		min.score = tsc.rb_rra;
	}
	return (min);
}
