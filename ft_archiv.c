void ft_check_stack_is_sorted(int **stack, int size_stack)
{
	int i;

	i = 0;
	while (i < size_stack -2)
	{
		if(stack[i] > stack[i + 1])
		{
			printf("KO: stack[%d]: %d > stack[%d]: %d\n", i, *stack[i], i + 1,  *stack[i + 1]);
		}
		i++;
	}
	printf("OK: sorted!\n");
}


int ft_find_next_smallest_first(int to_insert, int *stack, int size)
{
	int i;
	int smallest;
	int next_smallest;
	int idx_smallest;
	int diff;

	i = 0;
	smallest = ft_find_smallest(stack, size);
	idx_smallest = ft_find_idx_number(stack, smallest);	
	diff = to_insert - smallest;
	next_smallest = stack[idx_smallest];
	while (i < size - 1)
	{
		if (stack[i] < to_insert && (to_insert - stack[i]) <= diff)
		{
			diff = to_insert - stack[i];
			next_smallest = stack[i];
		}
		i++;
	}
	return (next_smallest);
}

int ft_find_next_smallest_alt_second(int to_insert, int *stack, int size)
{
    int i;
    int next_smallest = INT_MAX;
    
    for (i = 0; i < size - 1; i++)
    {
        if (stack[i] > to_insert && stack[i] < next_smallest)
            next_smallest = stack[i];
    }
    
    return next_smallest;
}


int ft_find_next_smallest_alt_third(int to_insert, int *stack, int size)
{
    int left = 0;
    int right = size - 1;
    int mid;
    int smallest = ft_find_smallest(stack, size);

    if (to_insert < smallest) {
        return smallest;
    }

    while (left <= right) {
        mid = (left + right) / 2;
        if (stack[mid] == to_insert) {
            return stack[mid + 1];
        } else if (stack[mid] < to_insert) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // we have found the index of the smallest element greater than to_insert
    return stack[left];
}