/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:00:43 by slombard          #+#    #+#             */
/*   Updated: 2023/02/24 15:13:02 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
TODO 1. Outsource str_art build  
TODO 2. Optimize algorithm: implement rra
*/
#include "push_swap.h"
void ft_algorithm(int *stack_a, int *size_a, int *stack_b, int *size_b);
int ft_find_idx_smallest(int *stack, int smallest);


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
	ft_algorithm(stack_a, &size_a, stack_b, &size_b);
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


int	ft_find_smallest(int *stack_a, int size)
{
	int ret;
	int i;

	i = 0;	
	ret = stack_a[0];
	while (i < size)
	{
		if (stack_a[i] < ret)
			ret = stack_a[i];
		i++;
	}

	return (ret);
}

int ft_find_idx_smallest(int *stack, int smallest)
{
	int	i;

	i = 0;
	while (smallest != stack[i])
		i++;
	return (i);
}

void	ft_print_stack(int *stack, int size)
{
	int i;

	i = 0;
    while (i < size)
    {
        printf("%d ", stack[i]);
        i++;
    }

    printf("\n");
}

