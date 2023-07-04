/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:56:08 by slombard          #+#    #+#             */
/*   Updated: 2023/06/18 11:32:36 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include "./libft/libft.h"

struct	s_stack
{
	int	*stack;
	int	size;
};

typedef struct s_next{
	int	value;
	int	rotation;
}	t_next;

typedef struct s_next_score{
	int	value;
	int	rotation;
	int	score;
}	t_next_score;

typedef struct s_scores_simple{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
}	t_scores_simple;

typedef struct t_scores_combined{
	int	rr;
	int	rrr;
	int	ra_rrb;
	int	rb_rra;
}	t_scores_combined;

typedef struct s_stack	t_stack;

void				ft_pa(int *stack_b, int *size_b, int *stack_a, int *size_a);
void				ft_pb(int *stack_a, int *size_a, int *stack_b, int *size_b);
void				ft_sa(int *stack_a);
void				ft_sb(int *stack_b);
void				ft_ra(int *stack_a, int size_a);
void				ft_rra(int *stack_a, int size_a);
void				ft_rb(int *stack_b, int size_b);
void				ft_rrb(int *stack_b, int size_b);
void				ft_ss(int *stack_a, int *stack_b);
void				ft_rr(int *stack_a, int size_a, int *stack_b, int size_b);
void				ft_rrr(int *stack_a, int size_a, int *stack_b, int size_b);

int					ft_find_smallest(int *stack_a, int size);
int					ft_find_n_smallest(int *stack_a, int size_a, int n);
int					ft_find_idx_number(int *stack, int smallest);
int					ft_find_highest(int *stack, int size);
void				ft_bring_highest_to_the_top(int *stack, int size_stack);
int					ft_find_next_smallest(int to_insert, int *stack, int size);
void				ft_print_stack(int *stack, int size);
void				ft_print_stacks(t_stack *stack_a, t_stack *stack_b);
int					ft_check_input(char **argv);
int					ft_num_check(char *argv);
int					ft_issign(int c);
int					ft_isdigit(int c);
int					ft_check_zero(char *argv);
int					ft_sneak_duplicate(char **argv);
void				ft_write_error(void);
int					ft_num_str_cmp(const char *s1, const char *s2);

void				ft_selection(int *stack_a, int *size_a,
						int *stack_b, int *size_b);
void				ft_select_insert(int *stack_a, int *size_a,
						int *stack_b, int *size_b);
void				ft_insertion(int to_insert, int *stack_b, int *size_b);

char				**ft_build_str_arr(int argc, char **argv, t_stack *stack_a);
int					ft_build_stacks(t_stack *stack_a,
						t_stack *stack_b, char **str_arr);
void				ft_count_sort(t_stack *stack_a, t_stack *stack_b);
void				ft_small_sort(t_stack *stack_a);
void				ft_medium_sort(t_stack *stack_a, t_stack *stack_b);

t_next				ft_find_next(t_stack stack_a, t_stack stack_b);
t_next_score		ft_find_score(t_stack stack_a, t_stack stack_b,
						int to_be_scored);
t_scores_simple		ft_find_scores_simple(t_stack stack_a,
						t_stack stack_b, int to_be_scored);
int					ft_find_score_rb(t_stack stack_b, int to_be_scored);
t_scores_combined	ft_find_scores_combined(t_scores_simple tss);
t_next_score		ft_build_ret(t_scores_combined tsc, int to_be_scored);
long int			ft_atol(const char *str);

void				ft_push_next(t_stack *stack_a, t_stack *stack_b,
						t_next next);
void				ft_push_next_rr(t_stack *stack_a, t_stack *stack_b,
						t_next next, int next_smallest);
void				ft_push_next_rrr(t_stack *stack_a, t_stack *stack_b,
						t_next next, int next_smallest);
void				ft_push_next_ra_rrb(t_stack *stack_a, t_stack *stack_b,
						t_next next, int next_smallest);
void				ft_push_next_rb_rra(t_stack *stack_a, t_stack *stack_b,
						t_next next, int next_smallest);

void				*ft_memmove(void *dest, const void *src, size_t n);
char				**ft_split(const char *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
int					ft_atoi(const char *str);
char				*ft_strdup(const char *src);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);
long int			ft_atol(const char *str);

/* ft_printf */
int					ft_printf(const char *format, ...);
void				ft_parse_specifier(va_list *args, int *count, char c);

void				ft_parse_char(char c, int *count);
void				ft_parse_str(char *str, int *count);
void				ft_parse_int(int nbr, int *count);
void				ft_parse_uint(unsigned int nbr, int *count);
void				ft_parse_ptr(void *ptr, int *count);
void				ft_parse_hex(unsigned int hex, int *count, char c);

void				ft_putchar(char c, int *count);
void				ft_putstr(char *s, int *count);
void				ft_putnbr(int n, int *count);
void				ft_putunbr(unsigned int n, int *count);
void				ft_puthex(unsigned long n, int *count, char c);

#endif
