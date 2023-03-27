/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:55:26 by slombard          #+#    #+#             */
/*   Updated: 2023/03/27 01:19:30 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	//printf("find_highest\n");
	//ft_print_stack(stack, size);
	

	i = 0;	
	ret = stack[0];
	while (i < size)
	{
		if (stack[i] > ret)
		{
			//printf("stack[%d]: %d\n", i, stack[i]); 
			ret = stack[i];
		}

		i++;
	}
	//printf("ret: %d\n", ret);

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
