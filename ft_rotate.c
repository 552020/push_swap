/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:03:13 by slombard          #+#    #+#             */
/*   Updated: 2023/02/24 15:09:03 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(int *stack_a, int size_a)
{
	int tmp;
	//printf("ft_ra\n");
	tmp = stack_a[0];
	//printf("tmp: %d\n", tmp);
	//printf("stack_a before ft_memmove: ");
	//ft_print_stack(stack_a, 3);
	ft_memmove(&stack_a[0], &stack_a[1], (size_a -1) * sizeof(int));
	//printf("stack_a after ft_memmove: ");
	//ft_print_stack(stack_a, 3);
	stack_a[size_a - 1] = tmp;
	printf("ra\n");
}

void	ft_rra(int *stack_a, int size_a)
{
	int tmp;
	tmp = stack_a[size_a - 1 ];
	ft_memmove(&stack_a[1], &stack_a[0], (size_a - 1) * sizeof(int));
	stack_a[0] = tmp;
	printf("rra\n");
}
