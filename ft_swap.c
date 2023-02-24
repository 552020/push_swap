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

void ft_sa(int *stack_a)
{
    int tmp;

    tmp = stack_a[0];
    stack_a[0] = stack_a[1];
    stack_a[1] = tmp;
    printf("sa\n");
}

void ft_sb(int *stack_b)
{
    int tmp;

    tmp = stack_b[0];
    stack_b[0] = stack_b[1];
    stack_b[1] = tmp;
    printf("sb\n");
}

void ft_ss(int *stack_a, int *stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}

