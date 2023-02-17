#include <stdio.h>
#include <stdlib.h>

void	ft_sa(int *stack_a);
void	ft_sb(int *stack_b);
void	ft_ra(int *stack_a, int size);
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
/*
typedef struct stack {
    int *data;
    int size;
} stack_t;
*/


//int main(void)
int main(int argc, char **argv)
{
	int smallest;
  //int stack_a[] = {5, 1, 3};
  //int stack_b[3];
	int *stack_a;
	int *stack_b;
	int size_a;
	int size_b;
	int i;
	char **str_arr;


	i = 0;
	size_a = 0;
	//printf("argc: %d\n", argc);
	while (i < argc)
	{
		//printf("argv[%d]: %s\n", i, argv[i]);
		i++;
	}
	// 0.1 Build an array out of the arguments passsed in in the command line
	// - case 1: $ ARG="4 67 86 89"; push_swap $ARG
	// - case 2; $ push_swap 4 67 86 89
	// - case 3: # push_swap // no arguments
	//printf("str_arr: \n");
	if (argc == 2)
	{
		str_arr = ft_split(argv[1], ' ');	
		i = 0;
		while (str_arr[i])
		{
			//printf("str_arr[%d]: %s\n", i, str_arr[i]);
			size_a++;
			i++;
		}
		size_b = size_a;
		//printf("size_a: %d\n", size_a);
		//printf("size_b: %d\n", size_b);
	}
	else if (argc > 2)
	{
		// case 2: 
		str_arr = &argv[1];
	}
	else
		return (0) ; 
	// 0.2 Build an array of ints from the array of string with atoi
	stack_a = malloc (sizeof(int) * size_a);
	stack_b = malloc (sizeof(int) * size_b);
	size_b = 0;
	i = 0;
	while (i < size_a)
	{
		stack_a[i] = ft_atoi(str_arr[i]);
		i++;
	}
	printf("stack_a begin: ");
	ft_print_stack(stack_a, size_a);
	while (1)
	{
		// 1. find the smallest number in the stack a
		smallest = ft_find_smallest(stack_a, size_a);
		//printf("smallest: %d\n", smallest);
		// 2. rotate till the stack_a[0] matches the numbers (ra)
		//printf("size_a main loop: %d\n", size_a);
		//printf("stack_a before ra: ");
		//ft_print_stack(stack_a, size_a);
		while (stack_a[0] != smallest)
		{
			//printf("ft_ra - while\n");
			ft_ra(stack_a, size_a);
		}
		/*
		printf("stack_a after ra: ");
		ft_print_stack(stack_a, size_a);
		printf("before pa\n");
		printf("stack a: ");
		ft_print_stack(stack_a, size_a);
		printf("stack b: ");
		ft_print_stack(stack_b, size_b);
		*/
		// 3. push the number to the stack_b (pa)
		ft_pa(stack_b, &size_b, stack_a, &size_a);
		/*
		printf("after pa\n");
		printf("stack a: ");
		ft_print_stack(stack_a, size_a);
		printf("stack b: ");
		ft_print_stack(stack_b, size_b);
		*/
		// 4. repeat till there are numbers in stack A;s
		if (size_a == 0)
			break ;
		//else 
			//printf("loop again\n");
			//printf("size_a: %d\n", size_a);
	}
	// 5. push the numbers back to to stack_b (pb)
	while (size_b > 0)
	{
		//printf("ft_pb while\n");
		ft_pb(stack_a, &size_a, stack_b, &size_b);
		//printf("size_b: %d\n", size_b);
	}
  printf("stack_a end: ");
	ft_print_stack(stack_a, size_a);
	free(stack_a);
	free(stack_b);
    return (0);
}

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

