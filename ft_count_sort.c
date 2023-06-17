/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:12:05 by slombard          #+#    #+#             */
/*   Updated: 2023/05/09 18:54:12 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define RR 1
#define RRR 2
#define RA_RRB 3
#define RB_RRA 4

void	ft_count_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_next next;

	// ft_printf("ft_count_sort!\n");

	// int i = 0; // REMOVE ME 
	// ft_print_stacks(stack_a, stack_b);
	while (stack_a->size > 0)
	{
		// ft_printf("\nfirst while ft_count_sort\n\n");
		// ft_print_stacks(stack_a, stack_b);
		next = ft_find_next(*stack_a, *stack_b);
		// ft_printf("next.value: %d\n", next.value);
		// ft_printf("ft_count_sort again\n");
		// ft_printf("stacks before ft_push_next\n");
		// ft_print_stacks(stack_a, stack_b);
		// ft_printf("next.value: %d\n", next.value);
		// ft_printf("next.rotation: %d\n", next.rotation);
		ft_push_next(stack_a, stack_b, next);
		// ft_printf("stacks after ft_push_next\n");
		// ft_print_stacks(stack_a, stack_b);
		// i++;
		// if (i == 10)
		// 	exit(0);
	}
	/* we need this one to process the last element in A */
	next = ft_find_next(*stack_a, *stack_b);


	ft_push_next(stack_a, stack_b, next);
	// ft_print_stacks(stack_a, stack_b);
	while (stack_b->size > 0)
		ft_pa(stack_a->stack, &stack_a->size, stack_b->stack, &stack_b->size);
}

t_next	ft_find_next(t_stack stack_a, t_stack stack_b)
{
	int i;
	t_next ret;
	t_next_score best;
	t_next_score tmp;

	// ft_printf("\n\nft_find_next\n");
	best = ft_find_score(stack_a, stack_b, stack_a.stack[0]);
	// ft_printf("best.value: %d\n", best.value);
	// ft_printf("best.rotation: %d\n", best.rotation);
	i = 0;
	// ft_printf("before the while loop\n");
	while (i < stack_a.size)
	{
		tmp = ft_find_score(stack_a, stack_b, stack_a.stack[i]);
		if (tmp.score < best.score)
			best = tmp;
		i++;
	}
	// ft_printf("###\nafter the while loop\n");
	ret.value = best.value;
	ret.rotation = best.rotation;
	// ft_printf("ret.value: %d\n", ret.value);
	// ft_printf("ret.rotation: %d\n", ret.rotation);
	return ret;
}

t_next_score	ft_find_score(t_stack stack_a, t_stack stack_b, int to_be_scored)
{
	t_scores_simple tss;
	t_scores_combined tsc;
	t_next_score ret;

	// ft_printf("\n\nft_find_score\n");
	
	tss = ft_find_scores_simple(stack_a, stack_b, to_be_scored);
	tsc = ft_find_scores_combined(tss);
	ret = ft_build_ret(tsc, to_be_scored);
	
	return ret;
}

t_scores_simple	ft_find_scores_simple(t_stack stack_a, t_stack stack_b, int to_be_scored)
{
	int to_be_scored_idx;
	t_scores_simple tss;

	// ft_printf("find_scores_simple\n");
	// ft_printf("to_be_scored: %d\n", to_be_scored);
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
	// ft_printf("tss.ra: %d\n", tss.ra);
	// ft_printf("tss.rra: %d\n", tss.rra);
	// ft_printf("tss.rb: %d\n", tss.rb);
	// ft_printf("tss.rrb: %d\n", tss.rrb);
	return tss;
}

int	ft_find_score_rb(t_stack stack_b, int to_be_scored)
{
	int next_smallest;
	int idx_next_smallest;
	// ft_printf("find_next_smallest in ft_find_score_rb\n");
	next_smallest =	ft_find_next_smallest(to_be_scored, stack_b.stack, stack_b.size);
	idx_next_smallest = ft_find_idx_number(stack_b.stack, next_smallest);
	return idx_next_smallest;
}

t_scores_combined	ft_find_scores_combined(t_scores_simple tss)
{
	t_scores_combined tsc;
	// printf("find_scores_combined\n");
	
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
	// ft_printf("tsc.rr: %d\n", tsc.rr);
	// ft_printf("tsc.rrr: %d\n", tsc.rrr);
	// ft_printf("tsc.ra_rrb: %d\n", tsc.ra_rrb);
	// ft_printf("tsc.rb_rra: %d\n", tsc.rb_rra);
	return tsc;
}

t_next_score	ft_build_ret(t_scores_combined tsc, int to_be_scored)
{
	t_next_score min;
	
	// ft_printf("build_ret\n");
	// ft_printf("ts.rr: %d\n", tsc.rr);
	// ft_printf("ts.rrr: %d\n", tsc.rrr);
	// ft_printf("ts.ra_rrb: %d\n", tsc.ra_rrb);
	// ft_printf("ts.rb_rra: %d\n", tsc.rb_rra);
	min.value = to_be_scored;
	min.rotation = RR;
	min.score = tsc.rr;
	// ft_printf("min.value: %d\n", min.value);
	// ft_printf("min.rotation: %d\n", min.rotation);
	// ft_printf("min.score: %d\n", min.score);
	if (tsc.rrr < min.score)
	{
		// ft_printf("tsc.rrr < min.score\n");
		min.rotation = RRR;
		min.score = tsc.rrr;
	}
	if (tsc.ra_rrb < min.score)
	{
		// ft_printf("tsc.ra_rrb < min.score\n");
		min.rotation = RA_RRB;
		min.score = tsc.ra_rrb;
	}
	if (tsc.rb_rra < min.score)
	{
		// ft_printf("tsc.rb_rra < min.score\n");
		min.rotation = RB_RRA;
		min.score = tsc.rb_rra;
	}
	// printf("min.rotation: %d\n", min.rotation);
	return min;
}

