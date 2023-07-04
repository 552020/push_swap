/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 01:00:03 by slombard          #+#    #+#             */
/*   Updated: 2023/06/17 23:18:41 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	char **str_arr;
	t_stack stack_a;
	t_stack stack_b;
	int i;

	stack_a.size = 0;
	stack_b.size = 0;

	if (!ft_check_input(argv))
		ft_write_error();
	str_arr = ft_build_str_arr(argc, argv, &stack_a);
	if (!ft_build_stacks(&stack_a, &stack_b, str_arr))
		return (0);
	if (stack_a.size > 3 && stack_a.size < 6)
		ft_medium_sort(&stack_a, &stack_b);
	else if (stack_a.size > 3)
		ft_count_sort(&stack_a, &stack_b);

	else
		ft_small_sort(&stack_a);
	i = 0;
	while (str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
	free(stack_a.stack);
	free(stack_b.stack);
}

int ft_build_stacks(t_stack *stack_a, t_stack *stack_b, char **str_arr)
{
	int i;

	stack_a->stack = malloc(sizeof(int) * stack_a->size);
	if (!stack_a->stack)
		return (0);
	stack_b->stack = malloc(sizeof(int) * stack_a->size);
	if (!stack_b->stack)
		return (0);
	i = 0;
	while (i < stack_a->size)
	{
		stack_a->stack[i] = ft_atol(str_arr[i]);
		i++;
	}
	return (1);
}

int ft_find_next_smallest(int to_insert, int *stack, int size)
{
	int i;
	int highest_b;
	int next_smallest;

	highest_b = ft_find_highest(stack, size);
	next_smallest = highest_b;
	i = 0;
	while (i < size - 1)
	{
		if (stack[i] > to_insert && stack[i + 1] < to_insert)
			next_smallest = stack[i + 1];
		i++;
	}
	if (size > 0 && stack[size - 1] > to_insert && stack[0] < to_insert)
		next_smallest = stack[0];
	// if (stack[size - 1] > to_insert && stack[0] < to_insert)
	// 	next_smallest = stack[0];
	return (next_smallest);
}

void ft_bring_highest_to_the_top(int *stack, int size_stack)
{
	int highest;
	int idx_highest;

	highest = ft_find_highest(stack, size_stack);
	idx_highest = ft_find_idx_number(stack, highest);
	while (stack[0] != highest)
	{
		if (idx_highest < size_stack - idx_highest)
			ft_rb(stack, size_stack);
		else
			ft_rrb(stack, size_stack);
	}
}
