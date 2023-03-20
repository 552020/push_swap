/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:56:08 by slombard          #+#    #+#             */
/*   Updated: 2023/03/20 21:46:48 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

void	ft_sa(int *stack_a);
void	ft_sb(int *stack_b);
void	ft_ra(int *stack_a, int size_a);
void	ft_rra(int *stack_a, int size_a);
void	ft_rb(int *stack_b, int size_b);
void	ft_rrb(int *stack_b, int size_b);
int		ft_find_smallest(int *stack_a, int size);
void	ft_print_stack(int *stack, int size);
void	ft_pb(int *stack_a, int *size_a, int *stack_b, int *size_b);
void	ft_pa(int *stack_b, int *size_b, int *stack_a, int *size_a);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	**ft_split(const char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_atoi(const char *str);
void	ft_ss(int *stack_a, int *stack_b);

#endif
