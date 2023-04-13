/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:22:35 by slombard          #+#    #+#             */
/*   Updated: 2023/02/22 23:11:31 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_pb(int *stack_b, int *size_b, int *stack_a, int *size_a)
{
	int tmp;
	//ft_printf("ft_pa - size_a before: %d\n", *size_a);
	if (*size_a == 0)
		return ;
	tmp = stack_a[0];
	ft_memmove(&stack_a[0], &stack_a[1], (*size_a - 1) * sizeof(int));
	//ft_printf("ft_pa: stack_a after memmove: ");
	//ft_print_stack(stack_a, *size_a);
	ft_memmove(&stack_b[1], &stack_b[0], (*size_b) * sizeof(int));
	stack_b[0] = tmp;
	(*size_a)--;
	//ft_printf("ft_pa - size_a after: %d\n", *size_a);
	(*size_b)++;
	ft_printf("pb\n");
}

void ft_pa(int *stack_a, int *size_a, int *stack_b, int *size_b)
{
	int tmp;
	
	if (*size_b == 0)
		return ;
	tmp = stack_b[0];
	ft_memmove(&stack_b[0], &stack_b[1], (*size_b - 1) * sizeof(int));
	ft_memmove(&stack_a[1], &stack_a[0], (*size_a) * sizeof(int));
	stack_a[0] = tmp;
	(*size_b)--;
	(*size_a)++;
	ft_printf("pa\n");
}


