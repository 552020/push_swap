/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:55:26 by slombard          #+#    #+#             */
/*   Updated: 2023/03/31 22:53:16 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **ft_build_str_arr(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	int i;
	char **ret;

	if (argc == 2)
	{
		ret = ft_split(argv[1], ' ');	
		while (ret[(*stack_a).size])
			(*stack_a).size++;
		(*stack_b).size = (*stack_a).size;
	}
	else if (argc > 2)
	{
		i = 1;
		ret = malloc (sizeof(char *) * argc - 1);
		while (i < argc)
		{
			ret[i - 1] = ft_strdup(argv[i]);
			i++;
			(*stack_a).size++;
		}
		(*stack_b).size = (*stack_a).size;
	}
	else
		exit (0) ;
	
	return (ret);

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

int	ft_find_highest(int *stack, int size)
{
	int ret;
	int i;

	i = 0;	
	ret = stack[0];
	while (i < size)
	{
		if (stack[i] > ret)
			ret = stack[i];
		i++;
	}
	return (ret);
}

int ft_find_idx_number(int *stack, int number)
{
	int	i;

	i = 0;
	while (number != stack[i])
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