void	ft_push_next(t_stack *stack_a, t_stack *stack_b, t_next next)
{
	int next_smallest;
	// ft_printf("ft_push_next\n");
	// ft_printf("next.value: %d\n", next.value);
	// ft_print_stacks(stack_a, stack_b);
	// ft_printf("find_next_smallest in ft_push_next\n");	
	next_smallest = ft_find_next_smallest(next.value, stack_b->stack, stack_b->size);

	// ft_printf("next_smallest: %d\n", next_smallest);
	// if (next.value == 4)
	// {
	// 	ft_printf("next.value: %d\n", next.value);
	// 	ft_printf("REMOVE ME\n");
	// 	exit(0);

	// }
	if (next.rotation == RR)
		ft_push_next_rr(stack_a, stack_b, next, next_smallest);
	if (next.rotation == RRR)
		ft_push_next_rrr(stack_a, stack_b, next, next_smallest);
	if (next.rotation == RA_RRB)
		ft_push_next_ra_rrb(stack_a, stack_b, next, next_smallest);
	if (next.rotation == RB_RRA)
		ft_push_next_rb_rra(stack_a, stack_b, next, next_smallest);
}

void	ft_push_next_rr(t_stack *stack_a, t_stack *stack_b, t_next next, int next_smallest)
{
	// ft_printf("ft_push_next_rr\n");
	// ft_printf("next.value: %d\n", next.value);
	// ft_printf("next_smallest: %d\n", next_smallest);
	while (stack_a->stack[0] != next.value || stack_b->stack[0] != next_smallest)
	{
		// ft_printf("next.value: %d\n", next.value);
		// ft_printf("next_smallest: %d\n", next_smallest);
		// ft_printf("stack_a->stack[0]: %d\n", stack_a->stack[0]);
		// ft_printf("stack_b->stack[0]: %d\n", stack_b->stack[0]);
		// ft_printf("stack_a\n");
		// ft_print_stack(stack_a->stack, stack_a->size);
		// ft_printf("stack_b\n");
		// ft_print_stack(stack_b->stack, stack_b->size);
		if (stack_a->stack[0] != next.value && stack_b->stack[0] != next_smallest)
			ft_rr(stack_a->stack, stack_a->size, stack_b->stack, stack_b->size);
		else if (stack_a->stack[0] != next.value)
			ft_ra(stack_a->stack, stack_a->size);
		else
			ft_rb(stack_b->stack, stack_b->size);
			
	}
	ft_pb(stack_b->stack, &stack_b->size, stack_a->stack, &stack_a->size);
}

void	ft_push_next_rrr(t_stack *stack_a, t_stack *stack_b, t_next next, int next_smallest)
{
	// ft_printf("push_next_rrr\n");
	while (stack_a->stack[0] != next.value || stack_b->stack[0] != next_smallest)
	{
		// ft_printf("next.value: %d\n", next.value);
		// ft_printf("next_smallest: %d\n", next_smallest);
		// ft_printf("stack_a->stack[0]: %d\n", stack_a->stack[0]);
		// ft_printf("stack_b->stack[0]: %d\n", stack_b->stack[0]);
		// ft_printf("ft_push_next_rrr\n");
		// ft_printf("stack_a\n");
		// ft_print_stack(stack_a->stack, stack_a->size);
		// ft_printf("stack_b\n");
		// ft_print_stack(stack_b->stack, stack_b->size);
		if (stack_a->stack[0] != next.value && stack_b->stack[0] != next_smallest)
		{
			// ft_printf("ft_rrr\n");
			ft_rrr(stack_a->stack, stack_a->size, stack_b->stack, stack_b->size);
		}
		else if (stack_a->stack[0] != next.value)
		{
			// ft_printf("ft_rra\n");
			ft_rra(stack_a->stack,stack_a->size);
		}
		else
		{
			// ft_printf("ft_rrb\n");
			ft_rrb(stack_b->stack, stack_b->size);

		}
	}
	// ft_printf("before ft_pb: stack_a->size: %d\n", *(&stack_a->size)); 
	ft_pb(stack_b->stack, &stack_b->size, stack_a->stack, &stack_a->size);
}

void	ft_push_next_ra_rrb(t_stack *stack_a, t_stack *stack_b, t_next next, int next_smallest)
{
	// ft_printf("ft_push_next_ra_rrb\n");
	while (stack_a->stack[0] != next.value)
			ft_ra(stack_a->stack, stack_a->size);
	while (stack_b->stack[0] != next_smallest)
			ft_rrb(stack_b->stack, stack_b->size);
	ft_pb(stack_b->stack, &stack_b->size, stack_a->stack, &stack_a->size);

}

void ft_push_next_rb_rra(t_stack *stack_a, t_stack *stack_b, t_next next, int next_smallest)
{
	// ft_printf("ft_push_next_rb_rra\n");
	while (stack_a->stack[0] != next.value)
			ft_rra(stack_a->stack, stack_a->size);
	while (stack_b->stack[0] != next_smallest)
			ft_rb(stack_b->stack, stack_b->size);
	ft_pb(stack_b->stack, &stack_b->size, stack_a->stack, &stack_a->size);
}
