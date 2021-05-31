#include "push_swap.h"

int if_order(t_stack *stack)
{
    int i = 0;
    while (i < stack->size - 1)
    {
        if (stack->stackA[i] > stack->stackA[i + 1])
            return (0);
        i++;
    }
    free(stack->stackA);
    free(stack->stackB);
    return (1);
}

int check_doble(t_stack *stack)
{
    int *array;

    array = malloc(sizeof(int) * stack->size);
    ft_memcpy(array , stack->stackA, sizeof(int) * find_new_size(stack));
    ft_sort(stack->size, array);
    int i = 0;
    while (i < stack->size -1)
    {
        if (array[i] == array[i + 1])
        {
            free(array);
            free(stack->stackB);
            free(stack->stackA);
            write(1, "Error\n", 6);
            return (1);
        }
        i++;
    }
    free(array);
    return (0);
}
