/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:00:43 by slombard          #+#    #+#             */
/*   Updated: 2023/03/18 23:36:57 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
TODO 1. Outsource str_art build  
TODO 2. Optimize algorithm: implement rra
*/
#include "push_swap.h"

int main(int argc, char **argv)
{
	int *stack_a;
	int *stack_b;
	int size_a;
	int size_b;
	int i;
	char **str_arr;
	/* TODO Outsource str_arr build */
	i = 0;
	size_a = 0;
	size_b = 0;
	while (i < argc)
		i++;
	if (argc == 2)
	{
		str_arr = ft_split(argv[1], ' ');	
		i = 0;
		while (str_arr[i])
		{
			size_a++;
			i++;
		}
		size_b = size_a;
	}
	else if (argc > 2)
		str_arr = &argv[1];
	else
		return (0) ; 
	stack_a = malloc (sizeof(int) * size_a);
	stack_b = malloc (sizeof(int) * size_b);
	size_b = 0;
	i = 0;
	while (i < size_a)
	{
		stack_a[i] = ft_atoi(str_arr[i]);
	i++;
	}
	
	printf("START\n");
	printf("stack_a: ");
	ft_print_stack(stack_a, size_a);
	printf("stack_b: ");
	ft_print_stack(stack_b, size_b);

	//ft_algorithm(stack_a, &size_a, stack_b, &size_b);
	ft_select_insert(&stack_a, &size_a, &stack_b, &size_b);
	printf("END\n");
	printf("stack_a: ");
	ft_print_stack(stack_a, size_a);
	printf("stack_b: ");
	ft_print_stack(stack_b, size_b);

		free(stack_a);
	free(stack_b);

    return (0);
}

void ft_algorithm(int *stack_a, int *size_a, int *stack_b, int *size_b)
{
	int smallest;
	int idx_smallest;
	
	while (1)
	{
		smallest = ft_find_smallest(stack_a, *size_a);
		idx_smallest = ft_find_idx_smallest(stack_a, smallest);
		while (stack_a[0] != smallest)
			if (idx_smallest + 1 > *size_a / 2)
				ft_rra(stack_a, *size_a);	
			else 
				ft_ra(stack_a, *size_a);
		ft_pb(stack_b, size_b, stack_a, size_a);
		//printf("%d\n", *size_a);
		if (*size_a == 0)
			break ;
	}
	while (*size_b > 0)
	{
		//printf("%d\n", *size_b);
		ft_pa(stack_a, size_a, stack_b, size_b);
	}
}

/* selection insertion sort algorithm */
void ft_select_insert(int **stack_a, int *size_a, int **stack_b, int *size_b)
{
	// 1.TODO Find the n smallest numbers 
	// The size of the chunks could also vary depending on their distribution. 
	// The result of this operation could be an array, but it could be also just the value of the smallest number and the value of the 50-th smallest value.
	int smallest;
	int	n_smallest; 
	int n; 
	int i;
	int actual_size_a; // we need this to the single interations through A

	n =	*size_a / 10; 

	// 2.TODO Push: We iterate through A as many times till A is empty and if the number is on the list or in the range, then we push the numbers to B
	while (*size_a > 0)
	{
		//printf("while\n");
		//printf("size_a: %d\n", *size_a); 
		actual_size_a = *size_a;
		smallest = ft_find_smallest(*stack_a, *size_a);
		n_smallest = ft_find_n_smallest(*stack_a, *size_a, n);
		i = 0;	
		while (i < actual_size_a)
		{
			/*
			printf("size_a: %d\n", *size_a);
			printf("size_b: %d\n", *size_b);
			printf("inner_while\n");
			printf("stack_a: ");
			ft_print_stack(*stack_a, *size_a);
			printf("stack_b: ");
			ft_print_stack(*stack_b, *size_b);
			printf("actual_size_a: %d\n", actual_size_a);
			printf("i: %d\n", i);
			printf("stack_a[%d]: %d\n", i, (*stack_a)[i]);
			*/
			if ((*stack_a)[i] >= smallest || (*stack_a)[i] <= n_smallest)
			{
				// 3. TODO (Insertion Sort) We rotate the number B inserting the number in the right place.
				ft_insertion(*stack_a[0], *stack_b, *size_b);
				ft_pb(*stack_b, size_b, *stack_a, size_a);
				actual_size_a--;
				i = 0;
			}
			i++;
		}
	}
}

void ft_insertion(int to_insert, int *stack_b, int size_b)
{
	int smallest;
	int highest;

	//printf("ft_insertion\n");

	if (size_b == 0)
		return ;
	else 
	{
		smallest = ft_find_smallest(stack_b, size_b);
		highest = ft_find_highest(stack_b, size_b);
		if (to_insert < smallest || to_insert > highest)
			ft_bring_highest_to_the_top(stack_b, size_b);
		else
			while (stack_b[0] > to_insert && stack_b[1] > to_insert)
				ft_rb(stack_b, size_b);
			ft_rb(stack_b, size_b);
	}
}

int ft_find_n_smallest(int *stack_a, int size_a, int n)
{
	// if size_a < n, then we can just return the biggest
	// actually we shouldn't care cause all the numbers are then copied to b
	// we should actually write a guard in the outer function and if size_a < n then we don't call ft_find_n_smallest
	int n_smallest;
	int last_n_smallest;
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < n && j < size_a)
	{
		n_smallest = stack_a[0];
		if (j == 0) // It means if it's the first time we run the function
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


void ft_bring_highest_to_the_top(int *stack, int size_stack)
{
	int highest;
	int idx_highest;

	highest = ft_find_highest(stack, size_stack);
	idx_highest = ft_find_idx_highest(stack, highest);	

	while (stack[0] != highest)
	{
		if (idx_highest > size_stack/2)
			ft_rrb(stack, size_stack);
		else
			ft_rb(stack, size_stack);
	}
}
