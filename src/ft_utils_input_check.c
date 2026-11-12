/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_input_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:49:57 by slombard          #+#    #+#             */
/*   Updated: 2023/06/17 22:50:05 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_input(char **str_arr)
{
	int	i;
	int	tot_zeros;

	tot_zeros = 0;
	i = 1;
	while (str_arr[i])
	{
		if (!ft_num_check(str_arr[i]))
			return (0);
		tot_zeros += ft_check_zero(str_arr[i]);
		i++;
	}
	if (tot_zeros > 1)
		return (0);
	if (ft_sneak_duplicate(str_arr))
		return (0);
	return (1);
}

int	ft_num_check(char *str_arr)
{
	int	i;

	i = 0;
	if (ft_issign(str_arr[i]) && str_arr[i + 1] != '\0')
		i++;
	while (str_arr[i] && ft_isdigit(str_arr[i]))
		i++;
	if (str_arr[i] != '\0' && !ft_isdigit(str_arr[i]))
		return (0);
	return (1);
}

int	ft_issign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_check_zero(char *str_arr)
{
	int	i;

	i = 0;
	if (ft_issign(str_arr[i]))
		i++;
	while (str_arr[i] && str_arr[i] == '0')
		i++;
	if (str_arr[i] != '\0')
		return (0);
	return (1);
}
