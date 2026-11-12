/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:04:18 by slombard          #+#    #+#             */
/*   Updated: 2023/07/04 20:04:25 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atol(const char *str)
{
	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (isneg == 1 && nb > (INT_MAX - (str[i] - '0')) / 10)
			ft_write_error();
		else if (isneg == -1 && nb > ((INT_MIN + (str[i] - '0')) / -10))
			ft_write_error();
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * isneg);
}
