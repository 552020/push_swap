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

	//printf("ft_check_input\n");
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
	//printf("ft_check_input end\n");
	return (1);
}

int	ft_num_check(char *argv)
{
	int	i;

	//printf("ft_num_check\n");
	i = 0;
	if (ft_issign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && ft_isdigit(argv[i]))
		i++;
	if (argv[i] != '\0' && !ft_isdigit(argv[i]))
		return (0);
	//printf("ft_num_check end\n");
	return (1);
}

int	ft_issign(int c)
{
	//printf("ft_issign\n");	
	if (c == '+' || c == '-')
		return (1);
	else
	{
		//printf("ft_issign end\n");
		return (0);
		

	}
}

int	ft_isdigit(int c)
{
	//printf("ft_isdigit\n");
	if (c >= '0' && c <= '9')
		return (1);
	else
	{
		//printf("ft_isdigit end\n");
		return (0);
	}
}

int	ft_check_zero(char *argv)
{
	int	i;

	//printf("ft_check_zero\n");
	i = 0;
	if (ft_issign(argv[i]))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	//printf("ft_check_zero end\n");
	return (1);
}
