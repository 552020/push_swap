/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_scores.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:39:02 by slombard          #+#    #+#             */
/*   Updated: 2023/06/18 12:39:08 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_next_score	ft_find_score(t_stack stack_a,
		t_stack stack_b, int to_be_scored)
{
	t_scores_simple		tss;
	t_scores_combined	tsc;
	t_next_score		ret;

	tss = ft_find_scores_simple(stack_a, stack_b, to_be_scored);
	tsc = ft_find_scores_combined(tss);
	ret = ft_build_ret(tsc, to_be_scored);
	return (ret);
}

t_scores_simple	ft_find_scores_simple(t_stack stack_a,
		t_stack stack_b, int to_be_scored)
{
	int					to_be_scored_idx;
	t_scores_simple		tss;

	to_be_scored_idx = ft_find_idx_number(stack_a.stack, to_be_scored);
	tss.ra = to_be_scored_idx;
	if (to_be_scored_idx == 0)
		tss.rra = 0;
	else
		tss.rra = stack_a.size - to_be_scored_idx;
	tss.rb = ft_find_score_rb(stack_b, to_be_scored);
	if (tss.rb == 0)
		tss.rrb = 0;
	else
		tss.rrb = stack_b.size - tss.rb;
	return (tss);
}

int	ft_find_score_rb(t_stack stack_b, int to_be_scored)
{
	int	next_smallest;
	int	idx_next_smallest;

	next_smallest = ft_find_next_smallest(to_be_scored,
			stack_b.stack, stack_b.size);
	idx_next_smallest = ft_find_idx_number(stack_b.stack, next_smallest);
	return (idx_next_smallest);
}

t_scores_combined	ft_find_scores_combined(t_scores_simple tss)
{
	t_scores_combined	tsc;

	if (tss.ra > tss.rb)
		tsc.rr = tss.ra;
	else
		tsc.rr = tss.rb;
	if (tss.rra > tss.rrb)
		tsc.rrr = tss.rra;
	else
		tsc.rrr = tss.rrb;
	tsc.ra_rrb = tss.ra + tss.rrb;
	tsc.rb_rra = tss.rb + tss.rra;
	return (tsc);
}
