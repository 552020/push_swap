/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 01:00:03 by slombard          #+#    #+#             */
/*   Updated: 2023/05/09 18:25:34 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int i;
	char **str_arr;
	t_stack stack_a;
	t_stack stack_b;

	stack_a.size = 0;
	stack_b.size = 0;
	str_arr = ft_build_str_arr(argc, argv, &stack_a);
	stack_a.stack = malloc (sizeof(int) * stack_a.size);
	if (!stack_a.stack)
		return (0);
	stack_b.stack = malloc (sizeof(int) * stack_a.size);
	if (!stack_b.stack)
		return(0);
	i = 0;
	while ( i < stack_a.size)
	{
		stack_a.stack[i] = ft_atoi(str_arr[i]);
		i++;
	}
	ft_printf("***stack_a***\n");
	ft_printf("stack_a.size: %d\n", stack_a.size);
	ft_print_stack(stack_a.stack, stack_a.size);
	ft_printf("***stack_b***\n");
	ft_printf("stack_b.size: %d\n", stack_b.size);
	ft_print_stack(stack_b.stack, stack_b.size);
	//if (stack_a.size < 20)
		//ft_selection(stack_a.stack, &stack_a.size, stack_b.stack, &stack_b.size);
	//else
		//ft_select_insert(stack_a.stack, &stack_a.size, stack_b.stack, &stack_b.size);
	ft_count_sort(&stack_a, &stack_b);
	ft_printf("***stack_a***\n");
	ft_printf("stack_a.size: %d\n", stack_a.size);
	ft_print_stack(stack_a.stack, stack_a.size);
	ft_printf("***stack_b***\n");
	ft_printf("stack_b.size: %d\n", stack_b.size);
	ft_print_stack(stack_b.stack, stack_b.size);
	free(stack_a.stack);
	free(stack_b.stack);
    return (0);
}

void ft_selection(int *stack_a, int *size_a, int *stack_b, int *size_b)
{
	int smallest;
	int idx_smallest;
	
	while (1)
	{
		smallest = ft_find_smallest(stack_a, *size_a);
		idx_smallest = ft_find_idx_number(stack_a, smallest);
		while (stack_a[0] != smallest)
			if (idx_smallest + 1 > *size_a / 2)
				ft_rra(stack_a, *size_a);	
			else 
				ft_ra(stack_a, *size_a);
		ft_pb(stack_b, size_b, stack_a, size_a);
		if (*size_a == 0)
			break ;
	}
	while (*size_b > 0)
		ft_pa(stack_a, size_a, stack_b, size_b);
}
void ft_select_insert(int *stack_a, int *size_a, int *stack_b, int *size_b)
{
	int smallest;
	int	n_smallest; 
	int n; 
	int i;
	int actual_size_a; 

	n =	*size_a / 9; 
	while (*size_a > 0)
	{
		actual_size_a = *size_a;
		smallest = ft_find_smallest(stack_a, *size_a);
		n_smallest = ft_find_n_smallest(stack_a, *size_a, n);
		i = 0;	
		while (i < actual_size_a)
		{
			if (stack_a[0] >= smallest && stack_a[0] <= n_smallest)
			{
				ft_insertion(stack_a[0], stack_b, size_b);
				ft_pb(stack_b, size_b, stack_a, size_a);
				actual_size_a--;
			} 
			else 
			{
				ft_ra(stack_a, *size_a);
				actual_size_a--;
			}
			i++;
		}
	}

	ft_bring_highest_to_the_top(stack_b, *size_b);
	while (*size_b > 0)
		ft_pa(stack_a, size_a, stack_b, size_b);
}

void ft_insertion(int to_insert, int *stack_b, int *size_b)
{
	int smallest;
	int highest;
	int idx_next_smallest;
	int next_smallest;

	smallest = ft_find_smallest(stack_b, *size_b);
	highest = ft_find_highest(stack_b, *size_b);
	if (size_b == 0)
		return ;
	else 
	{
		if (to_insert < smallest || to_insert > highest)
			ft_bring_highest_to_the_top(stack_b, *size_b);
		else
		{
			//printf("------\n");
			//printf("stack_b: ");
			//ft_print_stack(*stack_b, size_b);
			//printf("to_insert: %d\n", to_insert);
			//printf("------\n");
			//next_smallest = ft_find_next_smallest_second(to_insert, *stack_b, size_b);
			//printf("stack_b: ");
			//ft_print_stack(*stack_b, size_b);
			//printf("to_insert: %d\n", to_insert);
			//jprintf("next_smallest_alt_second: %d\n", next_smallest);
			//printf("------\n");
			//next_smallest = ft_find_next_smallest_alt_third(to_insert, *stack_b, size_b);
			//printf("stack_b: ");
			//ft_print_stack(*stack_b, size_b);
			//printf("to_insert: %d\n", to_insert);
			//printf("next_smallest_alt_third: %d\n", next_smallest);
			//printf("------\n");
			//next_smallest = ft_find_next_smallest(to_insert, *stack_b, size_b);
			//printf("stack_b: ");
			//ft_print_stack(*stack_b, size_b);
			//printf("to_insert: %d\n", to_insert);
			//printf("next_smallest: %d\n", next_smallest);
			next_smallest = ft_find_next_smallest(to_insert, stack_b, *size_b);
			idx_next_smallest = ft_find_idx_number(stack_b, next_smallest);
			//printf("next_smallest_alt: %d\n", next_smallest);
			while (!((stack_b[0] < to_insert) && (stack_b[*size_b - 1] > to_insert)))
			{
				if (idx_next_smallest == 0)
					break ;
				if (idx_next_smallest < *size_b / 2)
					ft_rb(stack_b, *size_b);
				else
					ft_rrb(stack_b, *size_b);
			}			
		}
	}
}

int ft_find_n_smallest(int *stack_a, int size_a, int n)
{
	int n_smallest;
	int last_n_smallest;
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < n && j < size_a)
	{
		n_smallest = stack_a[0];
		if (j == 0) 
			n_smallest = ft_find_smallest(stack_a, size_a);
		else 
		{
			while (i < size_a)
			{
				if (stack_a[i] < n_smallest && stack_a[i] > last_n_smallest)
					n_smallest = stack_a[i];
				i++;
			}
		}
		last_n_smallest = n_smallest;
		i = 0;
		j++;
	}
	return (last_n_smallest);
}

int ft_find_next_smallest(int to_insert, int *stack, int size)
{
	int i;
	int highest_b;
	int next_smallest;

	// ft_printf("ft_find_next_smallest\n");
	// ft_printf("to_insert: %d\n", to_insert);
	// ft_printf("size: %d\n", size);
	highest_b = ft_find_highest(stack, size);
	next_smallest = highest_b;
	// ft_printf("next_smallest_start: %d\n", next_smallest);

	i = 0;
	while (i < size - 1)
	{
		// printf("stack[%d]: %d\n", i, stack[i]);
		if(stack[i] > to_insert && stack[i + 1] < to_insert)
			next_smallest = stack[i + 1];
		i++;
		// ft_printf("next_smallest_loop: %d\n", next_smallest);
	}
	if(stack[size - 1] > to_insert && stack[0] < to_insert)
		next_smallest = stack[0];
	// ft_printf("next_smallest_final: %d\n", next_smallest);
	// ft_printf("------REMOVE\n");
	
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
