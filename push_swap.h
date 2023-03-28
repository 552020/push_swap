/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:56:08 by slombard          #+#    #+#             */
/*   Updated: 2023/03/28 22:01:40 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void	ft_pa(int *stack_b, int *size_b, int *stack_a, int *size_a);
void	ft_pb(int *stack_a, int *size_a, int *stack_b, int *size_b);
void	ft_sa(int *stack_a);
void	ft_sb(int *stack_b);
void	ft_ra(int *stack_a, int size_a);
void	ft_rra(int *stack_a, int size_a);
void	ft_rb(int *stack_b, int size_b);
void	ft_rrb(int *stack_b, int size_b);
void	ft_ss(int *stack_a, int *stack_b);

int		ft_find_smallest(int *stack_a, int size);
int		ft_find_n_smallest(int *stack_a, int size_a, int n);
int		ft_find_idx_number(int *stack, int smallest);
int		ft_find_highest(int *stack, int size);
void	ft_bring_highest_to_the_top(int **stack, int size_stack);
void	ft_print_stack(int *stack, int size);
void	ft_check_stack_is_sorted(int **stack,int size_stack);
int		ft_find_next_smallest(int to_insert, int *stack, int size);
int 	ft_find_next_smallest_alt(int to_insert, int *stack, int size);
int 	ft_find_next_smallest_alt_second(int to_insert, int *stack, int size);
int ft_find_next_smallest_alt_third(int to_insert, int *stack, int size);

void	ft_algorithm(int *stack_a, int *size_a, int *stack_b, int *size_b);
void	ft_select_insert(int **stack_a, int *size_a, int **stack_b, int *size_b);
void	ft_insertion(int to_insert, int **stack_b, int size_b);

void	*ft_memmove(void *dest, const void *src, size_t n);
char	**ft_split(const char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_atoi(const char *str);
char		*ft_strdup(const char *src);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putendl_fd(char *s, int fd);

#endif
