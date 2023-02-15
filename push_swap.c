#include <stdio.h>

void	ft_sa(int *stack_a);
void	ft_sb(int *stack_b);
void	ft_ra(int *stack_a, int size);
int		ft_find_smallest(int *stack_a, int size);
void	ft_print_stack(int *stack, int size);
void	*ft_memmove(void *dest, const void *src, size_t n);

int main(void)
{
	int smallest;

	// Take arguments from the command line.
    int stack_a[] = {5, 1, 3};
    int stack_b[3];
    printf("stack_a before: ");
	ft_print_stack(stack_a, 3);
	// We need now to sort the numbers in the stack A
	// - We can look for the smallest number, bring it to the top, push it to B
	// 1. find smallest number in the array
	smallest = ft_find_smallest(stack_a, 3);
	printf("smallest: %d\n", smallest);
	// 2. rotate till the stack_a[0] matches the numbers (ra)
	ft_ra(stack_a, 3);
    printf("stack_a after ra: ");
	ft_print_stack(stack_a, 3);
	// 3. push the number to the stack_b (pa)
	// 4. repeat till there are numbers
	// 5. push the numbers back to to stack_b (pb)
	// We would need just to imagine these operations, not to perform them: our output is not the sorted array but the operations we need to sort it. 
    ft_sa(stack_a);
    printf("stack_a after: ");
	ft_print_stack(stack_a, 3);
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
    printf("sa\n");
}

void	ft_ra(int *stack_a, int size)
{
	int tmp;
	printf("ft_ra\n");
	tmp = stack_a[0];
	printf("tmp: %d\n", tmp);
	printf("stack_a before ft_memmove: ");
	ft_print_stack(stack_a, 3);
	ft_memmove(&stack_a[0], &stack_a[1], (size -1) * sizeof(int));
	printf("stack_a after ft_memmove: ");
	ft_print_stack(stack_a, 3);
	stack_a[size - 1] = tmp;
	printf("ra\n");
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
