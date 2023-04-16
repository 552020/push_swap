/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:03:13 by slombard          #+#    #+#             */
/*   Updated: 2023/04/16 20:12:27 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(int *stack_a, int size_a)
{
	int tmp;

	tmp = stack_a[0];
	ft_memmove(&stack_a[0], &stack_a[1], (size_a -1) * sizeof(int));
	stack_a[size_a - 1] = tmp;
	ft_printf("ra\n");
}

void	ft_rra(int *stack_a, int size_a)
{
	int tmp;

	tmp = stack_a[size_a - 1 ];
	ft_memmove(&stack_a[1], &stack_a[0], (size_a - 1) * sizeof(int));
	stack_a[0] = tmp;
	ft_printf("rra\n");
}

void	ft_rb(int *stack_b, int size_b)
{
	int tmp;

	tmp = stack_b[0];
	ft_memmove(&stack_b[0], &stack_b[1], (size_b -1) * sizeof(int));
	stack_b[size_b - 1] = tmp;
	ft_printf("rb\n");
}

void	ft_rrb(int *stack_b, int size_b)
{
	int tmp;

	tmp = stack_b[size_b - 1];
	ft_memmove(&stack_b[1], &stack_b[0], (size_b - 1) * sizeof(int));
	stack_b[0] = tmp;
	ft_printf("rrb\n");
}

void	ft_rr(int *stack_a, int size_a, int *stack_b, int size_b)
{
	int tmp;

	tmp = stack_a[0];
	ft_memmove(&stack_a[0], &stack_a[1], (size_a -1) * sizeof(int));
	stack_a[size_a - 1] = tmp;
	tmp = stack_b[0];
	ft_memmove(&stack_b[0], &stack_b[1], (size_b -1) * sizeof(int));
	stack_b[size_b - 1] = tmp;
	ft_printf("rr\n");
}

void	ft_rrr(int *stack_a, int size_a, int *stack_b, int size_b)
{
	int tmp;

	tmp = stack_a[size_a - 1];
	ft_memmove(&stack_a[1], &stack_a[0], (size_a - 1) * sizeof(int));
	stack_a[0] = tmp;
	tmp = stack_b[size_b - 1];
	ft_memmove(&stack_b[1], &stack_b[0], (size_b - 1) * sizeof(int));
	stack_b[0] = tmp;
	ft_printf("rrr\n");
}


