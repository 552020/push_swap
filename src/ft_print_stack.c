/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:08:45 by slombard          #+#    #+#             */
/*   Updated: 2023/06/18 13:08:49 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(int *stack, int size)
{
	int	i;

	if (!stack || size <= 0)
		return ;
	i = 0;
	while (i < size)
	{
		printf("%d ", stack[i]);
		i++;
	}
	printf("\n");
}

void	ft_print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("---\n");
	ft_printf("***stack_a***\n");
	ft_printf("stack_a.size: %d\n", stack_a->size);
	ft_printf("stack_a: ");
	ft_print_stack(stack_a->stack, stack_a->size);
	ft_printf("\n");
	ft_printf("***stack_b***\n");
	ft_printf("stack_b.size: %d\n", stack_b->size);
	ft_printf("stack_b: ");
	ft_print_stack(stack_b->stack, stack_b->size);
	ft_printf("\n");
	ft_printf("---\n");
}
