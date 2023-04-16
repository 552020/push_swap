/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:12:05 by slombard          #+#    #+#             */
/*   Updated: 2023/04/16 15:58:06 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

#define RR 1
#define RRR 2
#define RA_RRB 3
#define RB_RRA 4

typedef struct {
	int value;
	int rotation;
	} t_next;

typedef struct {
	int value;
	int rotation;
	int score;
} t_next_score;

typedef struct {
	int ra;
	int rra;
	int rb;
	int rrb;
} t_scores_simple;

typedef struct {
	int rr;
	int rrr;
	int ra_rrb;
	int rb_rra;
} t_scores_combined;

void ft_count_sort(t_stack stack_a, t_stack stack_b)
{
	t_next next;

	next = ft_find_next(stack_a, stack_b);
	push_next(stack_a, stack_b, next);
}

t_next ft_find_next(t_stack stack_a, t_stack stack_b, int next_to_push_candidate)
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
	return best;
}

t_score ft_find_score(t_stack stack_a, t_stack stack_b, int to_be_scored)
{
	t_scores_simple tss;
	t_scores_combined tsc;
	t_next_score ret;
	int to_be_scored_idx;
	
	tss = ft_find_scores_simple(stack_a, stack_b, to_be_scored);
	tsc = ft_find_scores_combined(tss);
	ret = ft_build_ret(tsc, to_be_scored);
	return ret;
}

t_scores_simple ft_find_scores_simple(t_stack stack_a, t_stack stack_b, int to_be_scored)
{
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

int ft_find_score_rb(t_stack stack_b, int to_be_scored)
{
	int next_smallest;
	int idx_next_smallest;

	next_smallest =	ft_find_next_smallest(to_be_scored, stack_b.stack, stack_b.size);
	idx_next_smallest = ft_find_idx_number(stack_b.stack, next_smallest);
	return idx_next_smalles;t
}

t_scores_combined ft_find_scores_combined(t_scores_simple tss)
{
	t_scores_combined tsc;
	
	if (tss.ra > tss.rb)
		tsc.rr = rb;
	else 
		tsc.rr = ra;
	if (tss.rra > tss.rrb)
		tsc.rrr = rrb;
	else 
		tsc.rrr = rra;
	tsc.ra_rrb = tss.ra + tss.rrb;
	tsc.rb_rra = tss.rb + tss.rra;
	return tsc
}

t_next_score ft_build_ret(t_scored_combined tsc, int to_be_scored)
{
	t_next_score min;

	min.value = to_be_scored;
	min.rotation = RR;
	min.score = tsc.rr;
	if (tsc.rrr < min.score)
	{
		ret.rotation = RRR;
		min.score = tsc.rrr
	}
	if (tsc.ra_rrb < min.score)
	{
		ret.rotation = RA_RRB;
		min.score = tsc.ra_rrb;
	}
	if (tsc.rb_rra < min.score)
	{
		ret.rotation = RB_RRA;
		min.score = tsc.rb_rra;
	}
	ret min;
}

void push_next(t_stack stack_a, t_stack stack_b, t_stack next)
{

}


