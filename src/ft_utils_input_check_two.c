/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_input_check_two.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:16:52 by slombard          #+#    #+#             */
/*   Updated: 2023/06/18 13:16:58 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sneak_duplicate(char **str_arr)
{
	int	i;
	int	j;

	i = 1;
	while (str_arr[i])
	{
		j = 1;
		while (str_arr[j])
		{
			if (j != i && ft_num_str_cmp(str_arr[i], str_arr[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_write_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_num_str_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 1;
	while (i < stack->size) 
	{
		if (stack->stack[i] < stack->stack[i - 1])
			return (0);
		i++;
	}
	exit (1);
}
