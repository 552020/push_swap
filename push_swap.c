#include <stdio.h>

void ft_sa(int **stack_a);

int main(void)
{
	int i = 0;
	// Take arguments from the command line.
	// We need a stack A with some values in it. It could be an array of ints or a linked list
	int stack_a[] = {5, 1, 3};
	// We need an empty stack B, which should be something similar to A. 
	int stack_b[3];
	printf("stack_a before: ");
	while (i < 3)
	{
		printf("%d ", stack_a[i]);
		i++;
	}
	
	printf("\n");
	// We need now to sort the numbers in the stack A
	// - We can look for the smallest number, bring it to the top, push it to B
	ft_sa(&stack_a);
	printf("stack_a after: ");
	while (i < 3)
	{
		printf("%d ", stack_a[i]);
		i++;
	}
	
	printf("\n");
	return (0);
}

//void ft_sa(int *stack_a)
void ft_sa(int **stack_a)
{
	int tmp;

	
	printf("%d\n", tmp);
	(*stack_a)[0] = (*stack_a)[1];
	printf("%d\n", (*stack_a)[0]);
	*stack_a[1] = tmp;
	printf("%d\n", tmp);
	printf("sa\n");

}


