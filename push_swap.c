#include <stdio.h>

void	ft_sa(int *stack_a);
void	ft_sb(int *stack_b);
void	ft_ra(int *stack_a, int size);
int		ft_find_smallest(int *stack_a, int size);
void	ft_print_stack(int *stack, int size);
void	*ft_memmove(void *dest, const void *src, size_t n);
void ft_pb(int *stack_a, int *size_a, int *stack_b, int *size_b);
void ft_pa(int *stack_b, int *size_b, int *stack_a, int *size_a);
/*
typedef struct stack {
    int *data;
    int size;
} stack_t;
*/


int main(void)
{
	int smallest;
	// Take arguments from the command line.
  int stack_a[] = {5, 1, 3};
  int stack_b[3];
	int size_a = 3;
	int size_b = 0;
  printf("stack_a begin: ");
	ft_print_stack(stack_a, size_a);
	// We need now to sort the numbers in the stack A
	// - We can look for the smallest number, bring it to the top, push it to B
	// 1. find smallest number in the array
	while (1)
	{
		smallest = ft_find_smallest(stack_a, size_a);
		//printf("smallest: %d\n", smallest);
		// 2. rotate till the stack_a[0] matches the numbers (ra)
		//printf("size_a main loop: %d\n", size_a);
		printf("stack_a before ra: ");
		ft_print_stack(stack_a, size_a);
		while (stack_a[0] != smallest)
		{
			//printf("ft_ra - while\n");
			ft_ra(stack_a, size_a);
		}
		printf("stack_a after ra: ");
		ft_print_stack(stack_a, size_a);
		printf("before pa\n");
		printf("stack a: ");
		ft_print_stack(stack_a, size_a);
		printf("stack b: ");
		ft_print_stack(stack_b, size_b);
		// 3. push the number to the stack_b (pa)
		ft_pa(stack_b, &size_b, stack_a, &size_a);
		printf("after pa\n");
		printf("stack a: ");
		ft_print_stack(stack_a, size_a);
		printf("stack b: ");
		ft_print_stack(stack_b, size_b);
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
	}
  printf("stack_a end: ");
	ft_print_stack(stack_a, size_a);
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
	printf("ft_pa: stack_a after memmove: ");
	ft_print_stack(stack_a, *size_a);
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
