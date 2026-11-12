/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:58:16 by slombard          #+#    #+#             */
/*   Updated: 2023/02/24 14:17:57 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(int *stack_a)
{
	int	tmp;

	tmp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = tmp;
	ft_printf("sa\n");
}

void	ft_sb(int *stack_b)
{
	int	tmp;

	tmp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = tmp;
	ft_printf("sb\n");
}

void	ft_ss(int *stack_a, int *stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}

void	ft_rr(int *stack_a, int size_a, int *stack_b, int size_b)
{
	int	tmp;

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
	int	tmp;

	tmp = stack_a[size_a - 1];
	ft_memmove(&stack_a[1], &stack_a[0], (size_a - 1) * sizeof(int));
	stack_a[0] = tmp;
	tmp = stack_b[size_b - 1];
	ft_memmove(&stack_b[1], &stack_b[0], (size_b - 1) * sizeof(int));
	stack_b[0] = tmp;
	ft_printf("rrr\n");
}