void	ft_ra(int *stack_a, int size)
{
	int tmp;
	//printf("ft_ra\n");
	tmp = stack_a[0];
	//printf("tmp: %d\n", tmp);
	//printf("stack_a before ft_memmove: ");
	//ft_print_stack(stack_a, 3);
	ft_memmove(&stack_a[0], &stack_a[1], (size -1) * sizeof(int));
	//printf("stack_a after ft_memmove: ");
	//ft_print_stack(stack_a, 3);
	stack_a[size - 1] = tmp;
	printf("ra\n");
}
/* (push a): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty*/
void ft_pa(int *stack_b, int *size_b, int *stack_a, int *size_a)
{
	int tmp;
	//printf("ft_pa - size_a before: %d\n", *size_a);
	if (*size_a == 0)
		return ;
	tmp = stack_a[0];
	ft_memmove(&stack_a[0], &stack_a[1], (*size_a - 1) * sizeof(int));
	//printf("ft_pa: stack_a after memmove: ");
	//ft_print_stack(stack_a, *size_a);
	ft_memmove(&stack_b[1], &stack_b[0], (*size_b) * sizeof(int));
	stack_b[0] = tmp;
	(*size_a)--;
	//printf("ft_pa - size_a after: %d\n", *size_a);
	(*size_b)++;
	printf("pa\n");
}


void ft_pb(int *stack_a, int *size_a, int *stack_b, int *size_b)
{
	int tmp;
	
	if (*size_b == 0)
		return ;
	tmp = stack_b[0];
	ft_memmove(&stack_b[0], &stack_b[1], (*size_b - 1) * sizeof(int));
	ft_memmove(&stack_a[1], &stack_a[0], (*size_a) * sizeof(int));
	stack_a[0] = tmp;
	(*size_b)--;
	(*size_a)++;
	printf("pb\n");
}

int	ft_find_smallest(int *stack_a, int size)
{
	int ret;
	int i;

	i = 0;	
	ret = stack_a[0];
	while (i < size)
	{
		if (stack_a[i] < ret)
			ret = stack_a[i];
		i++;
	}

	return (ret);
}

void	ft_print_stack(int *stack, int size)
{
	int i;

	i = 0;
    while (i < size)
    {
        printf("%d ", stack[i]);
        i++;
    }

    printf("\n");
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*ptr_d;
	const char	*ptr_s;
	char		*ptr_db;
	const char	*ptr_sb;

	ptr_d = dest;
	ptr_s = src;
	if (ptr_d < ptr_s)
	{
		while (n--)
			*ptr_d++ = *ptr_s++;
		return (dest);
	}
	else if (ptr_d > ptr_s)
	{
		ptr_db = dest + (n - 1);
		ptr_sb = src + (n - 1);
		while (n--)
			*ptr_db-- = *ptr_sb--;
		return (dest);
	}
	return (dest);
}
/* ft_split.c */
int	ft_free_ret(char **ret, size_t i);

static size_t	ft_count_word(const char *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	if (!s[0])
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			words++;
			while (s[i] && s[i] == c)
				i++;
		}
		else
			i++;
	}
	if (s[i - 1] != c)
		words++;
	return (words);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	size_t	len;
	size_t	i;

	i = 0;
	ret = (malloc(sizeof(char *) * (ft_count_word(s, c) + 1)));
	if (!ret)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			ret[i] = ft_substr(s - len, 0, len);
			if (!ret[i] && ft_free_ret(ret, i))
				return (0);
			i++;
		}
		else
			s++;
	}
	ret[i] = 0;
	return (ret);
}

int	ft_free_ret(char **ret, size_t i)
{
	while (i--)
		free(ret[i]);
	free(ret);
	return (1);
}
/* ft_substr is needed for ft_split */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	substr_len;
	int		s_len;

	s_len = ft_strlen((char *)s);
	if (start >= ft_strlen((char *)s))
	{
		substr = malloc (sizeof(char));
		if (!substr)
			return (NULL);
		*substr = '\0';
		return (substr);
	}
	if (len <= s_len - start)
		substr_len = len;
	else
		substr_len = s_len - start;
	substr = malloc (sizeof(char) * substr_len + 1);
	if (substr == NULL)
		return (0);
	ft_strlcpy(substr, &s[start], substr_len + 1);
	return (&substr[0]);
}

size_t	ft_strlen(const char *str)
{
	size_t	s;

	s = 0;
	while (str[s] != '\0')
		s++;
	return (s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen((char *)src));
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	tot;

	i = 0;
	sign = 1;
	tot = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' )
	{
		tot = tot * 10 + str[i] - '0';
		i++;
	}
	return (tot * sign);
}
