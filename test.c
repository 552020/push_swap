#include "push_swap.h"

int main(int argc, char **argv)
{
	int *stack_a;
	int *stack_b;
	int size_a;
	int size_b;
	int i;
	char **str_arr;
	i = 0;
	size_a = 0;
	size_b = 0;
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
	{
		i = 1;
		str_arr = malloc (sizeof(char *) * argc - 1);
		while (i < argc)
		{
			str_arr[i - 1] = ft_strdup(argv[i]);
			i++;
			size_a++;
		}
		size_b = size_a;
	}
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
	if (size_a < 20)
		ft_algorithm(stack_a, &size_a, stack_b, &size_b);
	else
		ft_select_insert(&stack_a, &size_a, &stack_b, &size_b);
	free(stack_a);
	free(stack_b);
    return (0);
}

void ft_select_insert(int **stack_a, int *size_a, int **stack_b, int *size_b)
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
		smallest = ft_find_smallest(*stack_a, *size_a);
		n_smallest = ft_find_n_smallest(*stack_a, *size_a, n);
		i = 0;	
		while (i < actual_size_a)
		{
			if ((*stack_a)[0] >= smallest && (*stack_a)[0] <= n_smallest)
			{
				ft_insertion((*stack_a)[0], stack_b, *size_b);
				ft_pb(*stack_b, size_b, *stack_a, size_a);
				actual_size_a--;
			} 
			else 
			{
				ft_ra(*stack_a, *size_a);
				actual_size_a--;
			}
			i++;
		}
	}
	ft_bring_highest_to_the_top(stack_b, *size_b);
	while (*size_b > 0)
		ft_pa(*stack_a, size_a, *stack_b, size_b);
}

void ft_insertion(int to_insert, int **stack_b, int size_b)
{
	int smallest;
	int highest;
	int idx_next_smallest;
	int next_smallest;

	smallest = ft_find_smallest(*stack_b, size_b);
	highest = ft_find_highest(*stack_b, size_b);
	next_smallest = ft_find_next_smallest(to_insert, *stack_b, size_b);
	idx_next_smallest = ft_find_idx_number(*stack_b, next_smallest);	
	if (size_b == 0)
		return ;
	else 
	{
		if (to_insert < smallest || to_insert > highest)
			ft_bring_highest_to_the_top(stack_b, size_b);
		else
		{
			while (!(((*stack_b)[0] < to_insert) && ((*stack_b)[size_b - 1] > to_insert)))
			{
				if (idx_next_smallest < size_b - idx_next_smallest)
					ft_rb(*stack_b, size_b);
				else
					ft_rrb(*stack_b, size_b);
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
	int smallest;
	int next_smallest;
	int diff;

	i = 0;
	smallest = ft_find_smallest(stack, size);
	diff = to_insert - smallest;
	next_smallest = stack[0];
	while (i < size - 1)
	{
		if (stack[i] < to_insert && (to_insert - stack[i]) <= diff)
		{
			diff = to_insert - stack[i];
			next_smallest = stack[i];
		}
		i++;
	}
	return (next_smallest);
}


void ft_bring_highest_to_the_top(int **stack, int size_stack)
{
	int highest;
	int idx_highest;

	highest = ft_find_highest(*stack, size_stack);
	idx_highest = ft_find_idx_number(*stack, highest);	

	while ((*stack)[0] != highest)
	{
		if (idx_highest < size_stack - idx_highest)
			ft_rb(*stack, size_stack);
		else
			ft_rrb(*stack, size_stack);
	}
}
