#include <stdio.h>

void ft_sa(int *stack_a);

int main(void)
{
    int i = 0;
    int stack_a[] = {5, 1, 3};
    int stack_b[3];
    printf("stack_a before: ");
    while (i < 3)
    {
        printf("%d ", stack_a[i]);
        i++;
    }

    printf("\n");
    ft_sa(stack_a);
    printf("stack_a after: ");
    i = 0;
    while (i < 3)
    {
        printf("%d ", stack_a[i]);
        i++;
    }

    printf("\n");
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

