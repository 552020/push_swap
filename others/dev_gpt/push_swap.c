void ft_push_swap(int *stack_a, int size)
{
    int *stack_b;
    int len_b;
    int i;
    int counter_rb = 0; // initialize counter for rb
    int counter_rrb = 0; // initialize counter for rrb

    stack_b = malloc(sizeof(int) * size);
    if (!stack_b)
        return ;
    len_b = 0;
    i = 0;
    while (i < size)
    {
        if (len_b >= 2 && stack_b[len_b - 1] < stack_b[len_b - 2])
        {
            ft_swap(&stack_b[len_b - 1], &stack_b[len_b - 2]);
            printf("sb\n");
        }
        if (len_b == 0 || stack_a[i] < stack_b[len_b - 1])
        {
            ft_push(&stack_b, &len_b, stack_a[i]);
            printf("pb\n");
        }
        else
        {
            while (len_b > 0 && stack_a[i] > stack_b[len_b - 1])
            {
                ft_push(&stack_a, &i, ft_pop(&stack_b, &len_b));
                printf("pa\n");
            }
            ft_push(&stack_b, &len_b, stack_a[i]);
            printf("pb\n");
        }
        i++;
    }
    while (len_b > 0)
    {
        if (len_b > 1 && stack_b[len_b - 1] < stack_b[len_b - 2])
        {
            ft_swap(&stack_b[len_b - 1], &stack_b[len_b - 2]);
            printf("sb\n");
        }
        ft_push(&stack_a, &i, ft_pop(&stack_b, &len_b));
        printf("pa\n");
        if (len_b > 0)
        {
            counter_rrb++; // increment counter for rrb
            printf("rrb\n");
        }
    }
    while (counter_rrb > 0)
    {
        printf("rrb\n");
        counter_rrb--;
    }
    while (len_b > 0)
    {
        ft_pop(&stack_b, &len_b);
    }
    free(stack_b);
}

