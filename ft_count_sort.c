/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:12:05 by slombard          #+#    #+#             */
/*   Updated: 2023/04/17 01:05:00 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define RR 1
#define RRR 2
#define RA_RRB 3
#define RB_RRA 4

void	ft_count_sort(t_stack stack_a, t_stack stack_b)
{
	t_next next;

	next = ft_find_next(stack_a, stack_b);
	ft_push_next(stack_a, stack_b, next);
	while (stack_b.size > 0)
		ft_pa(stack_a.stack, &stack_a.size, stack_b.stack, &stack_b.size);
}

t_next	ft_find_next(t_stack stack_a, t_stack stack_b)
{
	int i;
	t_next ret;
	t_next_score best;
	t_next_score tmp;

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
	return ret;
}

t_next_score	ft_find_score(t_stack stack_a, t_stack stack_b, int to_be_scored)
{
	t_scores_simple tss;
	t_scores_combined tsc;
	t_next_score ret;
	
	tss = ft_find_scores_simple(stack_a, stack_b, to_be_scored);
	tsc = ft_find_scores_combined(tss);
	ret = ft_build_ret(tsc, to_be_scored);
	return ret;
}

t_scores_simple	ft_find_scores_simple(t_stack stack_a, t_stack stack_b, int to_be_scored)
{
	int to_be_scored_idx;
	t_scores_simple tss;

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
	return tss;
}

int	ft_find_score_rb(t_stack stack_b, int to_be_scored)
{
	int next_smallest;
	int idx_next_smallest;

	next_smallest =	ft_find_next_smallest(to_be_scored, stack_b.stack, stack_b.size);
	idx_next_smallest = ft_find_idx_number(stack_b.stack, next_smallest);
	return idx_next_smallest;
}

t_scores_combined	ft_find_scores_combined(t_scores_simple tss)
{
	t_scores_combined tsc;
	
	if (tss.ra > tss.rb)
		tsc.rr = tss.ra;
	else 
		tsc.rr = tss.rb;
	if (tss.rra > tss.rrb)
		tsc.rrr = tss.rrb;
	else 
		tsc.rrr = tss.rra;
	tsc.ra_rrb = tss.ra + tss.rrb;
	tsc.rb_rra = tss.rb + tss.rra;
	return tsc;
}

t_next_score	ft_build_ret(t_scores_combined tsc, int to_be_scored)
{
	t_next_score min;

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
	return min;
}

void	ft_push_next(t_stack stack_a, t_stack stack_b, t_next next)
{
	int next_smallest;

	next_smallest = ft_find_next_smallest(next.value, stack_b.stack, stack_b.size);
	if (next.rotation == RR)
		ft_push_next_rr(stack_a, stack_b, next, next_smallest);
	if (next.rotation == RRR)
		ft_push_next_rrr(stack_a, stack_b, next, next_smallest);
	if (next.rotation == RA_RRB)
		ft_push_next_ra_rrb(stack_a, stack_b, next, next_smallest);
	if (next.rotation == RB_RRA)
		ft_push_next_rb_rra(stack_a, stack_b, next, next_smallest);
}

void	ft_push_next_rr(t_stack stack_a, t_stack stack_b, t_next next, int next_smallest)
{	
		while (stack_a.stack[0] != next.value || stack_b.stack[0] != next_smallest)
	{
		if (stack_a.stack[0] != next.value && stack_b.stack[0] != next_smallest)
			ft_rr(stack_a.stack, stack_a.size, stack_b.stack, stack_b.size);
		else if (stack_a.stack[0] != next.value)
			ft_rb(stack_b.stack, stack_b.size);
		else
			ft_ra(stack_a.stack, stack_a.size);
	}
	ft_pb(stack_b.stack, &stack_b.size, stack_a.stack, &stack_a.size);
}

void	ft_push_next_rrr(t_stack stack_a, t_stack stack_b, t_next next, int next_smallest)
{
	while (stack_a.stack[0] != next.value || stack_b.stack[0] != next_smallest)
	{
		if (stack_a.stack[0] != next.value && stack_b.stack[0] != next_smallest)
			ft_rrr(stack_a.stack, stack_a.size, stack_b.stack, stack_b.size);
		else if (stack_a.stack[0] != next.value)
			ft_rrb(stack_b.stack, stack_b.size);
		else
			ft_rra(stack_a.stack, stack_a.size);
	}
	ft_pb(stack_b.stack, &stack_b.size, stack_a.stack, &stack_a.size);
}

void	ft_push_next_ra_rrb(t_stack stack_a, t_stack stack_b, t_next next, int next_smallest)
{
	while (stack_a.stack[0] != next.value)
			ft_ra(stack_a.stack, stack_a.size);
	while (stack_b.stack[0] != next_smallest)
			ft_rrb(stack_b.stack, stack_b.size);
	ft_pb(stack_b.stack, &stack_b.size, stack_a.stack, &stack_a.size);

}

void ft_push_next_rb_rra(t_stack stack_a, t_stack stack_b, t_next next, int next_smallest)
{
	while (stack_a.stack[0] != next.value)
			ft_rra(stack_a.stack, stack_a.size);
	while (stack_b.stack[0] != next_smallest)
			ft_rb(stack_b.stack, stack_b.size);
	ft_pb(stack_b.stack, &stack_b.size, stack_a.stack, &stack_a.size);
}
